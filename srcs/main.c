/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:58:42 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/10 15:58:44 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		init_storage(t_storage *storage)
{
	*storage = (t_storage){{NULL, 0, 0, 0, 0, 0, 0}, {NULL, ft_strnew(0)},
								{0, 0, 0}, {NULL, NULL, 0, 0, 0, NULL}, 0, 0};
}

int				main(void)
{
	t_storage	storage;

	init_storage(&storage);
	valid_map(&storage);
	create_hashtable(&storage.buffer, &storage.table, &storage.info);
	system("leaks lem-in");	
	// create_adjlists();
	// use_bfs(&storage.adj_lists);
	// use_dfs();
	// send_ants();
	return (0);
}
