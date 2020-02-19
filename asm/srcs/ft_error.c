/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:26:07 by hasni             #+#    #+#             */
/*   Updated: 2020/02/19 11:09:09 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char *ft_error_str(char *str, char *ret)
{
	ft_printf("%{RED}%s%{}\n", str);
	return (ret);
}

int ft_error(char *str, int ret)
{
	ft_printf("%{RED}%s%{}\n", str);
	return (ret);
}
