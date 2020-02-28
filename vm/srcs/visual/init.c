#include "visual.h"

t_visu	*init_visu(void)
{
	t_visu	*visu;
	t_win	*arena;
	t_win	*info;

	visu = (t_visu *)malloc(sizeof(t_visu));
	if (visu == NULL)
		return (NULL);
	arena = (t_win *)malloc(sizeof(t_win));
	if (arena == NULL)
		return (NULL);
	info = (t_win *)malloc(sizeof(t_win));
	if (info == NULL)
		return (NULL);
	arena->dim.lines = LINES;
	arena->dim.cols = COLS * 2 / 3;
	arena->coord.x = 0;
	arena->coord.y = 0;

	info->dim.lines = arena->dim.lines;
	info->dim.cols = COLS / 3;
	info->coord.x = arena->dim.cols;
	info->coord.y = 0;

	visu->arena = arena;

	visu->info = info;
	return (visu);
}

void	init_colors(void)
{
	start_color();
	init_pair(COLOR_P1, COLOR_RED, COLOR_BLACK);
	init_pair(COLOR_P2, COLOR_CYAN, COLOR_BLACK);
	init_pair(COLOR_P3, COLOR_GREEN, COLOR_BLACK);
	init_pair(COLOR_P4, COLOR_YELLOW, COLOR_BLACK);
}

void	init_arena(t_visu *visu)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 1;
	y = 2;
	i = 0;
	// while (x < visu->arena->dim.cols - 1)
	while (i < 64)
	{
		j = 0;
		x = 1;
		while (j < 64)
		{
			mvwprintw(visu->arena->window, y, x, "00");
			x += 2;
			j++;
			if (j < 64)
				mvwprintw(visu->arena->window, y, x++, " ");
		}
		y++;
		i++;
	}
	wrefresh(visu->arena->window);
}

void	init_player(t_visu *visu, char *p1, char *p2, char *p3, char *p4)
{
	// attron(COLOR_PAIR(COLOR_P1));
	wattron(visu->arena->window, COLOR_PAIR(COLOR_P1));
	mvwprintw(visu->arena->window, 2, 1, p1);
	wattroff(visu->arena->window, COLOR_PAIR(COLOR_P1));attroff(COLOR_PAIR(COLOR_P1));
	wattron(visu->arena->window, COLOR_PAIR(COLOR_P2));
	mvwprintw(visu->arena->window, 4, 1, p2);
	wattroff(visu->arena->window, COLOR_PAIR(COLOR_P2));attroff(COLOR_PAIR(COLOR_P2));
	wattron(visu->arena->window, COLOR_PAIR(COLOR_P3));
	mvwprintw(visu->arena->window, 6, 1, p3);
	wattroff(visu->arena->window, COLOR_PAIR(COLOR_P3));attroff(COLOR_PAIR(COLOR_P3));
	wattron(visu->arena->window, COLOR_PAIR(COLOR_P4));
	mvwprintw(visu->arena->window, 8, 1, p4);
	wattroff(visu->arena->window, COLOR_PAIR(COLOR_P4));attroff(COLOR_PAIR(COLOR_P4));
	wrefresh(visu->arena->window);
}
