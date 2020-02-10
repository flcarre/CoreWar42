/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:04:51 by hasni             #+#    #+#             */
/*   Updated: 2020/02/01 02:03:55 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static t_bool	handle_comment(t_asm *asmb, char **line)
{
	char	*tmp;
	int		ret;
	int		len;

	ret = 1;
	tmp = *line;
	len = ft_strchrindex(tmp, '"');
	if (len > COMMENT_LENGTH)
		return (ft_error("comment too long", 1));
	while (ret > 0 && !tmp[ft_strchrindex(tmp, '"')])
	{
		ft_strlcat(asmb->prog_comment, tmp, COMMENT_LENGTH);
		ft_strdel(&asmb->line);
		ret = get_next_line(asmb->fd, &asmb->line);
		tmp = asmb->line;
		len += ft_strchrindex(tmp, '"') + 1;
		if (len > COMMENT_LENGTH)
			return (ft_error("comment too long", 1));
	}
	*line = tmp;
    return (0);
}

t_bool			parse_comment(t_asm *asmb)
{
    int     n_start;
    int     n_len;
    char    *line;

    line = asmb->line + ft_strspn(asmb->line, " \t");
    n_len = ft_strcspn(line, " \t");
    n_start = n_len + ft_strspn(line + n_len, " \t");
    if (asmb->check & HAVE_COMMENT)
        return (ft_error("Champion already has a comment", 1));
    if (line[n_start] != '"')
        return (ft_error("could not find starting '\"' at the beginning of the comment", 1));
    line += n_start + 1;
    if (handle_comment(asmb, &line))
        return (1);
    n_len = ft_strchrindex(line, '"');
    if (!line[n_len] || line[n_len + 1 + ft_strspn(line + n_len + 1, " ")])
        ft_error("could not find ending '\"' at the end of the comment", 1);
    if (n_len > COMMENT_LENGTH)
        ft_error("comment too long", 1);
    ft_strlcat(asmb->prog_comment, line, n_len + 1);
    asmb->check |= HAVE_COMMENT;
    return (0);
}
