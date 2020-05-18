/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfrancis <kfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 09:56:07 by kfrancis          #+#    #+#             */
/*   Updated: 2020/02/10 14:34:20 by kfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	while (c >= 65 && c <= 90)
	{
		c = c + 32;
	}
	return (c);
}
