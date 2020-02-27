/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_address.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:56:53 by lutsiara          #+#    #+#             */
/*   Updated: 2020/02/27 22:05:40 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int ft_read_address(t_vm *vm, int addr, size_t bytes)
{
	int res;

	res = 0;
	while (bytes)
	{
		res += vm->mem[addr] * ft_power(256, bytes - 1);
		addr = (addr + 1) % MEM_SIZE;
		bytes--;
	}
	return (res);
}