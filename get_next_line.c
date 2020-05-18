/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfrancis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 12:40:49 by kfrancis          #+#    #+#             */
/*   Updated: 2020/05/18 20:34:06 by kfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	appendline(char **str, char **line)
{
	int		len;
	char	*temp;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++; //read till end of string or new line
	if ((*str)[len] == '\n')
	{
		*line = ft_strsub(*str, 0, len); // set *line to the read string until len bytes
		temp = ft_strdup(&((*str)[len + 1])); // set temp to whole of str including the newiline
		free(*str); //free data within str.
		*str = temp; //now set str to temps data
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
		return (-1); // return if error found
	else if (ret == 0 && str[fd] == NULL)
		return (0); // return if reaches end of file descriptor
	else
		return (appendline(&str[fd], line)); // run appendline function if line is read
}

int get_next_line(const int fd, char **line)
{
    int			ret;
	static char	*str[FD_SIZE];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;

	if (fd < 0 || line == NULL)
		return (-1); // checks to see if file descriptor is empty or non existant.
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0) // sets ret value to 9 but reads buffer size of 8 (size of BUFF_SIZE)
	{
		buffer[ret] = '\0'; // sets last character in string to end of line character
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buffer); // duplicates buffer info into str[fd]
		else
		{
			temp = ft_strjoin(str[fd], buffer); // while str[fd] is not empty adds buffer at end of whatever is in str[fd]
			free(str[fd]); // frees any data str[fd] was holding
			str[fd] = temp; // sets str[fd] to new and all the data within str[fd]
		}
		if (ft_strchr(str[fd], '\n'))
			break ; // if find new line is found exit loop.
	}
	return (output(str, line, ret, fd)); // run output function
}