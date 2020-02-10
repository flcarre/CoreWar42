/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:09:12 by wahasni           #+#    #+#             */
/*   Updated: 2020/01/13 14:09:29 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelfirst(t_list **alst)
{
	t_list *todelete;

	if (!alst)
		return ;
	todelete = alst;
	alst = (*alst)->next;
	ft_memdel((void*)todelete);
}
