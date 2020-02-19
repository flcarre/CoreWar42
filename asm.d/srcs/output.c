/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 17:28:31 by hasni             #+#    #+#             */
/*   Updated: 2020/02/19 16:22:14 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <fcntl.h>

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
		return (ft_error_str("ft_strsub failed in get_label", NULL));
	return (label);
}

static t_bool	write_label(int fd, t_inst *inst, t_label *labels, int i)
{
	char		*label;
	char		*name;
	int			addr;
	int			direct_len;

	if (!(label = get_label(inst, i)))
		return (1);
	addr = -1;
	while (label)
	{
		if (!labels)
			return (0);
		name = labels->name;
		if (ft_strcmp(label, name) == 0)
		{
			addr = labels->addr;
			break ;
		}
		labels = labels->next;
	}
	direct_len = inst->param_arr[i][0] == '%' ? inst->direct_len : 2;
	if (addr != -1)
		disp_hexlen(fd, addr - inst->addr, direct_len);
	else
		ft_error("can't find label", 1);
	ft_strdel(&label);
	return (0);
}

static t_bool	write_inst(int fd, t_inst *inst, t_label *labels)
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
			if (write_label(fd, inst, labels, i))
				return (1);
		}
		i++;
	}
	return (0);
}

t_bool	output(t_asm *asmb)
{
	t_inst	*inst;
	t_label	*labels;

	if ((asmb->fd = open(asmb->file_name, O_WRONLY | O_CREAT, 0755)) == -1)
		return (ft_error("open file failed", 1));
	if (asmb->accu_len > 682)
		return (ft_error("exec code size too big", 1));
	disp_hexlen(asmb->fd, COREWAR_EXEC_MAGIC, 4);
	// ft_printf("asmb->name : %s | ft_strlen : %d\n", asmb->prog_name, ft_strlen(asmb->prog_name));
	asmb->prog_name[ft_strlen(asmb->prog_name) - 1] = 0;
	asmb->prog_comment[ft_strlen(asmb->prog_comment) - 1] = 0;
	if (asmb->prog_name[ft_strlen(asmb->prog_name)] == '"')
		asmb->prog_name[ft_strlen(asmb->prog_name)] = 0;
	if (asmb->prog_comment[ft_strlen(asmb->prog_comment)] == '"')
		asmb->prog_name[ft_strlen(asmb->prog_name)] = 0;
	// ft_printf("PROG_NAME : %s | PROG_COMMENT : %s\n", asmb->prog_name, asmb->prog_comment);
	write(asmb->fd, asmb->prog_name, PROG_NAME_LENGTH);
	disp_hexlen(asmb->fd, asmb->accu_len, 8);
	write(asmb->fd, asmb->prog_comment, COMMENT_LENGTH);
	write(asmb->fd, "\0\0\0\0", 4);
	inst = asmb->inst;
	labels = asmb->labels;
	while (inst)
	{
		if (write_inst(asmb->fd, inst, labels))
			return (1);
		inst = inst->next;
	}
	ft_printf("Writing output program to %s\n", asmb->file_name);
	if ((close(asmb->fd)) == -1)
		return (ft_error("close file failed", 1));
	return (0);
}
