/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfrancis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 12:40:49 by kfrancis          #+#    #+#             */
/*   Updated: 2020/05/18 18:56:20 by kfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	appendline(char **str, char **line)
{
	int		len;
	char	*temp;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	if ((*str)[len] == '\n')
	{
		*line = ft_strsub(*str, 0, len);
		temp = ft_strdup(&((*str)[len + 1]));
		free(*str);
		*str = temp;
		if ((*str)[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

static int	output(char **str, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && str[fd] == NULL)
		return (0);
	else
		return (appendline(&str[fd], line));
}

int get_next_line(const int fd, char **line)
{
    int			ret;
	static char	*str[FD_SIZE];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (output(str, line, ret, fd));
}