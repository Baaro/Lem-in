/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 14:34:00 by vsokolog          #+#    #+#             */
/*   Updated: 2018/09/22 14:34:02 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static intmax_t	count_waves(t_path *p, intmax_t ants, intmax_t paths)
{
	intmax_t 	waves;

	waves = 0;
	if (p && p->next)
	{
		if (paths == 1)
			waves = p->steps + ants - 1;
		else if (paths == 2)
			waves = p->next->steps + ants / paths - 1;
	}
	return (waves);
}

void			antsshft(t_lp *lp, t_q_st *q, intmax_t *ants, char *e)
{
	intmax_t	final_ant;
	intmax_t	del;

	del = 0;
	final_ant = -1;
	while (*ants && ++final_ant < lp->ants_in_graph)
	{
		if (ft_strcmp(e, q->front->step->vertex->room->name) == 0)
		{
			dequeue_st(q);
			del++;
			(*ants)--;
		}
		if (q->front->step->next)
			step(q, 1);
	}
	if (!(*ants) || is_empty_st(q))
		ft_printf("\n");
	lp->ants_in_graph -= del;
}

void			antsput(t_lp *lp, t_q_st *q, intmax_t *a, bool *aig)
{
	static intmax_t	ant;
	size_t			i;
	t_path			*p;

	i = -1;
	p = lp->front;
	if (!(*aig) && *a && !p->step->ant)
	{
		while (p && ant < lp->final_ant && ++i < lp->paths)
		{
			p->step->ant = ++ant;
			lp->ants_in_graph++;
			enqueue_st(q, p->step);
			ft_printf("L%jd-%s ", p->step->ant, p->step->vertex->room->name);
			if (count_waves(p, *a, 1) < count_waves(p, *a, 2))
				break ;
			p = p->next;
		}
		ft_printf("\n");
	}
	if (lp->ants_in_graph == lp->final_ant)
		*aig = TRUE;
}
