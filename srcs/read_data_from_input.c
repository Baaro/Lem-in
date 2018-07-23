/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data_from_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:47:07 by vsokolog          #+#    #+#             */
/*   Updated: 2018/07/23 16:47:08 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool 	read_data_from_input(t_map *map)
{
	if (get_next_line(INPUT, &map->buffer.data) > 0)
	{
		map->buffer.info = ft_strjoincl(map->buffer.info, map->buffer.data, 0);
		return (TRUE);
	}
	return (FALSE);
}