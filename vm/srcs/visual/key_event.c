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
}

int			ft_key_event(t_vm *vm)
{
	int	ch;

	if ((ch = getch()) == 27)
		return (END_GAME);
	ft_edit_speed_cycle(vm, ch);
	if (ch == ' ')
	{
		while ((ch = getch()) != ' ')
		{
			if (ch == 27)
				return (END_GAME);
			vm->visu->info->coord.x = 1;
			vm->visu->info->coord.y = 20;
			ft_edit_speed_cycle(vm, ch);
			ft_print_first_panel(vm->visu->info, vm);
			ft_print_fourth_panel(vm->visu->info, "PAUSE");
			wrefresh(vm->visu->info->window);
		}
		ft_print_fourth_panel(vm->visu->info, "RUNNING");
	}
	return (0);
}
