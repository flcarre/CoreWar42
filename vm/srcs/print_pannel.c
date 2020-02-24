/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pannel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:57:53 by lutsiara          #+#    #+#             */
/*   Updated: 2020/02/24 18:41:13 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_pannel_line(char *line)
{
	char pannel[60];

	ft_bzero(pannel, 60);
	ft_printf(ft_strcat(ft_strcpy(pannel, "          "), line));
}

static void	ft_print_war(int line)
{
	if (line == 2)
		ft_printf(
			"                   />");
	else if (line == 3)
		ft_printf(
			"      ()          //---------------------------(");
	else if (line == 4)
		ft_printf(
			"     (*)OXOXOXOXO(*>        --COREWAR--         %{RED}\\%{}");
	else if (line == 5)
		ft_printf(
			"      ()          \\\\-----------%{RED}------------------)%{}");
	else if (line == 6)
		ft_printf(
			"                   \\>                          %{RED}  \"%{}");
	else if (line == 7)
		ft_printf(
			"                                                 %{RED}'%{}");
}

void ft_print_pannel_extend_extend(t_vm *vm, int line)
{
	if (line == 24)
	{
		ft_printf("        %-25s %{YELLOW}%d%{}", "  Lives since check:",
				vm->lives_since_check);
	}
	if (line == 18)
		ft_printf("        %-25s %d", "  Number of players:", vm->nb_players);
	if (line == 20)
		ft_printf("        %-25s %d", "  Number of processes:", vm->nb_proc);
	if (line == 22)
		ft_printf("        %-25s %d", "  Last check: ", vm->last_verif);
}

void ft_print_pannel_extend(t_vm *vm, int line, int *players)
{
	int i;

	if (line == 9 || line == 15 || line == 27 || line == 32)
	{
		ft_printf("---------------------------------");
		ft_printf("--------------------------------");
	}
	else if (line == 28 + (*players) && *players < 4)
	{
		if (vm->live_tab[*players] != -1)
		{
			i = ft_get_player_color(vm, vm->live_tab[*players]);
			ft_printf("          %s (%d) has called Live!%{}",
					vm->player[i].name, vm->player[i].id);
		}
		(*players)++;
	}
	ft_print_pannel_extend_extend(vm, line);
}

void print_pannel(t_vm *vm, int line, int *players)
{
	ft_printf("%{}     |");
	if (line < 8)
		ft_print_war(line);
	else if (line == 11)
	{
		ft_pannel_line("current cycle : ");
		ft_printf("%d", vm->cycles);
	}
	else if (line == 12)
	{
		ft_pannel_line("last alive : ");
		ft_printf("%s (%d)", vm->last_live->name, vm->last_live->id);
	}
	else if (line == 13)
	{
		ft_pannel_line("cycles to die : ");
		ft_printf("%d", vm->cycles_to_die);
	}
	ft_print_pannel_extend(vm, line, players);
	ft_printf("\n");
}
