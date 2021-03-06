/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:55:10 by lutsiara          #+#    #+#             */
/*   Updated: 2020/05/11 16:42:29 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static int	ft_parse_magic(int fd)
{
	unsigned char buff[4];

	if (read(fd, &buff, 4) < 4)
		return (1);
	if (ft_read_octet(buff, 4) == COREWAR_EXEC_MAGIC)
		return (0);
	return (1);
}

static int	ft_parse_exec(int fd, t_vm *vm)
{
	unsigned char buff[4];

	if (read(fd, buff, 4) != 4)
		return (1);
	if ((vm->player[vm->nb_players].size = \
		ft_read_octet(buff, 4)) <= 0 || \
		vm->player[vm->nb_players].size > CHAMP_MAX_SIZE)
		return (SIZE_ERROR);
	if (read(fd, vm->player[vm->nb_players].comment, \
		COMMENT_LENGTH + 4) != COMMENT_LENGTH + 4)
		return (COMMENT_ERROR);
	if (read(fd, vm->player[vm->nb_players].exec, \
			vm->player[vm->nb_players].size) != \
			vm->player[vm->nb_players].size)
		return (SIZE_ERROR);
	if (read(fd, buff, 4))
		return (SIZE_ERROR);
	ft_check_empty(vm);
	return (0);
}

int			ft_check_players_number(t_vm *vm, int player_nb)
{
	int i;

	vm->player_numbers[(vm->nb_option - 1 < 0) ? 0 : vm->nb_option - 1] = 1;
	vm->nb_option = 0;
	i = 0;
	while (i < vm->nb_players)
	{
		if (vm->player[(player_nb - 1 < 0) ? 0 : player_nb - 1].id \
			== vm->player[i].id && \
			((player_nb - 1 < 0) ? 0 : player_nb - 1) != i)
		{
			vm->player[i].id = ft_get_next_number(vm);
			return (ft_check_players_number(vm, i));
		}
		i++;
	}
	return (0);
}

int			ft_get_next_number(t_vm *vm)
{
	int i;

	i = -1;
	while (++i < MAX_PLAYERS)
		if (!vm->player_numbers[i])
		{
			vm->player_numbers[i] = 1;
			return (i + 1);
		}
	return (0);
}

int			ft_parse_players(t_vm *vm, char **av, int i)
{
	int fd;

	if (ft_check_extension(av[i]))
		return (FILE_ERROR);
	if ((fd = open(av[i], O_RDONLY)) <= 0)
		return (FILE_ERROR);
	if (vm->nb_players >= MAX_PLAYERS)
		return (PLAYER_OVERLOAD);
	if (ft_parse_magic(fd))
		return (MAGIC_ERROR);
	if (read(fd, vm->player[vm->nb_players].name, \
			PROG_NAME_LENGTH + 4) != PROG_NAME_LENGTH + 4)
		return (NAME_ERROR);
	if (ft_parse_exec(fd, vm))
		return (EXEC_ERROR);
	vm->nb_players++;
	vm->player[vm->nb_players - 1].id = vm->nb_option \
							? vm->nb_option \
							: ft_get_next_number(vm);
	if (vm->nb_option)
		return (ft_check_players_number(vm, vm->nb_players));
	else
		return (0);
}
