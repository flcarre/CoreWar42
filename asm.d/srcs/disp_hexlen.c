/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_hexlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:15:19 by hasni             #+#    #+#             */
/*   Updated: 2020/02/19 16:41:56 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void disp_hexlen(int fd, unsigned long size, int len)
{
	unsigned char *tmp;
	int i;

	i = len;
	if (!(tmp = (unsigned char *)ft_memalloc(i * sizeof(unsigned char))))
		return;
	while (size && i > 0)
	{
		tmp[--i] = size % 256;
		size /= 256;
	}
	write(fd, tmp, len);
	ft_memdel((void **)&tmp);
}
