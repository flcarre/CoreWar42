/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:20:58 by wahasni           #+#    #+#             */
/*   Updated: 2020/02/27 20:57:31 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		remove_comment(char *str)
{
	int		i;
	int		j;
	int		index;

	i = ft_strchrindex(str, COMMENT_CHAR);
	j = ft_strchrindex(str, ALT_COMMENT_CHAR);
	if (i > j)
		index = j;
	else
		index = i;
	if (index >= 0)
		while (str[index])
			str[index] = 0;
}

static t_inst	*create_inst(t_asm *asmb, t_op *op)
{
	t_inst	*inst;

	if (!(inst = (t_inst *)malloc(sizeof(t_inst))))
		return (NULL);
	inst->opcode = op->opcode;
	inst->addr = asmb->accu_len;
	inst->len = 1 + op->ocp;
	inst->ocp = op->ocp;
	inst->direct_len = op->direct_len;
	return (inst);
}

static t_op		*check_inst(char *str)
{
	int		inst_len;
	char	*inst;
	t_op	*op;

	inst = NULL;
	inst_len = 0;
	while (str[inst_len] && !ft_isspace(str[inst_len])
		&& str[inst_len] != DIRECT_CHAR)
		inst_len++;
	if (!(inst = ft_strsub(str, 0, inst_len)))
		return (NULL);
	if (!(op = get_op(inst)))
	{
		ft_strdel(&inst);
		return (NULL);
	}
	ft_strdel(&inst);
	return (op);
}

static int		check_label_infront(t_asm *asmb, char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] && !ft_isspace(str[i]) && str[i] != DIRECT_CHAR)
	{
		if (str[i] == LABEL_CHAR)
		{
			j = 0;
			while (j < i)
				if (!ft_strchr(LABEL_CHARS, str[j++]))
					return (ft_error("label contains non-LABEL_CHARS", 1));
			ft_list_push_back_label(&asmb->labels,
				ft_strsub(str, 0, i), asmb->accu_len);
			return (i + 1);
		}
		i++;
	}
	return (0);
}

int				parse_instruction(t_asm *asmb)
{
	char	*str;
	int		i;
	t_op	*op;
	t_inst	*inst;

	remove_comment(asmb->line);
	if (!(str = ft_strtrim(asmb->line)))
		return (1);
	i = check_label_infront(asmb, str);
	if (!str[i])
		return (free_str_value(str, 1));
	i = skip_space(str, i);
	if (!(op = check_inst(str + i)))
		return (free_str_value(str, 0));
	if (!(inst = create_inst(asmb, op)))
		return (free_str_value(str, 0));
	i = skip_nonspace(str, i);
	i = skip_space(str, i);
	if (check_param(str + i, op, inst, -1))
		return (free_str_value(str, free_just_inst(inst, 0)));
	asmb->accu_len += inst->len;
	ft_list_push_back_inst(&asmb->inst, inst);
	return (free_str_value(str, free_just_inst(inst, 1)));
}
