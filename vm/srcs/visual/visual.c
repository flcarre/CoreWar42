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
	// visu->color_p = color_p;
	vm->visu = visu;

	// move(1, 10);
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

	/* Utiliser les coord curseurs ici et à incrementer à chaque refresh */
	
	getch(); // DEBUG
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
	return (0);
}
