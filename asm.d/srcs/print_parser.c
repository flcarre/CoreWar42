/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 03:40:59 by wahasni           #+#    #+#             */
/*   Updated: 2020/02/19 16:22:14 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void print_inst(t_inst *begin)
{
	t_inst *inst;

	inst = (t_inst *)begin;
	while (inst)
	{
	}
}

void print_parser(t_asm *asmb)
{
	ft_printf("%{RED}FILE NAME IS : %s%{}\n", asmb->file_name);
	if (!asmb->prog_name)
		ft_printf("%{RED}Empty name%{}\n");
	else
		ft_printf("%{RED}Name of the champ : %s\n%{}\n", asmb->prog_name);
	if (!asmb->prog_comment)
		ft_printf("%{RED}Empty comment%{}\n");
	else
		ft_printf("%{RED}Comment of the champ : %s\n%{}\n", asmb->prog_comment);
}
