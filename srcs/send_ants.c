/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:17:35 by vsokolog          #+#    #+#             */
/*   Updated: 2018/09/22 12:17:36 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		step(t_q_st *q, bool clear)
{
	// if (q->front->step->next)
	q->front->step->next->ant = q->front->step->ant;
	enqueue_st(q, q->front->step->next);
	ft_printf("L%jd-%s ", q->front->step->ant,
				q->front->step->next->vertex->room->name);
	if (clear)
		q->front->step->ant = 0;
	dequeue_st(q);
}

void		antsstep(t_lp *lp, t_q_st *q, intmax_t *ants, char *end)
{
	intmax_t	final_ant;
	intmax_t	del;

	del = 0;
	final_ant = -1;
	while (*ants && ++final_ant < *ants && final_ant < lp->ants_in_graph)
	{
		if (ft_strcmp(end, q->front->step->vertex->room->name) == 0)
		{
			dequeue_st(q);
			(*ants)--;
			del++;
		}
		if (final_ant == *ants)
			break ;
		if (q->front->step->next)
			step(q, 0);
	}
	if ((!is_empty_st(q)
	&& ft_strcmp(end, q->front->step->vertex->room->name) == 0)
	|| !is_empty_st(q))
		ft_printf("\n");
	lp->ants_in_graph -= del;
}

void		atgraph(t_lp *lp, t_q_st *q, intmax_t *ants, char *end)
{
	bool	all_ants_in_graph;

	all_ants_in_graph = FALSE;
	while (!all_ants_in_graph || *ants)
	{
		antsshft(lp, q, ants, end);
		antsput(lp, q, ants, &all_ants_in_graph);
	}
}

void		send_ants(t_lp *lp, intmax_t ants, char *end)
{
	t_q_st	*q;

	q = queue_init_st();
	lp->final_ant = ants;
	atgraph(lp, q, &ants, end);
	while (ants)
		antsstep(lp, q, &ants, end);
	queue_clear_st(q);
}
