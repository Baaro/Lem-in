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

t_alst		*get_nearest_vertex(t_atab *at, t_htab *ht, t_alst *v)
{
	t_alst	*tmp;
	t_alst	*nearest_v;
	size_t	level;

	level = 0;
	nearest_v = NULL;
	tmp = get_vertex(ht, at, v->room->name);
	while (tmp && tmp->room)
	{
		if (is_nearest(tmp, level))
		{
			level = tmp->room->level;
			nearest_v = tmp;
		}
		if (nearest_v && is_start(ht, nearest_v))
			break ;
		tmp = tmp->next;
	}
	return (nearest_v);
}

void		lstpaths_init(t_lp *lp)
{
	if (!(ft_memset(lp, 0, sizeof(t_lp))))
		errors_memory(CANT_SETZERO, "lstpaths_init");
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

void		lstpaths_create(t_lp *lp, t_atab *at, t_htab *ht)
{
	t_path	*p;

	bfs(at, ht);
	if (spe(at, ht))
		lp->shortest_path = TRUE;
	else
	{
		while (paths_exist(at, ht))
		{
			p = path_init();
			if (path_create(p, at, ht))
			{
				lp->paths++;
				lstpaths_put(lp, p);
			}
		}
		if (!lp->paths)
			errors_algorithm(THERE_ARE_NO_POSSIBLE_WAYS);
	}
}
