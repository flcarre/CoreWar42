/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:23:49 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/12 21:35:27 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_uitoa_base(unsigned int n, int base)
{
	size_t				i;
	size_t				n_size;
	static char			str[15];
	char				*strbase;

	i = 0;
	ft_bzero(str, 15);
	strbase = "0123456789abcdef0123456789ABCDEF";
	n_size = ft_nbrlen(n, base);
	while (i < n_size--)
	{
		str[n_size] = strbase[(n % base)];
		n /= base;
	}
	return (str);
}

char					*ft_itoa_base(int n, int base)
{
	size_t				i;
	size_t				n_size;
	static char			str[15];
	char				*strbase;
	unsigned int		abs;

	i = 0;
	ft_bzero(str, 15);
	strbase = "0123456789abcdef0123456789ABCDEF";
	n_size = ft_nbrlen(n, base);
	abs = n < 0 ? -n : n;
	if (n < 0)
	{
		str[i++] = '-';
		n_size++;
	}
	while (i < n_size--)
	{
		str[n_size] = strbase[(abs % base)];
		abs /= base;
	}
	return (str);
}

char					*ft_itoa(int n)
{
	size_t				i;
	size_t				n_size;
	static char			str[12];
	unsigned int		abs;

	i = 0;
	ft_bzero(str, 12);
	n_size = ft_nbrlen(n, 10);
	abs = n < 0 ? -n : n;
	if (n < 0)
		str[i++] = '-';
	while (i < n_size--)
	{
		str[n_size] = (abs % 10) + '0';
		abs /= 10;
	}
	return (str);
}
