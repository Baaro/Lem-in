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

void		clear(t_htab *htab, t_adjtab *adjtab, t_storage *strg)
{
	adjtab_clear(adjtab);
	hashtab_clear(htab);
	info_clear(strg->info);
	buff_clear(strg->buff);
}

int			main(void)
{
	t_storage		strg;
	t_htab			htab;
	t_adjtab		adjtab;

	storage_init(&strg);
	valid_data(&strg);

	hashtab_init(&htab, &strg);
	hashtab_create(&htab, strg.buff, strg.info);

	adjtab_init(&adjtab, &htab);
	adjtab_create(&adjtab, &htab, strg.buff, strg.info);

	printf("\nHASHTABLE_ROOM\n");
	size_t i = -1;
	while (++i < (size_t)htab.size)
		hashtable_print_room(&htab, i);

	printf("\nHASHTABLE_COORDNATES\n");
	size_t k = -1;
	while (++k < (size_t)htab.size)
		hashtable_print_coord(&htab, k);

 	printf("\nADJLISTS\n");
 	size_t j = -1;
	while (++j < (size_t)adjtab.size + 1)
		adjtab_print(&adjtab, j);

	bfs(&adjtab, &htab);
	// dfs(&adjtab, &htab);
	// send_ants();
	clear(&htab, &adjtab, &strg);
	// system("leaks lem-in");
	return (0);
}
