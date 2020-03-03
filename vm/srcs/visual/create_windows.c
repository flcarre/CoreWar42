#include "vm.h"

void		create_windows(t_visu *visu)
{
	t_win	*arena;
	t_win	*info;

	arena = visu->arena;
	info = visu->info;
	arena->window = newwin(arena->dim.lines, arena->dim.cols, arena->coord.y, arena->coord.x);
	info->window = newwin(info->dim.lines, info->dim.cols, info->coord.y, info->coord.x);
	box(visu->arena->window, ACS_VLINE, ACS_HLINE);
	box(visu->info->window, ACS_VLINE, ACS_HLINE);
	mvwprintw(visu->arena->window, 0, 1, "Arena");
	mvwprintw(visu->info->window, 0, 1, "Info");
	refresh();
	// visu->arena->coord.x = 1;
	// visu->arena->coord.y = 10;
}