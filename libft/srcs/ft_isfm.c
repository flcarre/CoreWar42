/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:58:26 by flcarre           #+#    #+#             */
/*   Updated: 2018/12/20 15:30:34 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isfm(char c)
{
	if (c == '#')
		return (16);
	if (c == '0')
		return (8);
	if (c == '-')
		return (4);
	if (c == ' ')
		return (2);
	if (c == '+')
		return (1);
	return (0);
}
