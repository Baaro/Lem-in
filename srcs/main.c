/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:58:42 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/27 14:37:25 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		init_storage(t_storage *strg)
{
	ft_memset(strg, 0, sizeof(t_storage));
	strg->buff.data = ft_strnew(0);
}

static void		init_rooms(t_rooms **rooms, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
	{
		if (!(rooms[i] = (t_rooms *)malloc(sizeof(t_rooms))))
			errors_memory(CANT_ALLOCATE_MEM, "init_rooms");
		if (!(rooms[i] = ft_memset(rooms[i], 0, sizeof(t_rooms))))
			errors_memory(CANT_SETZERO, "init_rooms");
	}
}

void		init_hashtable(t_htab *htab, t_storage *strg)
{
	if (strg->info.amnt_of_rooms < 1)
		errors_rooms(NO_ROOMS);
	if (!(htab = memset(htab, 0, sizeof(t_htab))))
		errors_memory(CANT_SETZERO, "init_htab");
	if (!(htab->rooms = (t_rooms **)malloc(sizeof(t_rooms *)
					* strg->info.amnt_of_rooms)))
	{
		free(htab->rooms);
		errors_memory(CANT_ALLOCATE_MEM, "init_htab");
	}
	htab->size = strg->info.amnt_of_rooms;
	init_rooms(htab->rooms, htab->size);
}

int				main(void)
{
	t_storage		strg;
	t_htab			htab;
//	t_adjlists		adjlsts;

	init_storage(&strg);
	valid_data(&strg);

	init_hashtable(&htab, &strg);
	create_hashtable(&htab, &strg.buff, &strg.info);
//	init_adjlists(&adjlsts);
//	create_adjlists(&adjlsts, &htab, &strg);
	// use_bfs(&adj_lists);
	// free(strg.buffer.line);
	// free(strg.buffer.data);
	// use_dfs();
	// send_ants();
	return (0);
}
