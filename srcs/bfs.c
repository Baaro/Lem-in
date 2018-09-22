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

t_alst		*get_vertex(t_htab *ht, t_atab *at, char *name)
{
	unsigned long	id;
	t_alst			*v;
	t_room			*room;

	id = get_id(ht, name, ft_strlen(name));
	room = htab_get(ht, id, name);
	// ft_printf("r: %s\n", room->name);
	// ft_printf("GO_TO_ATAB_GET\n");
	v = atab_get(at, room);
	// ft_printf("AFTER_ATAB_GET\n");
	return (v);
}

void		bfs(t_atab *at, t_htab *ht)
{
	t_queue			*q;
	t_alst			*v;
	size_t			level;

	level = 1;
	q = queue_init();
	if (!(v = get_vertex(ht, at, ht->start)))
	{
		// ft_printf("v: %s\n", v->room->name);
		errors_rooms(THERE_ARE_NO_LINKS_WITH_START);
	}
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
		v = get_vertex(ht, at, v->room->name);
	}
	queue_clear(q);
}
