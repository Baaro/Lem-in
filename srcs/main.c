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

int			main(void)
{
	t_storage		strg;
	t_htab			htab;
	t_adjlists		adjlsts;
	
	init_storage(&strg);
	valid_data(&strg);

	init_hashtable(&htab, &strg);
	hashtable_create(&htab, &strg.buff, &strg.info);

	// init_adjlists(&adjlsts, &htab);
	// adjlists_create(&adjlsts, &htab, &strg.buff, &strg.info);

	printf("HASHTABLE\n");
	size_t i = 0;
	while (++i <= (size_t)htab.size)
		print_htab(&htab, i);
	printf("\n");

 	// printf("ADJLISTS\n");
 	// size_t j = 0;
	// while (++j <= (size_t)adjlsts.size)
	// 	print_adjlists(&adjlsts, j);

	// use_bfs(&adjlsts, &htab);
	// free(strg.buffer.line);
	// free(strg.buffer.data);
	// use_dfs();
	// send_ants();
	// system("leaks lem-in");
	return (0);
}
