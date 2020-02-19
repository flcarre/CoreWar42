/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:28:48 by hasni             #+#    #+#             */
/*   Updated: 2020/02/19 16:22:14 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int skip_nonspace(char *str, int i)
{
	while (str[i] && !ft_isspace(str[i]) && str[i] != DIRECT_CHAR)
		i++;
	return (i);
}

int	skip_space(char *str, int i)
{
	while (str[i] && ft_isspace(str[i]))
		i++;
	return (i);
}
