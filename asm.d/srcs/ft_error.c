/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:26:07 by wahasni           #+#    #+#             */
/*   Updated: 2020/05/15 21:03:09 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*ft_error_str(char *str, char *ret)
{
	ft_printf("{red}%s{reset}\n", str);
	return (ret);
}

int		ft_error(char *str, int ret)
{
	ft_printf("{red}%s{reset}\n", str);
	return (ret);
}
