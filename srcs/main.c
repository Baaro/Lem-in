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
	*map = (t_map){0, 0, 0, 0, {NULL, ft_strnew(0)}, {0, 0, 0}, 0, 0, {0, NULL}};
}

int				main(void)
{
	t_map	map;

	init_map(&map);
	valid_map(&map);
	make_path(&map, &map.path);
	// output_paths();
	// find_shortest_path_in_map(map, path);
	// show_shortest_path(map, path);
	return (0);
}
