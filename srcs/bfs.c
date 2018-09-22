/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:15:01 by vsokolog          #+#    #+#             */
/*   Updated: 2018/09/22 12:15:03 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_alst		*get_vertex(t_htab *htab, t_atab *at, char *name)
{
	unsigned long	id;
	t_alst			*vertex;
	t_room			*room;

	id = get_id(htab, name, ft_strlen(name));
	room = htab_get(htab, id, name);
	vertex = atab_get(at, room);
	return (vertex);
}

void		bfs(t_atab *at, t_htab *htab)
{
	t_queue			*q;
	t_alst			*v;
	size_t			level;

	level = 1;
	q = queue_init();
	if (!(v = get_vertex(htab, at, htab->start)))
		errors_rooms(THERE_ARE_NO_LINKS_WITH_START);
	enqueue(q, v, level);
	while (!is_empty(q))
	{
		level = v->room->level;
		while (v)
		{
			if (!v->room->visited
			&& !v->room->in_queue)
				enqueue(q, v, level + 1);
			v = v->next;
		}
		v = dequeue(q);
		v = get_vertex(htab, at, v->room->name);
	}
	queue_clear(q);
}
