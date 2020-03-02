#include "vm.h"

void	ft_print_col_numbers(t_visu *visu)
{
	int	x;
	int	y;
	int	i;
	// int	j;

	x = 1;
	y = 1;
	i = 0;
	
	mvwprintw(visu->arena->window, y, x, "Col nb : ");
	x += 9;
	while (i < 64)
	{
		mvwprintw(visu->arena->window, y, x, "%02d", i);
		i++;
		x += 2;
		if (i < 64)
			mvwprintw(visu->arena->window, y, x++, " ");
	}
}

void	ft_print_bytes(t_visu *visu, t_vm *vm, int i, int *color_p)
{
	int color;
	int	x;
	int	y;

	x = visu->arena->coord.x;
	y = visu->arena->coord.y;

	color = vm->owner[i] % 8;
	wattron(visu->arena->window, COLOR_PAIR(color_p[color]));
	mvwprintw(visu->arena->window, y, x, "%02x", vm->mem[i]);
	wattroff(visu->arena->window, COLOR_PAIR(color_p[color]));
}

void	ft_print_war_bis(t_win *info)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	wattron(info->window, COLOR_PAIR(COLOR_P1));
	mvwprintw(info->window, y++, x, "\t\t       .----.-----.-----.-----.");
	mvwprintw(info->window, y++, x, "\t\t      /      \\     \\     \\     \\");
	mvwprintw(info->window, y++, x, "\t\t     |  \\/    |     |   __L_____L__");
	mvwprintw(info->window, y++, x, "\t\t     |   |    |     |  (           \\");
	mvwprintw(info->window, y++, x, "\t\t     |    \\___/    /    \\______/    |");
	mvwprintw(info->window, y++, x, "\t\t     |        \\___/\\___/\\___/       |");
	mvwprintw(info->window, y++, x, "\t\t      \\      \\     /               /");
	mvwprintw(info->window, y++, x, "\t\t       |                        __/");
	mvwprintw(info->window, y++, x, "\t\t        \\_                   __/");
	mvwprintw(info->window, y++, x, "\t\t          |        |         |");
	mvwprintw(info->window, y++, x, "\t\t          |                  |");
	mvwprintw(info->window, y++, x, "\t\t          |                  |");
	wattroff(info->window, COLOR_PAIR(COLOR_P1));
}
