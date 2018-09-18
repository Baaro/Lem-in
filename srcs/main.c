/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:58:42 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/29 12:39:34 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		clear(t_htab *ht, t_adjtab *at, t_storage *strg, t_lstpaths *lp)
{
	adjtab_clear(at);
	hashtab_clear(ht);
	info_clear(strg->info);
	buff_clear(strg->buff);
}

/*-----------------TO DO-----------------*/
/* HANDLE ERRORS: 
* 1. ERROR: Segfault has occurs when room has '#' at the beginning;
* 2. ERROR: Segfault has occurs when room has negative coordinates.
* 3. ERROR: There are no possbile ways from start to end;
*/
//                DONE

/*
* CREATE SEND_ANTS func:
* 1.
*/

/* CREATE USAGE:
* 1. Flag '-u' shows usage;
* 2. Flag '-ht' shows hashtable;
* 3. Flag '-at' shows adjtable;
* 4. Flag '-p' shows all possible ways which my algorithm was found.
* 5. Flag '-a' shows all info which we discussed above.
*/

void			ants_step(t_lstpaths *lp, t_queue_st *q, intmax_t *ants, const char *end)
{
	intmax_t	final_ant;

	final_ant = -1;
	while (*ants && ++final_ant != *ants)
	{
		if (found_room(end, q->front->step->vertex->room->name))
		{
			dequeue_st(q);
			lp->ants_in_graph--;
			(*ants)--;
		}
		if (q->front->step->next)
		{
			q->front->step->next->ant = q->front->step->ant;
			enqueue_st(q, q->front->step->next);
			ft_printf("L%jd-%s ", q->front->step->ant, q->front->step->next->vertex->room->name);
			dequeue_st(q);
		}
	}
	if (q->front->next)
		ft_printf("\n");
	else if (found_room(end, q->front->step->vertex->room->name))
		ft_printf("\n");		
}

void			ants_shift(t_lstpaths *lp, t_queue_st *q, intmax_t *ants, const char *end)
{
	intmax_t final_ant;

	final_ant = -1;
	while (++final_ant < lp->ants_in_graph)
	{
		if (found_room(end, q->front->step->vertex->room->name))
		{
			dequeue_st(q);
			lp->ants_in_graph--;			
			(*ants)--;
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
}

void			ants_put(t_lstpaths *lp, t_queue_st *q, intmax_t *ants, bool *all_ants_in_graph)
{
	static intmax_t	ant;	
	t_path			*p;

	p = lp->front;
	if (!(*all_ants_in_graph) && *ants && !p->step->ant)
	{
		while (p && ++ant <= lp->final_ant)
		{
			p->step->ant = ant;
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

void			put_all_ants_in_graph(t_lstpaths *lp, t_queue_st *q, intmax_t *ants, const char *end)
{
	bool	all_ants_in_graph;
	int i;

	all_ants_in_graph = FALSE;
	while (!all_ants_in_graph && *ants)
	{
		ants_shift(lp, q, ants, end);
		ants_put(lp, q, ants, &all_ants_in_graph);
	}
}

void			send_ants(t_lstpaths *lp, intmax_t ants, const char *end)
{
	t_queue_st	*q;

	q = queue_init_st();
	lp->final_ant = ants;
	put_all_ants_in_graph(lp, q, &ants, end);
	// while (ants)
		// ants_step(lp, q, &ants, end);
	queue_clear_st(q);
}

int			main(void)
{
	t_storage		strg;
	t_htab			ht;
	t_adjtab		at;
	t_lstpaths		lp;
	// t_usage		u;

	// usage_init(&u);
	// usage_analyze(&u, argc, argv);
	storage_init(&strg);
	valid_data(&strg);

	hashtab_init(&ht, &strg);
	hashtab_create(&ht, strg.buff, strg.info);

	printf("\nSTART: %s\n", ht.start);
	printf("FINISH: %s\n", ht.end);
	printf("\nHASHTABLE_ROOM\n");
	size_t i = -1;
	while (++i < (size_t)ht.size)
		hashtable_print_room(&ht, i);

	printf("\nHASHTABLE_COORDNATES\n");
	size_t k = -1;
	while (++k < (size_t)ht.size)
		hashtable_print_coord(&ht, k);

	adjtab_init(&at, ht.size);
	adjtab_create(&at, &ht, strg.buff, strg.info);

 	printf("\nADJLISTS\n");
 	size_t j = -1;
	while (++j < (size_t)at.size + 1)
		adjtab_print(&at, j);

	lstpaths_init(&lp);
	lstpaths_create(&lp, &at, &ht);

	// usage_print(&u, &lp, &at, &ht);

	send_ants(&lp, strg.info->ants, ht.end);
	clear(&ht, &at, &strg, &lp);
	// // system("leaks lem-in");
	return (0);
}
