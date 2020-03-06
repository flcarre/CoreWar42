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

int	ft_key_event(t_vm *vm)
{
	int	ch;

	if ((ch = getch()) == 27)
		return (END_GAME);
	if (ch == '-' && vm->visu->cps > 1)
		vm->visu->cps--;
	if (ch == '+' && vm->visu->cps < 900)
		vm->visu->cps++;
	if (ch == ' ')
	{
		while ((ch = getch()) != ' ')
		{
			if (ch == 27)
				return (END_GAME);
			vm->visu->info->coord.x = 1;
			vm->visu->info->coord.y = 20;
			if (ch == '-' && vm->visu->cps > 1)
				vm->visu->cps--;
			if (ch == '+' && vm->visu->cps < 900)
				vm->visu->cps++;
			ft_print_first_panel(vm->visu->info, vm);
			wrefresh(vm->visu->info->window);
		}
	}
	return (0);
}
