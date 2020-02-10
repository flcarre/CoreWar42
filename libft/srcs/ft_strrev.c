/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 22:59:12 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/11 22:22:49 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	int		i;
	int		y;
	char	c;

	i = 0;
	y = 0;
	while (str[y])
		y++;
	y--;
	while (i < y)
	{
		c = str[y];
		str[y] = str[i];
		str[i] = c;
		i++;
		y--;
	}
	return (str);
}
