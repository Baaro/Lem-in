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

void		path_put(t_path *p, t_adjlst *vertex)
{
	t_stack		*tmp;

	if (p && vertex->room)
	{
		if (!(tmp = (t_stack *)ft_memalloc(sizeof(t_stack))))
			errors_memory(CANT_ALLOCATE_MEM, "path_put");
		tmp->vertex = vertex;
		tmp->vertex->room->visited = FALSE;
		tmp->next = p->step;
		p->step = tmp;
		p->steps++;
	}
}

bool		paths_exist(t_adjtab *at, t_htab *ht)
{
	t_adjlst	*vertex;

	vertex = get_vertex(ht, at, ht->end);
	while (vertex && vertex->room)
	{
		if (vertex->room->visited)
			return (TRUE);
		vertex = vertex->next;
	}
	return (FALSE);
}

bool		path_create(t_path *p, t_adjtab *at, t_htab *ht)
{
	t_adjlst	*vertex;
	bool		found;

	found = FALSE;
	vertex = get_vertex(ht, at, ht->end);
	path_put(p, vertex);
	while ((vertex = get_nearest_vertex(at, ht, vertex->room->name)))
	{
		if (ft_strcmp(ht->start, vertex->room->name) == 0)
		{
			vertex->room->visited = TRUE;
			found = TRUE;
			break ;
		}
		path_put(p, vertex);
	}
	if (!found)
		path_del(p);
	return (found);
}
