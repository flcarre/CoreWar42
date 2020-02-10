/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 03:40:59 by wahasni           #+#    #+#             */
/*   Updated: 2020/02/01 03:53:12 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	print_inst(t_inst *begin)
{
	t_inst *inst;

	inst = (t_inst *)begin;
	while (inst)
	{
	}
}

void		print_parser(t_asm *asmb)
{
	ft_printf("{red}FILE NAME IS : %s{reset}\n", asmb->file_name);
	if (!asmb->prog_name)
		ft_printf("{red}Empty name{reset}\n");
	else
		ft_printf("{red}Name of the champ : %s\n{reset}\n", asmb->prog_name);
	if (!asmb->prog_comment)
		ft_printf("{red}Empty comment{reset}\n");
	else
		ft_printf("{red}Comment of the champ : %s\n{reset}\n", asmb->prog_comment);
}
