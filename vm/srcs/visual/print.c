#include "vm.h"

void	ft_print_col_numbers_bis(t_visu *visu)
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

static void	ft_print_bytes_bis(t_visu *visu, t_vm *vm, int i, int *color_p)
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
	y = 2;
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
	y += 3;
	info->coord.x = x;
	while (x < info->dim.cols - 1)
		mvwprintw(info->window, y, x++, "-");
	info->coord.y = y + 3;
}

void	ft_print_arena_bis(t_visu *visu, t_vm *vm, int *color_p)
{
	int	i;
	int	size;

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
}
