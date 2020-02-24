/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:55:24 by lutsiara          #+#    #+#             */
/*   Updated: 2020/02/24 18:41:13 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int ft_modulo_mem_size(int addr)
{
	if (addr >= 0)
		return (addr % MEM_SIZE);
	else
		return (MEM_SIZE + (addr % MEM_SIZE));
}

int ft_idx_mod(int addr)
{
	short new_addr;

	new_addr = (short)addr;
	return (new_addr % IDX_MOD);
}

int is_valid_reg(int reg)
{
	if (reg > 0 && reg < 17)
		return (1);
	return (0);
}

void init_registers(t_process *process)
{
	int i;

	i = 2;
	process->reg[0] = 0;
	process->reg[1] = -process->master;
	while (i < 17)
	{
		process->reg[i] = 0;
		i++;
	}
}

void ft_copy_registers(t_process *new, t_process *proc)
{
	int i;

	i = 1;
	new->reg[0] = 0;
	while (i < 17)
	{
		new->reg[i] = proc->reg[i];
		i++;
	}
}
