/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:51:00 by anrzepec          #+#    #+#             */
/*   Updated: 2020/02/19 11:59:34 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int			ft_arg_check(int ac)
{
	if (ac == 1)
	{
		ft_print_helper();
		return (1);
	}
	return (0);
}

int			ft_players_loading(char **av, t_vm *vm)
{
	int i;
	int ret;
	int err;

	i = 0;
	while (++i < vm->nb_args)
	{
		if (av[i] && av[i][0] == '-')
		{
			if ((ret = parse_option(vm, av, &i)))
				return (ret);
		}
		else if ((err = parse_player(vm, av, i)))
			return (err);
	}
	return (vm->nb_players > 0 ? 0 : 1);
}

void		ft_position_loading(t_vm *vm)
{
	t_process	*tracer;
	int			div;
	int			i;

	i = vm->nb_players - 1;
	div = MEM_SIZE / vm->nb_players;
	tracer = vm->process;
	while (tracer)
	{
		tracer->pc = div * i;
		i--;
		tracer = tracer->next;
	}
}

int			main(int ac, char **av)
{
	int		err;
	t_vm	*vm;

	err = 0;
	if (ft_arg_check(ac))
		return (1);
	if (!(vm = ft_init_vm(ac)))
		return (ft_init_error(ALLOC_ERROR, vm));
	if ((err = ft_players_loading(av, vm)))
		return (ft_init_error(err, vm));
	if ((load_process_list(vm)) == ALLOC_ERROR)
		return (ALLOC_ERROR);
	ft_position_loading(vm);
	create_arena(vm);
	vm->last_live = &vm->player[vm->nb_players - 1];
	if (exec_machine(vm) == ALLOC_ERROR)
		return (ft_init_error(ALLOC_ERROR, vm));
	free_machine(vm);
	ft_printf("You have been playing Corewar, feel free to donate!\n");
	return (0);
}
