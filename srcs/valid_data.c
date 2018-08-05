/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:47:19 by vsokolog          #+#    #+#             */
/*   Updated: 2018/07/23 16:47:20 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static bool		is_end_checked(const t_checks *checks)
{
	if (checks->comm_check[END] == UNCHECKED)
		errors_commands(no_end_command);
	return (TRUE);
}

static bool		is_comment(char *data)
{
	if (*data == '#' && !is_start_command(data) && !is_end_command(data))
		return (TRUE);
	return (FALSE);
}

t_flags			valid_data(t_map *map, t_checks *checks)
{
	if (!is_comment(map->buffer.data))
	{
		if (check_ants(checks, map->buffer.data, &map->ants))
			return (read_next_data);
		if (check_start_command(map, checks, map->buffer.data))
			return (read_next_data);
		if (check_end_command(map, checks, map->buffer.data))
			return (read_next_data);
		if (is_link(map->buffer.data) && is_end_checked(checks))
			return (end_read_data);
		if (room_is_valid(map->buffer.data))
			return (add_elem_to_hashtable);
	}
	return (read_next_data);
}
