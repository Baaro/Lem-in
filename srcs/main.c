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

void		wave(t_queue *q, t_lstpaths *lp, t_path *p, intmax_t *ants)
{
	while (TRUE)
	{
		if (p->next)
			ft_printf("L%d-%s ", q->front->room->ant, q->front->room->name);
		else
			ft_printf("L%d-%s", q->front->room->ant, q->front->room->name);
		if (p->vertex->room->ant)
			break ;
		p = p->next;
		enqueue(q, p->vertex, 0);
		(*ants)++;
	}
}

void		send_ants(t_lstpaths *lp, intmax_t ants)
{
	t_path		*p;
	t_queue 	*q;

	p = lp->front;
	q = queue_init();
	enqueue(q, p->vertex, 0);
	while (!is_empty(q))
	{
		wave(q, p, &ants);
		p = lp->front;
	}
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

	send_ants(&lp, strg.info->ants);
	clear(&ht, &at, &strg, &lp);
	// system("leaks lem-in");
	return (0);
}
