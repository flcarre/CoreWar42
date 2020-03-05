#include "vm.h"

int	ft_visual(t_vm *vm)
{
	t_visu	*visu;
	// int		color_p[8];

	initscr();
	visu = init_visu(vm);
	if (visu == NULL)
		return (VIS_ERROR);
	curs_set(FALSE);
	noecho();
	// cbreak();
	if (has_colors() == FALSE)
	{
		endwin();
		ft_printf("Your terminal does not support color\n");
		return (VIS_ERROR);
	}
	// ft_printf("\n=====DEBUG=====\n");
	create_windows(visu);
	init_colors(visu);
	init_arena(visu, vm, visu->color_p);
	init_panel(visu, vm);
	wrefresh(visu->arena->window);
	wrefresh(visu->info->window);
	// nodelay(visu->arena->window, 1);
	// nodelay(visu->info->window, 1);
	// visu->color_p = color_p;
	// vm->visu = visu;

	// move(1, 10);
	return (0);
}

int	ft_refresh_visu(t_vm *vm)
{
	t_visu		*visu;
	t_process	*champion;
	int			curs_x;
	int			curs_y;
	// int			ch;

	visu = vm->visu;
	visu->info->coord.x = 1;
	visu->info->coord.y = 20;

	/* Utiliser les coord curseurs ici et à incrementer à chaque refresh */
	
	// if ((ch = getch()) != 27)
	// 	if (ch == KEY_EXIT) // DEBUG
	// 		exit(0);
	// (void)vm;
	ft_print_arena_bis(visu, vm, visu->color_p);
	ft_print_first_panel(visu->info, vm);
	ft_print_secnd_panel(visu->info, vm);
	ft_print_third_panel(visu->info, vm);

	champion = vm->process;
	while (champion != NULL)
	{
		curs_x = (champion->pc % ft_sqrt(MEM_SIZE)) * 3 + 10;
		curs_y = (champion->pc / ft_sqrt(MEM_SIZE)) + 2;
		mvwchgat(visu->arena->window, curs_y, curs_x, 2, A_STANDOUT, champion->id + 1, NULL);
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

int	ft_key_event(t_vm *vm)
{
	int	ch;
	
	ch = getch();
	if (ch == '-' && vm->visu->cps > 1)
			vm->visu->cps--;
	if (ch == '+' && vm->visu->cps < 900)
		vm->visu->cps++;
	if (ch == ' ')
	{
		while ((ch = getch()) != ' ')
		{
			if (ch == 27)
				return (1);
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
