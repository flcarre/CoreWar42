/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 17:28:31 by hasni             #+#    #+#             */
/*   Updated: 2020/02/10 15:23:05 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void		write_number(int fd, t_inst *inst, int i)
{
	if (inst->param_arr[i][0] == '%')
		disp_hexlen(fd, ft_atoi(&inst->param_arr[i][1]), inst->direct_len);
	else
		disp_hexlen(fd, ft_atoi(&inst->param_arr[i][0]), 2);
}

static char		*get_label(t_inst *inst, int i)
{
	int			begin;
	int			len;
	char		*label;

	begin = inst->param_arr[i][0] == '%' ? 2 : 1;
	len = ft_strlen(inst->param_arr[i]) - begin;
	if (!(label = ft_strsub(inst->param_arr[i], begin, len)))
		return (ft_error_str("ft_strsub failed in get_label", NULL);
	return (label);
}

static t_bool	write_label(int fd, t_inst *inst, t_list *label_list, int i)
{
	char		*label;
	char		*name;
	int			addr;
	int			direct_len;

	if (!(label = get_label(inst, i)))
		return (1);
	addr = -1;
	while (label_list)
	{
		name = ((t_label *)label_list->content)->name;
		if (ft_strcmp(label, name) == 0)
		{
			addr = ((t_label *)label_list->content)->addr;
			break ;
		}
		label_list = label_list->next;
	}
	direct_len = inst->param_arr[i][0] == '%' ? inst->direct_len : 2;
	if (addr != -1)
		disp_hexlen(fd, addr - inst->addr, direct_len);
	else
		ft_error("can't find label", 1);
	ft_strdel(&label);
	return (0);
}

static t_bool	write_inst(int fd, t_inst *inst, t_list *label_list)
{
	int			i;

	disp_hexlen(fd, inst->opcode, 1);
	if (inst->ocp)
		disp_hexlen(fd, inst->param_byte, 1);
	i = 0;
	while (i < inst->param_num)
	{
		if (inst->param_arr[i][0] == 'r')
			disp_hexlen(fd, ft_atoi(&inst->param_arr[i][1]), 1);
		else if (!ft_strchr(inst->param_arr[i], ':'))
			write_number(fd, inst, i);
		else
		{
			if (write_label(fd, inst, label_list, i))
				return (1);
		}
		i++;
	}
	return (0);
}

t_bool	write_champion(t_asmb *asmb)
{
	if ((asmb->fd = open(asmb->file_name, 0)) == -1)
		return (ft_error("open file failed", 1)); // Free all
	disp_hexlen(asmb->fd, COREWAR_EXEC_MAGIC, 4);
	write(asmb->fd, asmb->prog_name, PROG_NAME_LENGTH);
	disp_hexlen(asmb->fd, asmb->accu_len, 8);
	write(asmb->fd, asmb->prog_comment, COMMENT_LENGTH);
	write(asmb->fd, "\0\0\0\0", 4);
	tmp = asmb->inst;
	while (tmp)
	{
		if (write_inst(asmb->fd, (t_inst *)t->content, asmb->labels))
			return (1);
		tmp = tmp->next;
	}
	ft_printf("Writing output program to %s\n", asmb->file_name);
	if ((close(asmb->fd)) == -1)
		return (ft_error("close file failed", 1)); // Free_all
	return (0);
}
