/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:26:59 by dcoloma           #+#    #+#             */
/*   Updated: 2020/03/06 15:27:01 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	ft_visual(t_vm *vm)
{
	t_visu	*visu;

	initscr();
	timeout(0);
	visu = init_visu(vm);
	if (visu == NULL)
	{
		ft_exit_visu(vm->visu);
		return (ALLOC_ERROR);
	}
	curs_set(FALSE);
	noecho();
	if (has_colors() == FALSE)
	{
		ft_exit_visu(vm->visu);
		ft_printf("Your terminal does not support color\n");
		return (VIS_ERROR);
	}
	create_windows(visu);
	init_colors(visu);
	init_arena(visu, vm, visu->color_p);
	init_panel(visu, vm);
	wrefresh(visu->arena->window);
	wrefresh(visu->info->window);
	return (0);
}

int	ft_refresh_visu(t_vm *vm)
{
	t_visu		*visu;
	t_process	*champion;
	int			curs_x;
	int			curs_y;

	visu = vm->visu;
	visu->info->coord.x = 1;
	visu->info->coord.y = 20;
	ft_print_arena_bis(visu, vm, visu->color_p);
	ft_print_first_panel(visu->info, vm);
	ft_print_secnd_panel(visu->info, vm);
	ft_print_third_panel(visu->info, vm);
	champion = vm->process;
	while (champion != NULL)
	{
		curs_x = (champion->pc % ft_sqrt(MEM_SIZE)) * 3 + 10;
		curs_y = (champion->pc / ft_sqrt(MEM_SIZE)) + 2;
		mvwchgat(visu->arena->window, curs_y, curs_x,
			2, A_STANDOUT, champion->id + 1, NULL);
		champion = champion->next;
	}
	wrefresh(visu->arena->window);
	wrefresh(visu->info->window);
	usleep(MAX_SLEEP_TIME / visu->cps);
	return (0);
}

int	ft_exit_visu(t_visu *visu)
{
	endwin();
	if (visu != NULL)
	{
		if (visu->arena != NULL)
		{
			if (visu->arena->window != NULL)
				free(visu->arena->window);
			free(visu->arena);
		}
		if (visu->info != NULL)
		{
			if (visu->info->window != NULL)
				free(visu->info->window);
			free(visu->info);
		}
		free(visu);
	}
	return (0);
}
