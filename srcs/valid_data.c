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

static bool		is_all_checked(const t_checks checks)
{
	// if (map->checks.ants_check == UNCHECKED)
		// errors_ants();
	if (checks.comm_check[START] == UNCHECKED)
		errors_commands(no_start_command);
	else if (checks.comm_check[END] == UNCHECKED)
		errors_commands(no_end_command);
	// else if (map->checks.coord_check == UNCHECKED);
		// return (UNCHECKED);
	return (CHECKED);
}

static void		check_data(t_map *map)
{
	if (map->checks.ants_check == UNCHECKED)
		check_amount_of_ants(map->buffer.data, &map->checks);
	// else if (map->checks.comm_check[START] == UNCHECKED)
	// 	check_start_command(map->buffer.data, &map->checks);
	// else if (map->checks.commands[END] == UNCHECKED)
	// 	check_end_command(map->buffer.data, &map->checks);
	// else if (map->checks.links == UNCHECKED)
	// 	check_rooms(map->buffer.data, &map->checks);
}

static bool		is_comment(char *data)
{
	if (*data == '#' && !is_start_command(data) && !is_end_command(data))
		return (TRUE);
	return (FALSE);
}

// bool		is_link(char *data)
// {
// 	if (valid_first_name_room(&data))
// 		if (valid_second_name_room(data))
// 			return (TRUE);
// 	return (FALSE);
// }

short			valid_data(t_map *map)
{
	if (!is_link(map->buffer.data))
	{
		if (!is_comment(map->buffer.data))
			printf("is work\n");
			// check_data(map);
		return (READ_DATA);
	}
	// else if (is_all_checked(map->checks))
	// 	return (END_READ);
	return (CAN_ADD_TO_HASHTABLE);
}
