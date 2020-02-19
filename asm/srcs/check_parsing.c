/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:28:19 by hasni             #+#    #+#             */
/*   Updated: 2020/02/01 03:40:03 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static t_bool	check_each_label(t_inst *inst, t_label *labels_list, int i)
{
	int			j;
	int			found;
	t_label		*label;

	j = ft_strchr(inst->param_arr[i], '%') ? 2 : 1;
	found = 0;
	while (labels_list)
	{
		label = (t_label *)labels_list;
		if (ft_strcmp(&inst->param_arr[i][j], label->name) == 0)
		{
			found = 1;
			break ;
		}
		labels_list = labels_list->next;
	}
	if (found == 0)
		return (ft_error("can't find referenced label of the parameters", 1));
	return (0);
}

static t_bool	check_label(t_inst *inst_list, t_label *labels_list)
{
	t_inst		*inst;
	int			i;

	while (inst_list)
	{
		inst = (t_inst *)inst_list;
		i = 0;
		while (i < inst->param_num)
		{
			if (ft_strchr(inst->param_arr[i], ':'))
				if (check_each_label(inst, labels_list, i))
					return (1);
			i++;
		}
		inst_list = inst_list->next;
	}
	return (0);
}

t_bool  		check_parsing(t_asm *asmb)
{
    if (!(asmb->check & HAVE_NAME))
		return (ft_error("champion has no name", 1));
	if (!(asmb->check & HAVE_COMMENT))
		return (ft_error("champion has no comment", 1));
	if (!asmb->inst)
		return (ft_error("champion has no instruction", 1));
	if (check_label(asmb->inst, asmb->labels))
		return (1);
	return (0);
}
