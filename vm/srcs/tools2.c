/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:56:53 by lutsiara          #+#    #+#             */
/*   Updated: 2020/02/24 18:41:13 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int ft_is_valid_op(int op_code)
{
	if (op_code <= 0 || op_code > 16)
		return (0);
	else
		return (1);
}

int long_rel_address(t_process *proc, int add1, int add2)
{
	return (ft_modulo_mem_size(proc->pc + add1 + add2));
}

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

int ft_read_octet(unsigned char *mem, size_t size)
{
	size_t bytes;
	int res;

	bytes = 0;
	res = 0;
	while (bytes < size)
	{
		res += mem[bytes] * ft_power(256, (4 - (bytes + 1)));
		bytes++;
	}
	return (res);
}

void ft_write_to_address(t_vm *vm, t_process *proc, int addr, int to_write)
{
	int bytes;
	int chunk;
	unsigned to_write_uns;

	bytes = 0;
	to_write_uns = (unsigned int)to_write;
	while (bytes < 4)
	{
		chunk = ft_power(256, (4 - (bytes + 1)));
		vm->mem[(addr + bytes) % MEM_SIZE] = to_write_uns / chunk;
		vm->owner[(addr + bytes) % MEM_SIZE] = proc->master;
		to_write_uns = to_write_uns % chunk;
		bytes++;
	}
}
