/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 16:55:07 by wahasni           #+#    #+#             */
/*   Updated: 2020/01/13 14:11:06 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	inside_int(long long n)
{
	return (n <= -2147483648 || n >= 2147483647);
}

int			ft_isnumber(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[0] == '-')
			i++;
		if (!ft_isdigit(s[i]))
			break ;
		i++;
	}
	if (i == ft_strlen(s))
		return (inside_int((long long)ft_atoll(s)));
	else
		return (1);
}
