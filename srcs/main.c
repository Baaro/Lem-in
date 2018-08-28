/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:58:42 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/28 17:21:22 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init_storage(t_storage *strg)
{
	ft_memset(strg, 0, sizeof(t_storage));
	strg->buff.data = ft_strnew(0);
}

static void	init_elems(t_adjelem **elems, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
	{
		if (!(elems[i] = (t_adjelem *)malloc(sizeof(t_adjelem))))
			errors_memory(CANT_ALLOCATE_MEM, "init_elems");
		if (!(elems[i] = ft_memset(elems[i], 0, sizeof(t_adjelem))))
			errors_memory(CANT_SETZERO, "init_elems");
	}
}

static void	init_rooms(t_room **rooms, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
	{
		if (!(rooms[i] = (t_room *)malloc(sizeof(t_room))))
			errors_memory(CANT_ALLOCATE_MEM, "init_rooms");
		if (!(rooms[i] = ft_memset(rooms[i], 0, sizeof(t_room))))
			errors_memory(CANT_SETZERO, "init_rooms");
	}
}

void		init_hashtable(t_htab *htab, t_storage *strg)
{
	if (strg->info.amnt_of_rooms < 1)
		errors_rooms(NO_ROOMS);
	if (!(htab = ft_memset(htab, 0, sizeof(t_htab))))
		errors_memory(CANT_SETZERO, "init_htab");
	if (!(htab->rooms = (t_room **)malloc(sizeof(t_room *)
					* strg->info.amnt_of_rooms)))
	{
		free(htab->rooms);
		errors_memory(CANT_ALLOCATE_MEM, "init_htab");
	}
	htab->size = strg->info.amnt_of_rooms;
	init_rooms(htab->rooms, htab->size);
}

void		init_adjlists(t_adjlists *adjlsts, t_htab *htab)
{
	if (!(adjlsts = ft_memset(adjlsts, 0, sizeof(t_adjlists))))
	   errors_memory(CANT_SETZERO, "init_adjlists");
	adjlsts->size = htab->size;
    if (!(adjlsts->elems = (t_adjelem **)malloc(sizeof(t_adjelem *)
					* adjlsts->size)))
         errors_memory(CANT_ALLOCATE_MEM, "init_adjlists");
	init_elems(adjlsts->elems, adjlsts->size);
}

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
//	system("leaks lem-in");
	create_adjlists(&adjlsts, &htab, &strg.buff);
	// use_bfs(&adj_lists);
	// free(strg.buffer.line);
	// free(strg.buffer.data);
	// use_dfs();
	// send_ants();
	return (0);
}
