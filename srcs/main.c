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

static void		init_map(t_map *map)
{
	// *map = (t_map){0, 0, 0, 0, {NULL, ft_strnew(0)}, {0, 0, 0}, 0, 0, {0, NULL}}
	*map = (t_map){0, 0, 0, 0, {NULL, ft_strnew(0)},
								{0, 0, 0}, {NULL, NULL, 0, 0, 0, NULL}, 0, 0};
}

int				main(void)
{
	t_map	map;

	init_map(&map);
	valid_map(&map);
	make_adj_lists(&map, &map.adj_lists);
	use_bfs(&map.adj_lists);
	// use_dfs();
	// send_ants();
	return (0);
}
