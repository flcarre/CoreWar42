/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeofint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:14:37 by wahasni           #+#    #+#             */
/*   Updated: 2020/01/10 18:00:19 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sizeofint(int n)
{
	int				size;
	unsigned int	nb;

	nb = ft_abs(n);
	size = 0;
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}
