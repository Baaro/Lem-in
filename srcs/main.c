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
	create_hashtable(&htab, &strg.buff, &strg.info);

	init_adjlists(&adjlsts, &htab);
	create_adjlists(&adjlsts, &htab, &strg.buff, &strg.info);

	printf("HASHTABLE\n");
	int i = 0;
	while (++i <= (int)htab.size)
		print_htab(&htab, i);
	printf("\n");

 	printf("ADJLISTS\n");
 	ssize_t j = 0;
	while (++j <= (ssize_t)adjlsts.size)
		print_adjlists(&adjlsts, j);

	system("leaks lem-in");
	// use_bfs(&adj_lists);
	// free(strg.buffer.line);
	// free(strg.buffer.data);
	// use_dfs();
	// send_ants();
	return (0);
}
