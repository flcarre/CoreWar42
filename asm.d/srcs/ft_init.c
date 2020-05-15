/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:27:41 by wahasni           #+#    #+#             */
/*   Updated: 2020/05/15 19:09:16 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_asm(t_asm *asmb)
{
	asmb->fd = 0;
	asmb->line = NULL;
	asmb->file_name = NULL;
	asmb->check = 0;
	asmb->have_quote = 0;
	asmb->lab = 0;
	ft_bzero(asmb->prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(asmb->prog_comment, COMMENT_LENGTH + 1);
	asmb->accu_len = 0;
	asmb->inst = NULL;
	asmb->labels = NULL;
}
