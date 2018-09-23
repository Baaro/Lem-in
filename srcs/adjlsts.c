/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjlsts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:14:21 by vsokolog          #+#    #+#             */
/*   Updated: 2018/09/22 12:14:22 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	alst_init(t_alst **lsts, ssize_t size)
{
	ssize_t	i;

	i = -1;
	while (++i < size)
	{
		if (!(lsts[i] = (t_alst *)ft_memalloc(sizeof(t_alst))))
			errors_memory(CANT_ALLOCATE_MEM, "adjlst_init");
	}
}

bool	alst_exists(const t_alst *elem, const t_room *room)
{
	t_alst	*tmp;

	if (elem && room)
	{
		tmp = (t_alst *)elem;
		while (tmp && tmp->room != NULL)
		{
			if (ft_strcmp(tmp->room->name, room->name) == 0)
				return (TRUE);
			tmp = tmp->next;
		}
	}
	return (FALSE);
}

void	*alst_put(t_alst *elem, const t_room *room)
{
	t_alst	*tmp;

	tmp = NULL;
	if (elem && room)
	{
		tmp = (t_alst *)malloc(sizeof(t_alst));
		tmp->room = (t_room *)room;
		tmp->next = elem->next;
		elem->next = tmp;
	}
	return (tmp);
}
