/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:36:33 by hasni             #+#    #+#             */
/*   Updated: 2020/01/29 16:36:47 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strspn(const char *s, const char *charset)
{
	int		i;

	i = -1;
	while (s[++i] && ft_charinset(s[i], charset))
		;
	return (i);
}
