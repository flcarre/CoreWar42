/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:40:50 by hasni             #+#    #+#             */
/*   Updated: 2020/02/17 02:38:17 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_bool	parse(t_asm *asmb)
{
	while (get_next_line(asmb->fd, &asmb->line))
	{
		if (asmb->line[0] == COMMENT_CHAR || asmb->line[0] == ';')
			;
		else if (ft_strnequ(asmb->line + ft_strspn(asmb->line, " \t"),
				NAME_CMD_STRING, 5))
		{
			if (parse_name(asmb))
				return (free_asm(asmb, 1));
		}
		else if (ft_strnequ(asmb->line + ft_strspn(asmb->line, " \t"),
				COMMENT_CMD_STRING, 7))
		{
			if (parse_comment(asmb))
				return (free_asm(asmb, 1));
		}
		else if (!parse_instruction(asmb))
			return (free_asm(asmb, 1));
		ft_strdel(&asmb->line);
	}
	if (check_parsing(asmb))
		return (free_asm(asmb, 1));
	return (0);
}
