#include "vm.h"

t_visu	*init_visu(t_vm *vm)
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
	(void)vm;
	return (visu);
}

void	init_colors(int *color_p)
{
	start_color();
	init_pair(COLOR_DEF, COLOR_WHITE, COLOR_BLACK);
	init_pair(COLOR_P1, COLOR_RED, COLOR_BLACK);
	init_pair(COLOR_P2, COLOR_GREEN, COLOR_BLACK);
	init_pair(COLOR_P3, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(COLOR_P4, COLOR_BLUE, COLOR_BLACK);
	init_pair(COLOR_P5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(COLOR_P6, COLOR_CYAN, COLOR_BLACK);
	init_pair(COLOR_P7, COLOR_BLACK, COLOR_WHITE);
	color_p[0] = COLOR_DEF;
	color_p[1] = COLOR_P1;
	color_p[2] = COLOR_P2;
	color_p[3] = COLOR_P3;
	color_p[4] = COLOR_P4;
	color_p[5] = COLOR_P5;
	color_p[6] = COLOR_P6;
	color_p[7] = COLOR_P7;
}

void	init_arena(t_visu *visu, t_vm *vm, int *color_p)
{
	int	i;
	int	size;

	ft_print_col_numbers_bis(visu);
	i = 0;
	visu->arena->coord.x = 1;
	visu->arena->coord.y = 1;
	size = ft_sqrt(MEM_SIZE);
	while (i < MEM_SIZE)
	{
		if (i % size == 0)
		{
			visu->arena->coord.y++;
			visu->arena->coord.x = 1;
			mvwprintw(visu->arena->window, visu->arena->coord.y,
				visu->arena->coord.x, "0x%04x : ", i);
			visu->arena->coord.x = 10;
		}
		ft_print_bytes_bis(visu, vm, i, color_p);
		i++;
		visu->arena->coord.x += 3;
	}
	// wrefresh(visu->arena->window);
}

void	init_player(t_visu *visu, char *p1, char *p2, char *p3, char *p4)
{
	wattron(visu->arena->window, COLOR_PAIR(COLOR_P1));
	mvwprintw(visu->arena->window, 2, 1, p1);
	wattroff(visu->arena->window, COLOR_PAIR(COLOR_P1));
	wattron(visu->arena->window, COLOR_PAIR(COLOR_P2));
	mvwprintw(visu->arena->window, 4, 1, p2);
	wattroff(visu->arena->window, COLOR_PAIR(COLOR_P2));
	wattron(visu->arena->window, COLOR_PAIR(COLOR_P3));
	mvwprintw(visu->arena->window, 6, 1, p3);
	wattroff(visu->arena->window, COLOR_PAIR(COLOR_P3));
	wattron(visu->arena->window, COLOR_PAIR(COLOR_P4));
	mvwprintw(visu->arena->window, 8, 1, p4);
	wattroff(visu->arena->window, COLOR_PAIR(COLOR_P4));
	// wrefresh(visu->arena->window);
}

void	init_panel(t_visu *visu, t_vm *vm)
{
	
	(void)vm;
	ft_print_war_bis(visu->info);
	ft_print_first_panel(visu->info, vm);
	ft_print_secnd_panel(visu->info, vm);
	// ft_print_third_panel(visu->info, vm);
	wrefresh(visu->info->window);
}
