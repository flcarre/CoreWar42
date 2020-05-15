/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:41:26 by wahasni           #+#    #+#             */
/*   Updated: 2020/05/15 21:59:52 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_isdigitp(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

intmax_t	ft_atoip(char *s)
{
	intmax_t	res;
	int			i;

	i = 0;
	res = 0;
	while (s[i] && ft_isdigitp(s[i]))
	{
		res += s[i] - 48;
		if (ft_isdigitp(s[i + 1]))
			res *= 10;
		i++;
	}
	return (res);
}
