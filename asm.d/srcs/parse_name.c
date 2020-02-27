/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:02:52 by wahasni           #+#    #+#             */
/*   Updated: 2020/02/27 20:57:15 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	handle_name(t_asm *asmb, char **line)
{
	char	*tmp;
	int		ret;

	ret = 1;
	tmp = *line;
	while (ret > 0)
	{
		ft_strlcat(asmb->prog_name, tmp, PROG_NAME_LENGTH);
		ft_strcat(asmb->prog_name, "\n");
		if (ft_strchr(tmp, '"'))
		{
			asmb->prog_name[ft_strlen(asmb->prog_name) - 1] = 0;
			asmb->have_quote |= QUOTE_NAME;
			break ;
		}
		ft_strdel(&asmb->line);
		ret = get_next_line(asmb->fd, &asmb->line);
		tmp = asmb->line;
		if (ft_strlen(asmb->prog_name) - 1 > PROG_NAME_LENGTH)
			return (ft_error("champion name too long", 1));
	}
	*line = tmp;
	return (0);
}

int			parse_name(t_asm *asmb)
{
	int		n_start;
	int		n_len;
	char	*line;

	line = asmb->line + ft_strspn(asmb->line, " \t");
	n_len = ft_strcspn(line, " \t");
	n_start = n_len + ft_strspn(line + n_len, " \t");
	if (asmb->check & HAVE_NAME)
		return (ft_error("Champion already has a name", 1));
	if (line[n_start] != '"')
		return (ft_error("There isnt '\"' at the beginning of the name", 1));
	line += n_start + 1;
	if (handle_name(asmb, &line))
		return (1);
	n_len = ft_strchrindex(line, '"');
	if (!(asmb->have_quote & QUOTE_NAME))
		return (ft_error("There isnt '\"' at the end of the name", 1));
	if (n_len > PROG_NAME_LENGTH)
		return (ft_error("champion name too long", 1));
	ft_strlcat(asmb->prog_name, line, n_len + 1);
	asmb->check |= HAVE_NAME;
	return (0);
}
