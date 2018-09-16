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

intmax_t		ants_exist(intmax_t ants)
{
	return (ants);
}

void		ants_put(t_path *p, size_t ant, t_stack *step, bool final)
{
	if (p->next && !final)
	{
		step->ant = ant;
		ft_printf("L%d-%s ", step->ant, step->vertex->room->name);
	}
	else
	{
		step->ant = ant;
		ft_printf("L%d-%s\n", step->ant, step->vertex->room->name);
	}
}

bool		all_ants_in_graph(intmax_t ants, intmax_t ants_in_graph)
{
	if (ants == ants_in_graph)
		return (TRUE);
	return (FALSE);
}

bool			front_room_is_free(intmax_t ant)
{
	if (!ant)
		return (TRUE);
	return (FALSE);
}

void		own_sleep(void)
{
	ssize_t i = -1;

	while (++i < 2147483641);
}

// void		waves(t_lstpaths *lp, t_htab *ht, t_queue_st *q, intmax_t ants)
// {
// 	size_t 	ant;
// 	t_stack	*step;
// 	t_path 	*path;


// 	ant = 0;
// 	while (ants_exist(ants))
// 	{
// 		path = lp->front;
// 		if (!all_ants_in_graph(ants, lp->ants_in_graph) && front_room_is_free(path->step->ant))
// 		{
// 			step = path->step;
// 			while (path && ant >= ants)
// 			{
// 				enqueue_st(q, step);
// 				ants_put(path, ++ant, step);
// 			}
// 		}
	// }
// }

void		waves(t_lstpaths *lp, t_htab *ht, t_queue_st *q, intmax_t ants)
{
	t_path		*path;
	t_stack		*step;
	intmax_t	final_ant;
	bool		back_slashn;
	size_t 		ant;
	size_t		i;

	ant = 0;
	back_slashn = 0;
	while (ants_exist(ants))
	{
		// own_sleep();
		final_ant = ants;
		path = lp->front;
		if (!all_ants_in_graph(ants, lp->ants_in_graph) && front_room_is_free(path->step->ant))
		{
			while (path && ant != ants)
			{
				back_slashn = 0;
				if (!path->next)
					back_slashn = 1;
				step = path->step;
				enqueue_st(q, step);
				// queue_print_st(q);
				ants_put(path, ++ant, step, back_slashn);
				lp->ants_in_graph++;
				path = path->next;
			}
		}
		else
		{
			i = -1;
			while (++i < lp->paths)
			{
				back_slashn = 0;
				if (found_room(ht->end, q->front->step->vertex->room->name))
				{
					dequeue_st(q);
					lp->ants_in_graph--;
					ants--;
				}
				printf("ants: %jd", ants);
				if (final_ant == q->front->step->ant)
					back_slashn = 1;
				enqueue_st(q, q->front->step->next);
				ants_put(path, q->front->step->ant, q->front->step->next, back_slashn);
				q->front->step->ant = 0;
				dequeue_st(q);
				// queue_print_st(q);
			}
		}
	}
}

// void		waves(t_lstpaths *lp, t_htab *ht, t_queue_st *q, intmax_t ants, size_t ant)
// {
// 	t_path		*path;
// 	t_stack		*step;
// 	bool		final;
// 	size_t		i;

// 	path = lp->front;
// 	// own_sleep();
// 	if (ants_exist(ants))
// 	{
// 		if (!all_ants_in_graph(ants, lp->ants_in_graph) && front_room_is_free(path->step->ant))
// 		{
// 			while (path && ant != ants)
// 			{
// 				final = 0;
// 				if (!path->next)
// 					final = 1;
// 				step = path->step;
// 				enqueue_st(q, step);
// 				// queue_print_st(q);
// 				ants_put(path, ++ant, step, final);
// 				lp->ants_in_graph++;
// 				path = path->next;
// 			}
// 		}
// 		else
// 		{
// 			// own_sleep();
// 			i = -1;
// 			while (++i < lp->paths)
// 			{
// 				final = 0;
// 				if (found_room(ht->end, q->front->step->vertex->room->name))
// 				{
// 					// printf("ant -> [%zu] finished\n", q->front->step->ant);
// 					dequeue_st(q);
// 					lp->ants_in_graph--;
// 					ants--;
// 					// printf("ants: %jd\n", ants);
// 				}
// 				if (q->front->step->ant == ants)
// 					final = 1;
// 				// if (q->front->step->next)
// 					// printf("IT'S A SEG MAN!!!\n");
// 				enqueue_st(q, q->front->step->next);
// 				ants_put(path, q->front->step->ant, q->front->step->next, final);
// 				q->front->step->ant = 0;
// 				dequeue_st(q);
// 				// queue_print_st(q);
// 			}
// 		}
// 		waves(lp, ht, q, ants, ant);
// 	}
// }

void		send_ants(t_lstpaths *lp, t_htab *ht, intmax_t ants)
{
	t_queue_st		*q;;

	q = queue_init_st();
	waves(lp, ht, q, ants);
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

	// hashtab_init(&ht, &strg);
	// hashtab_create(&ht, strg.buff, strg.info);

	// printf("\nSTART: %s\n", ht.start);
	// printf("FINISH: %s\n", ht.end);
	// printf("\nHASHTABLE_ROOM\n");
	// size_t i = -1;
	// while (++i < (size_t)ht.size)
	// 	hashtable_print_room(&ht, i);

	// printf("\nHASHTABLE_COORDNATES\n");
	// size_t k = -1;
	// while (++k < (size_t)ht.size)
	// 	hashtable_print_coord(&ht, k);

	// adjtab_init(&at, ht.size);
	// adjtab_create(&at, &ht, strg.buff, strg.info);

 // 	printf("\nADJLISTS\n");
 // 	size_t j = -1;
	// while (++j < (size_t)at.size + 1)
	// 	adjtab_print(&at, j);

	// lstpaths_init(&lp);
	// lstpaths_create(&lp, &at, &ht);

	// // usage_print(&u, &lp, &at, &ht);

	// send_ants(&lp, &ht, strg.info->ants);
	// clear(&ht, &at, &strg, &lp);
	// // system("leaks lem-in");
	return (0);
}
