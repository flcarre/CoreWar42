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
	wrefresh(visu->arena->window);
	// refresh();
	
	mvwprintw(visu->info->window, 0, 1, "Info");
	wrefresh(visu->info->window);
	init_colors(color_p);
	init_arena(visu, vm, color_p);
	init_panel(visu, vm);
	// init_player(visu, p1, p2, p3, p4);

	// attron(COLOR_PAIR(1));
	// attron(COLOR_PAIR(2));
	// print_in_middle(stdscr, LINES / 2, 0, 0, "Voila !!! In color ...");
	// attroff(COLOR_PAIR(2));

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
