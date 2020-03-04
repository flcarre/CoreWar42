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

	/* A REMPLACER par un tableau de curseur par player contenant les coord x,y */
	visu->cursor.x = 10;
	visu->cursor.y = 2;
	// move(1, 10);
	return (0);
}

int	ft_refresh_visu(t_vm *vm)
{
	t_visu	*visu;
	int		player;

	player = 0;
	visu = vm->visu;
	visu->info->coord.x = 1;
	visu->info->coord.y = 20;

	/* Utiliser les coord curseurs ici et à incrementer à chaque refresh */
	
	// getch();
	// (void)vm;
	ft_print_arena_bis(visu, vm, visu->color_p);
	ft_print_first_panel(visu->info, vm);
	ft_print_secnd_panel(visu->info, vm);
	ft_print_third_panel(visu->info, vm);

	mvwchgat(visu->arena->window, visu->cursor.y, visu->cursor.x, 2, A_STANDOUT, 1, NULL);
	if (visu->cursor.x < visu->arena->dim.cols - 1)
		visu->cursor.x += 3;
	else
	{
		visu->cursor.x = 10;
		visu->cursor.y++;
	}
	wrefresh(visu->arena->window);
	wrefresh(visu->info->window);
	return (0);
}
