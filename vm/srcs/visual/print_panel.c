#include "vm.h"

void	ft_print_first_panel(t_win *info, t_vm *vm)
{
	int	x;
	int	y;

	x = info->coord.x + 8;
	y = info->coord.y;
	mvwprintw(info->window, y++, x, "current cycle : %d", vm->cycles);
	mvwprintw(info->window, y++, x, "last alive : %s (%d)", vm->last_live->name, vm->last_live->id);
	mvwprintw(info->window, y, x, "cycles to die : %d", vm->cycles_to_die);
	y += 3;
	x = info->coord.x;
	while (x < info->dim.cols - 1)
		mvwprintw(info->window, y, x++, "-");
	info->coord.y = y + 3;
}

void	ft_print_secnd_panel(t_win *info, t_vm *vm)
{
	int	x;
	int	y;
	t_process	*pc1 = vm->process;
	t_process	*pc2 = vm->process->next;
	int			curs_x;
	int			curs_y;

	x = info->coord.x + 8;
	y = info->coord.y;
	mvwprintw(info->window, y++, x, "%-25s %d", "Number of players:",vm->nb_players);
	mvwprintw(info->window, y++, x, "%-25s %d", "Number of processes:",vm->nb_proc);
	mvwprintw(info->window, y++, x, "%-25s %d", "Last check:",vm->last_verif);

	/* DEBUG */
	y++;
	wattron(info->window, COLOR_PAIR(5));
	mvwprintw(info->window, y++, x, "%-10s", "DEBUG", pc1->pc, vm->mem[pc1->pc]);
	wattroff(info->window, COLOR_PAIR(5));

	wattron(info->window, COLOR_PAIR(3));
	mvwprintw(info->window, y++, x, "%-10s %-10d %02x", "pc1", pc1->pc, vm->mem[pc1->pc]);
	curs_x = (pc1->pc % ft_sqrt(MEM_SIZE)) * 3 + 10;
	curs_y = (pc1->pc / ft_sqrt(MEM_SIZE)) + 2;
	mvwprintw(info->window, y++, x, "x = %-10d y = %d", curs_x, curs_y);
	wattroff(info->window, COLOR_PAIR(3));

	wattron(info->window, COLOR_PAIR(4));
	mvwprintw(info->window, y - 2, x + 35, "%-10s %-10d %02x", "pc2", pc2->pc, vm->mem[pc2->pc]);
	curs_x = (pc2->pc % ft_sqrt(MEM_SIZE)) * 3 + 10;
	curs_y = (pc2->pc / ft_sqrt(MEM_SIZE)) + 2;
	mvwprintw(info->window, y - 1, x + 35, "x = %-10d y = %d", curs_x, curs_y);
	wattroff(info->window, COLOR_PAIR(4));
	y++;
	/* end DEBUG */
	
	wattron(info->window, A_STANDOUT);
	mvwprintw(info->window, y, x, "%-25s %d", "Lives since check:",vm->lives_since_check);
	wattroff(info->window, A_STANDOUT);
	y += 3;
	x = info->coord.x;
	while (x < info->dim.cols - 1)
		mvwprintw(info->window, y, x++, "-");
	info->coord.y = y + 3;
}

void	ft_print_third_panel(t_win *info, t_vm *vm)
{
	int		x;
	int		y;
	int		player;
	int		i;
	t_visu	*visu;
	
	x = info->coord.x + 8;
	y = info->coord.y;
	player = 0;
	visu = vm->visu;
	while (player < vm->nb_players)
	{
		if (vm->live_tab[player] != -1)
		{
			i = ft_get_player_color(vm, vm->live_tab[player]);
			wattron(info->window, COLOR_PAIR(visu->color_p[i + 1]));
			mvwprintw(info->window, y++, x, "%-25s (%d) has called Live!", vm->player[i].name, vm->player[i].id);
			wattroff(info->window, COLOR_PAIR(visu->color_p[i + 1]));
		}
		player++;
	}
}
