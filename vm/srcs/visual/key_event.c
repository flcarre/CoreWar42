/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:18:59 by dcoloma           #+#    #+#             */
/*   Updated: 2020/03/06 16:19:00 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_edit_speed_cycle(t_vm *vm, int ch)
{

	if (ch == '-' && vm->visu->cps > 1)
		vm->visu->cps--;
	if (ch == '+' && vm->visu->cps < 900)
		vm->visu->cps++;
	if (ch == '+' || ch == '-')
	{
		ft_print_first_panel(vm->visu->info, vm);
		// wrefresh(vm->visu->info->window);
	}
	// ft_print_secnd_panel(vm->visu->info, vm);
}

static void	ft_resize_window(t_vm *vm, char *state)
{
	// vm->visu->info->coord.x = 1;
	// vm->visu->info->coord.y = 2;
	ft_init_arena(vm->visu, vm, vm->visu->color_p);
	// ft_init_panel(vm->visu, vm);
	ft_print_arena_bis(vm->visu, vm, vm->visu->color_p);
	ft_print_war_bis(vm->visu->info, 1, 2);
	ft_print_first_panel(vm->visu->info, vm);
	ft_print_secnd_panel(vm->visu->info, vm);
	ft_print_third_panel(vm->visu->info, vm);
	ft_print_fourth_panel(vm->visu->info, state);
	ft_create_border(vm->visu);
	wrefresh(vm->visu->info->window);
	wrefresh(vm->visu->arena->window);
	refresh();
	// vm->visu->info->coord.x = 1;
	// vm->visu->info->coord.y = 2;
}

int		ft_pause(t_vm *vm)
{
	int	ch;

	ft_print_fourth_panel(vm->visu->info, "PAUSE");
	wrefresh(vm->visu->info->window);
	// ft_print_secnd_panel(vm->visu->info, vm);
	while ((ch = getch()) != ' ')
	{
		if (ch == 27)
			return (END_GAME);
		ft_edit_speed_cycle(vm, ch);
		if (ch == KEY_RESIZE)
			ft_resize_window(vm, "PAUSE");
	}
	ft_print_fourth_panel(vm->visu->info, "RUNNING");
	return (0);
}

int			ft_key_event(t_vm *vm)
{
	int	ch;

	if ((ch = getch()) == 27)
		return (END_GAME);
	ft_edit_speed_cycle(vm, ch);
	if (ch == KEY_RESIZE)
		ft_resize_window(vm, "PAUSE");
	if (ch == ' ')
		return (ft_pause(vm));
	return (0);
}
