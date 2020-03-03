#include "vm.h"

int	ft_visual(t_vm *vm)
{
	t_visu	*visu;
	int		color_p[8];

	initscr();
	visu = init_visu(vm);
	if (visu == NULL)
		return (VIS_ERROR);
	// curs_set(FALSE);
	if (has_colors() == FALSE)
	{
		endwin();
		ft_printf("Your terminal does not support color\n");
		return (VIS_ERROR);
	}
	
	ft_printf("\n=====DEBUG=====\n");
	create_windows(visu);
	
	box(visu->arena->window, ACS_VLINE, ACS_HLINE);
	box(visu->info->window, ACS_VLINE, ACS_HLINE);

	mvwprintw(visu->arena->window, 0, 1, "Arena");
	// refresh();
	
	mvwprintw(visu->info->window, 0, 1, "Info");
	
	init_colors(color_p);
	init_arena(visu, vm, color_p);
	init_panel(visu, vm);
	wrefresh(visu->arena->window);
	wrefresh(visu->info->window);


	if (getch() == KEY_ENTER)
	{
		free(visu->arena->window);
		free(visu->info->window);
		free(visu->arena);
		free(visu->info);
		free(visu);
		// exit(0);
		endwin();
	}
	return (0);
}
// int	ft_refresh_visu(t_vm *vm, t_visu *visu)
// {

// }
