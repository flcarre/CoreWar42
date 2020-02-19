/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:26:03 by hasni             #+#    #+#             */
/*   Updated: 2020/02/19 16:22:14 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_tab(void **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_inst(t_inst *inst)
{
	t_inst	*tmp;

	while (inst)
	{
		free_tab((void **)inst->param_arr);
		tmp = inst->next;
		// 	ft_memdel((void **)inst);
		inst = tmp;
	}
}

void	free_labels(t_label *labels)
{
	t_label	*tmp;

	while (labels)
	{
		ft_strdel(&labels->name);
		tmp = labels->next;
		ft_memdel((void **)labels);
		labels = tmp;
	}
}

int		free_asm(t_asm *asmb, int ret)
{
	ft_strdel(&asmb->file_name);
	if (asmb->labels)
		free_labels(asmb->labels);
	if (asmb->inst)
		free_inst(asmb->inst);
	return (ret);
}

int		free_str_value(char *str, int value)
{
	ft_strdel(&str);
	return (value);
}
