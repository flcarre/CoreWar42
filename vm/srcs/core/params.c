/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:00:42 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/22 18:07:25 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	ft_get_param(t_vm *vm, t_process *proc, int pc, int code)
{
	int dir_size;

	dir_size = (g_op_tab[proc->current_op - 1].dir_size ? 2 : 4);
	if (code == REG_CODE)
	{
		if (ft_is_valid_reg(ft_read_address(vm, pc, 1)))
			return (ft_read_address(vm, pc, 1));
		else
			return (-1);
	}
	else if (code == DIR_CODE)
		return (ft_read_address(vm, pc, dir_size));
	else if (code == IND_CODE)
	{
		if (g_op_tab[proc->current_op - 1].restr)
			return (ft_modulo_mem_size(
				proc->pc + ft_idx_mod(ft_read_address(vm, pc, 2))));
		else
			return ((proc->pc + ft_read_address(vm, pc, 2)) % MEM_SIZE);
	}
	return (0);
}

static int	ft_param_size(int code, int dir_size)
{
	if (code == REG_CODE)
		return (1);
	else if (code == DIR_CODE)
		return (dir_size);
	else if (code == IND_CODE)
		return (2);
	return (0);
}

t_param		ft_set_params(t_vm *vm, t_process *proc, int pc, int *offset)
{
	int			i;
	char		ocp;
	t_param		params;
	int			dir_size;

	i = 0;
	ocp = vm->mem[(pc + 1) % MEM_SIZE];
	pc = (pc + 2) % MEM_SIZE;
	*offset = 2;
	params.valid = 1;
	if (!ft_check_ocp(proc, ocp))
		params.valid = 0;
	dir_size = (g_op_tab[proc->current_op - 1].dir_size ? 2 : 4);
	while (i < 3)
	{
		params.c[i] = ft_get_code(ocp >> (6 - (2 * i)));
		if ((params.n[i] = ft_get_param(vm, proc, pc, params.c[i])) == -1)
			params.valid = 0;
		pc = (pc + ft_param_size(params.c[i], dir_size)) % MEM_SIZE;
		*offset = *offset + ft_param_size(params.c[i], dir_size);
		i++;
	}
	return (params);
}
