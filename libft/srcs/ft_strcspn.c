/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 22:23:02 by hasni             #+#    #+#             */
/*   Updated: 2020/01/30 22:25:38 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcspn(const char *s, const char *charset)
{
	int	i;

	i = 0;
	while (s[i] && !ft_charinset(s[i], charset))
		i++;
	return (i);
}
