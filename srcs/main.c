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

// Create usage in future
int			main(void)
{
	t_storage		strg;
	t_htab			ht;
	t_adjtab		at;
	t_lstpaths		lp;

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
	// send_ants(&lp);

	clear(&ht, &at, &strg, &lp);
	// system("leaks lem-in");
	return (0);
}
