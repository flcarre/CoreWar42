/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_panel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:26:55 by dcoloma           #+#    #+#             */
/*   Updated: 2020/03/06 15:26:56 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_print_war_bis(t_win *info, int x, int y)
{
	x += 12;
	wattron(info->window, COLOR_PAIR(COLOR_P1));
	mvwprintw(info->window, y++, x, "  .----.-----.-----.-----.");
	mvwprintw(info->window, y++, x, " /      \\     \\     \\     \\");
	mvwprintw(info->window, y++, x, "|  \\/    |     |   __L_____L__");
	mvwprintw(info->window, y++, x, "|   |    |     |  (           \\");
	mvwprintw(info->window, y++, x, "|    \\___/    /    \\______/    |");
	mvwprintw(info->window, y++, x, "|        \\___/\\___/\\___/       |");
	mvwprintw(info->window, y++, x, " \\      \\     /               /");
	mvwprintw(info->window, y++, x, "  |                        __/");
	mvwprintw(info->window, y++, x, "   \\_                   __/");
	mvwprintw(info->window, y++, x, "     |        |         |");
	mvwprintw(info->window, y++, x, "     |                  |");
	mvwprintw(info->window, y++, x, "     |                  |");
	wattroff(info->window, COLOR_PAIR(COLOR_P1));
	y += 3;
	x -= 12;
	mvwprintw(info->window, y, x,
		"----------------------------------------------------------");
}

void	ft_print_first_panel(t_win *info, t_vm *vm)
{
	int	x;
	int	y;
	int	i;

	x = info->coord.x + 8;
	y = info->coord.y + 18;
	i = ft_get_player_color(vm, vm->last_live->id);
	mvwprintw(info->window, y++, x, "current cycle\t: %6d", vm->cycles);
	mvwprintw(info->window, y++, x, "Cycles/second\t: %6d", vm->visu->cps);
	mvwprintw(info->window, y++, x, "cycles to die\t: %6d", vm->cycles_to_die);
	mvwprintw(info->window, y, x, "last alive\t: ");
	wattron(info->window, COLOR_PAIR(vm->visu->color_p[i + 1]) | A_BOLD);
	mvwprintw(info->window, y, x + 18, "(%d)%-20.20s",
		vm->last_live->id, vm->last_live->name);
	wattroff(info->window, COLOR_PAIR(vm->visu->color_p[i + 1]) | A_BOLD);
	y += 3;
	x = info->coord.x;
	mvwprintw(info->window, y, x,
		"----------------------------------------------------------");
}

void	ft_print_secnd_panel(t_win *info, t_vm *vm)
{
	int	x;
	int	y;

	x = info->coord.x + 8;
	y = info->coord.y  + 27;
	mvwprintw(info->window, y++, x, "%-25s %d", "Number of players:",
		vm->nb_players);
	mvwprintw(info->window, y++, x, "%-25s %d", "Number of processes:",
		vm->nb_proc);
	mvwprintw(info->window, y++, x, "%-25s %d", "Last check:", vm->last_verif);
	wattron(info->window, A_STANDOUT);
	mvwprintw(info->window, y, x, "%-25s %d", "Lives since check:",
		vm->lives_since_check);
	wattroff(info->window, A_STANDOUT);
	y += 3;
	x = info->coord.x;
	mvwprintw(info->window, y, x,
		"----------------------------------------------------------");
}

void	ft_print_third_panel(t_win *info, t_vm *vm)
{
	int		x;
	int		y;
	int		player;
	int		i;
	t_visu	*visu;

	x = info->coord.x + 8;
	y = info->coord.y + 35;
	player = 0;
	visu = vm->visu;
	while (player < vm->nb_players)
	{
		if (vm->live_tab[player] != -1 && player < 4)
		{
			i = ft_get_player_color(vm, vm->live_tab[player]);
			wattron(info->window, COLOR_PAIR(visu->color_p[i + 1]));
			mvwprintw(info->window, y++, x, "(%d)%-.20s has called Live!",
				vm->player[i].id, vm->player[i].name);
			wattroff(info->window, COLOR_PAIR(visu->color_p[i + 1]));
		}
		player++;
	}
}

void	ft_print_fourth_panel(t_win *info, char *state)
{
	int		x;
	int		y;

	x = info->coord.x;
	y = info->coord.y + 58;
	mvwprintw(info->window, y, x,
		"----------------------------------------------------------");
	y = 63;
	x = 23;
	wattron(info->window, A_BOLD);
	mvwprintw(info->window, y, x, "**%s**\t", state);
	mvwprintw(info->window, y + 1, x, "COLS = %d\tLINES = %d", COLS, LINES);
	wattroff(info->window, A_BOLD);
}
