/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:22:07 by wahasni           #+#    #+#             */
/*   Updated: 2020/05/15 21:58:19 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_wstrlenp(wchar_t *s)
{
	int i;

	i = 0;
	while (*s != L'\0')
	{
		i += w_charlen(*s);
		s++;
	}
	return (i);
}

size_t	ft_strlenp(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
