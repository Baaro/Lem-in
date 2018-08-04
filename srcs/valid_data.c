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
	return (CHECKED);
}

static bool		is_comment(char *data)
{
	if (*data == '#' && !is_start_command(data) && !is_end_command(data))
		return (TRUE);
	return (FALSE);
}

void			valid_data(t_map *map, t_flags *flag, t_checks *checks)
{
	if (!is_comment(map->buffer.data))
	{
		if (checks->ants_check == UNCHECKED)
			check_ants(checks, map->buffer.data, &map->ants);
		else if (checks->comm_check[START] == UNCHECKED)
			check_start_command(map->buffer.data, &map->checks);
		else if (checks->comm_check[END] == UNCHECKED)
			check_end_command(map->buffer.data, checks);
		else if (room_is_valid(map->buffer.data)			
			*flag = add_elem_to_hashtable;
		*flag = read_next_data;
		if (is_link(map->buffer.data) && is_end_checked(checks))
			*flag = end_read_data;
	}
	else
		*flag = read_next_data;
}
