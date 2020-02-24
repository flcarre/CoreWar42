/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:22:13 by anrzepec          #+#    #+#             */
/*   Updated: 2020/02/24 18:41:13 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdlib.h>

void		ft_free_machine(t_vm *vm)
{
	t_process *tracer;
	t_process *tmp;

	tracer = vm->process;
	while (tracer)
	{
		tmp = tracer;
		tracer = tracer->next;
		free(tmp);
	}
	free(vm);
}

static void	ft_print_helper_war(void)
{
	ft_printf("\n");
	ft_printf("\t\t  .----.-----.-----.-----.\n");
	ft_printf("\t\t /      \\     \\     \\     \\\n");
	ft_printf("\t\t|  \\/    |     |   __L_____L__\n");
	ft_printf("\t\t|   |    |     |  (           \\\n");
	ft_printf("\t\t|    \\___/    /    \\______/    |\n");
	ft_printf("\t\t|        \\___/\\___/\\___/       |\n");
	ft_printf("\t\t \\      \\     /               /\n");
	ft_printf("\t\t  |                        __/\n");
	ft_printf("\t\t   \\_                   __/\n");
	ft_printf("\t\t     |        |         |\n");
	ft_printf("\t\t     |                  |\n");
	ft_printf("\t\t     |                  |\n");
}

void		ft_print_helper(void)
{
	ft_print_helper_war();
	ft_printf("> ./corewar [-v] cycle_refresh [[-dump] nbr_cycles] ");
	ft_printf("[[-n number]");
	ft_printf(" champion1.cor] ...\n\n%{RED}-->     FLAGS%{}\n\n-v  ");
	ft_printf("    ");
	ft_printf("Visualization.\n        Example: ./corewar -v 500 champ1.cor ");
	ft_printf("champ2.cor\n\n-n      Player number selection.\n        ");
	ft_printf("Example: > ./corewar -n 4 champ1.cor -n 2 champ2.cor\n        ");
	ft_printf("Corewar will auto-assign where no selection is made.\n\n");
	ft_printf("-dump  ");
	ft_printf(" Dump memory.\n        Example: > ./corewar -dump 27 ");
	ft_printf("champ1.cor ");
	ft_printf("champ2.cor\n        Here, Corewar will dump memory after 27");
	ft_printf(" cycles.\n        Corewar can only accept 1 -dump argument.\n");
}

static void	ft_init_error_extend(int error)
{
	if (error == SIZE_ERROR)
		ft_printf("Invalid Champion: Exceeds Authorized Size.\n");
	if (error == ALLOC_ERROR)
	{
		ft_printf("Malloc() fail. (Please report this incident to the ");
		ft_printf("dev team)\n");
	}
	if (error == VIS_ERROR)
		ft_printf("Invalid Value For Visualization Refresh Rate.\n");
	ft_printf("\n%{}");
	if (error != ALLOC_ERROR)
		ft_print_helper();
}

int			ft_init_error(int error, t_vm *vm)
{
	ft_free_machine(vm);
	ft_printf("%{RED}\n -> ");
	if (error == OPTION_ERROR)
		ft_printf("Invalid option(s).\n");
	if (error == PLAYER_NUMBER_ERROR)
		ft_printf("Invalid champion number.\n");
	if (error == DUMP_ERROR)
		ft_printf("Invalid Memory Dump Value.\n");
	if (error == FILE_ERROR)
		ft_printf("Invalid Path to Champion.\n");
	if (error == PLAYER_OVERLOAD)
		ft_printf("Too Many Champions.\n");
	if (error == NAME_ERROR)
		ft_printf("Invalid Champion Name.\n");
	if (error == COMMENT_ERROR)
		ft_printf("Invalid Champion Comment.\n");
	if (error == EXEC_ERROR)
		ft_printf("Invalid Champion Executable.\n");
	if (error == MAGIC_ERROR)
		ft_printf("Invalid Champion Magic Number.\n");
	ft_init_error_extend(error);
	return (1);
}
