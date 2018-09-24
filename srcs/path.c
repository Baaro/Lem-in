/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:16:53 by vsokolog          #+#    #+#             */
/*   Updated: 2018/09/22 12:16:54 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		path_del(t_path *p)
{
	while (p->step)
	{
		free(p->step);
		p->step = p->step->next;
	}
	free(p);
}

t_path		*path_init(void)
{
	t_path		*p;

	if (!(p = ft_memalloc(sizeof(t_path))))
		errors_memory(CANT_ALLOCATE_MEM, "path_init");
	return (p);
}

void		path_put(t_path *p, t_alst *v)
{
	t_stack		*tmp;

	if (p && v->room)
	{
		if (!(tmp = (t_stack *)ft_memalloc(sizeof(t_stack))))
			errors_memory(CANT_ALLOCATE_MEM, "path_put");
		tmp->vertex = v;
		tmp->vertex->room->visited = FALSE;
		tmp->next = p->step;
		p->step = tmp;
		p->steps++;
	}
}

bool		paths_exist(t_atab *at, t_htab *ht)
{
	t_alst		*v;

	v = get_vertex(ht, at, ht->end);
	while (v && v->room)
	{
		if (v->room->visited && !is_start(ht, v))
			return (TRUE);
		v = v->next;
	}
	return (FALSE);
}

bool		path_create(t_path *p, t_atab *at, t_htab *ht)
{
	t_alst		*v;
	bool		found;

	found = FALSE;
	v = get_vertex(ht, at, ht->end);
	path_put(p, v);
	while ((v = get_nearest_vertex(at, ht, v->room->name)))
	{
		if (ft_strcmp(ht->start, v->room->name) == 0)
		{
			v->room->visited = TRUE;
			found = TRUE;
			break ;
		}
		path_put(p, v);
	}
	if (!found)
		path_del(p);
	return (found);
}
