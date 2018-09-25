/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstspaths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:16:18 by vsokolog          #+#    #+#             */
/*   Updated: 2018/09/22 12:16:20 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lstpaths_init(t_lp *lp)
{
	if (!(ft_memset(lp, 0, sizeof(t_lp))))
		errors_memory(CANT_SETZERO, "lstpaths_init");
}

bool	is_end(t_htab *ht, t_alst *v)
{
	if (ft_strcmp(ht->end, v->room->name) == 0)
		return (TRUE);
	return (FALSE);
}

bool	is_start(t_htab *ht, t_alst *v)
{
	if (ft_strcmp(ht->start, v->room->name) == 0)
		return (TRUE);
	return (FALSE);
}

bool		shortest_path_found(t_htab *ht, t_alst *v)
{
	if (is_start(ht, v)
	&& v->room->shortest_path)
		return (TRUE);
	return (FALSE);
}

bool		is_nearest(t_alst *tmp, size_t level)
{
	if (tmp->room && tmp->room->visited
	&& (level == 0 || level >= tmp->room->level))
		return (TRUE);
	return (FALSE);
}

t_alst		*get_nearest_vertex(t_atab *at, t_htab *ht, t_alst *v)
{
	t_alst	*tmp;
	t_alst	*nearest_v;
	size_t	level;

	level = 0;
	nearest_v = NULL;
	tmp = get_vertex(ht, at, v->room->name);
	ft_printf("v[l:%zu][v:%zu]: %s\n", tmp->room->level,
	tmp->room->visited,
	tmp->room->name);
	while (tmp && tmp->room)
	{
		if (is_nearest(tmp, level)
		&& (is_end(ht, v) && is_start(ht, tmp)) ? FALSE : TRUE	// if link is not start-end
		&& (!is_end(ht, v) && is_end(ht, tmp)) ? FALSE : TRUE)	// if we have link start-end and we are not at the end that we shouldn't go to end
		{
			ft_printf("tmp[l:%zu][v:%zu]: %s\n", tmp->room->level,
			tmp->room->visited,
			tmp->room->name);
			level = tmp->room->level;
			nearest_v = tmp;
		}
		if (nearest_v && is_start(ht, nearest_v))
			break ;
		tmp = tmp->next;
	}
	return (nearest_v);
}

void		lstpaths_put(t_lp *lp, t_path *p)
{
	if (lp->front == NULL)
	{
		lp->front = p;
		lp->front->next = NULL;
		lp->rear = lp->front;
	}
	else
	{
		lp->rear->next = p;
		lp->rear->next->next = NULL;
		lp->rear = lp->rear->next;
	}
}

bool		shortest_path_find(t_atab *at, t_htab *ht, bool *shortest_path)
{
	t_alst		*v;

	if (!(*shortest_path))
	{
		v = get_vertex(ht, at, ht->end);
		while (v && v->room)
		{
			if (is_start(ht, v))
			{
				*shortest_path = TRUE;
				return (TRUE);
			}
			v = v->next;
		}
	}
	return (FALSE);
}

void		lstpaths_create(t_lp *lp, t_atab *at, t_htab *ht)
{
	t_path		*p;
	bool		shortest_path;

	bfs(at, ht);
	shortest_path = FALSE;
	while (paths_exist(at, ht))
	{
		p = path_init();
		if (!shortest_path && shortest_path_find(at, ht, &shortest_path))
		{
			path_put(p, get_vertex(ht, at, ht->end));
			lp->paths++;
			lstpaths_put(lp, p);
		}
		else if (path_create(p, at, ht))
		{
			lp->paths++;
			lstpaths_put(lp, p);
		}
	}
	if (!lp->paths)
		errors_algorithm(THERE_ARE_NO_POSSIBLE_WAYS);
}
