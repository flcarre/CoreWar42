#include "visual.h"

void	visual(void)
{
	t_visu	*visu;


	char	*p1="Player 1";
	char	*p2="Player 2";
	char	*p3="Player 3";
	char	*p4="Player 4";

	initscr();
	visu = init_visu();
	// curs_set(FALSE);
	if (has_colors() == FALSE)
	{
		endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	create_windows(visu);
	
	box(visu->arena->window, ACS_VLINE, ACS_HLINE);
	box(visu->info->window, ACS_VLINE, ACS_HLINE);

	mvwprintw(visu->arena->window, 0, 1, "Arena");
	wrefresh(visu->arena->window);
	// refresh();
	
	mvwprintw(visu->info->window, 0, 1, "Info");
	wrefresh(visu->info->window);
	init_arena(visu);
	init_colors();
	init_player(visu, p1, p2, p3, p4);

	// attron(COLOR_PAIR(1));
	// attron(COLOR_PAIR(2));
	// print_in_middle(stdscr, LINES / 2, 0, 0, "Voila !!! In color ...");
	// attroff(COLOR_PAIR(2));

	getch();
	free(visu->arena->window);
	free(visu->info->window);
	free(visu->arena);
	free(visu->info);
	free(visu);
	endwin();
}
