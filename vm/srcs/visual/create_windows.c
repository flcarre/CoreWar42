#include "visual.h"

void		create_windows(t_visu *visu)
{
	t_win	*arena;
	t_win	*info;

	arena = visu->arena;
	info = visu->info;
	arena->window = newwin(arena->dim.lines, arena->dim.cols, arena->coord.y, arena->coord.x);
	info->window = newwin(info->dim.lines, info->dim.cols, info->coord.y, info->coord.x);
	refresh();
}