#include "lem_in.h"

void	ants_step(t_lstpaths *lp, t_queue_st *q, intmax_t *ants, const char *end)
{
	intmax_t	final_ant;
	intmax_t	del;

	del = 0;	 	
	final_ant = -1;
	while (*ants && ++final_ant < *ants)
	{
		if (found_room(end, q->front->step->vertex->room->name))
		{
			dequeue_st(q);
			(*ants)--;
			del++;
		}
		if (q->front->step->next)
		{
			q->front->step->next->ant = q->front->step->ant;
			enqueue_st(q, q->front->step->next);
			ft_printf("L%jd-%s ", q->front->step->ant,
						q->front->step->next->vertex->room->name);
			dequeue_st(q);
		}
	}
	if (!is_empty_st(q) && found_room(end, q->front->step->vertex->room->name))
		ft_printf("\n");
	else if (!is_empty_st(q))
		ft_printf("\n");
	lp->ants_in_graph -= del;
}

void	ants_shift(t_lstpaths *lp, t_queue_st *q, intmax_t *ants, const char *end)
{
	intmax_t	final_ant;
	intmax_t	del;

	del = 0;
	final_ant = -1;
	while (*ants && ++final_ant < lp->ants_in_graph)
	{
		if (found_room(end, q->front->step->vertex->room->name))
		{
			dequeue_st(q);
			(*ants)--;
			del++;			
		}
		if (q->front->step->next)
		{
			q->front->step->next->ant = q->front->step->ant;
			q->front->step->ant = 0;
			enqueue_st(q, q->front->step->next);
			ft_printf("L%jd-%s ", q->front->step->next->ant,
						q->front->step->next->vertex->room->name);
			dequeue_st(q);
		}			
	}
    if (!(*ants))
        printf("\n");
	lp->ants_in_graph -= del;
}

void	ants_put(t_lstpaths *lp, t_queue_st *q, intmax_t *ants, bool *all_ants_in_graph)
{
	static intmax_t	ant;
	intmax_t 		i;	
	t_path			*p;

	i = -1;
	p = lp->front;
	if (!(*all_ants_in_graph) && *ants && !p->step->ant)
	{
		while (p && ant < lp->final_ant && ++i < lp->paths)
		{
			p->step->ant = ++ant;
			lp->ants_in_graph++;
			enqueue_st(q, p->step);
			ft_printf("L%jd-%s ", p->step->ant, p->step->vertex->room->name);
			p = p->next;
		}
		ft_printf("\n");
	}
	if (lp->ants_in_graph == lp->final_ant)
		*all_ants_in_graph = TRUE;
}

void	put_all_ants_in_graph(t_lstpaths *lp, t_queue_st *q, intmax_t *ants, const char *end)
{
	bool	all_ants_in_graph;

	all_ants_in_graph = FALSE;
	while (!all_ants_in_graph && *ants)
	{
		ants_shift(lp, q, ants, end);
		ants_put(lp, q, ants, &all_ants_in_graph);
	}
}

void    send_ants(t_lstpaths *lp, intmax_t ants, const char *end)
{
	t_queue_st	*q;

	q = queue_init_st();
	lp->final_ant = ants;
	put_all_ants_in_graph(lp, q, &ants, end);
	while (ants)
		ants_step(lp, q, &ants, end);
	queue_clear_st(q);
}