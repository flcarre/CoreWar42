/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:02:52 by hasni             #+#    #+#             */
/*   Updated: 2020/02/19 16:22:14 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// Free a chaque return error

static t_bool	handle_name(t_asm *asmb, char **line)
{
	char	*tmp;
	int		ret;
	int		len;

	ret = 1;
	tmp = *line;
	len = ft_strchrindex(tmp, '"');
	if (len > PROG_NAME_LENGTH)
		return (ft_error("champion name too long", 1));
	ft_printf("line : %s, asmb->line\n", *line, asmb->line);
	while (ret > 0)
	{
		ft_strlcat(asmb->prog_name, tmp, PROG_NAME_LENGTH);
		ft_strcat(asmb->prog_name, ".");
		ft_strdel(&asmb->line);
		ft_printf("tmp_start : %s\n", tmp);
		if (ft_strchr(tmp, '"'))
        {
			asmb->prog_name[ft_strlen(asmb->prog_name) - 1] = 0;
			asmb->have_quote |= QUOTE_NAME;
            break ;
		}
		ret = get_next_line(asmb->fd, &asmb->line);
		tmp = asmb->line;
		len += ft_strchrindex(tmp, '"') + 1;
		if (len > PROG_NAME_LENGTH)
			return (ft_error("champion name too long", 1));
	}
	*line = tmp;
	return (0);
}

t_bool			parse_name(t_asm *asmb)
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
		return (ft_error("could not find starting '\"' at the beginning of the name", 1));
	line += n_start + 1;
	if (handle_name(asmb, &line))
		return (1);
	n_len = ft_strchrindex(line, '"');
	if (!(asmb->have_quote & QUOTE_NAME))
		return (ft_error("could not find ending '\"' at the end of the name", 1));
	if (n_len > PROG_NAME_LENGTH)
		return (ft_error("champion name too long", 1));
	ft_strlcat(asmb->prog_name, line, n_len + 1);
	asmb->check |= HAVE_NAME;
	return (0);
}
