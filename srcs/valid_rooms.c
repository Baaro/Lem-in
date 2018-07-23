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

// static bool		is_all_checked(const t_checks checks)
// {
// 	// if (map->checks.ants_check == UNCHECKED)
// 		// errors_ants();
// 	else if (map->checks.coom_check[START] == UNCHECKED)
// 		errors_commands();
// 	else if (map->checks.coom_check[END] == UNCHECKED)
// 		errors_commands();
// 	// else if (map->checks.coord_check == UNCHECKED);
// 		// return (UNCHECKED);
// 	return (CHECKED);
// }

// static intmax_t	count_ants(const char *data)
// {
// 	intmax_t	ants;

// 	ants = 0;
// 	if (*str == '-')
// 		errors_ants(ants_is_neg);
// 	else if (*str == 0)
// 		errors_ants(ants_is_zero);
// 	while (*str && ants < MAX_ANTS)
// 	{
// 		if (ft_isdigit(*str))
// 			ants = (ants * 10) + (*str) - '0';
// 		else
// 			errors_ants(wrong_value_ants);
// 		str++;
// 	}
// 	if (ants < MAX_ANTS)
// 		errors_ants(to_few_ants);
// 	return (ants);
// }

// static bool		check_amount_of_ants(t_map *map)
// {
// 	map->ants = count_ants(map->buffer.data);
// 	map->checks.ants = CHECKED;
// 	return (VALID);
// }

// static void		check_start_coomand(t_map *map)
// {
// 	if (map->checks.comm_find == NOTFOUND)
// 	{
// 		if (ft_strcmp(map->buffer.data, "##start") == 0)
// 			map->checks.comm_find == FOUND;
// 		else
// 			errors_commands(wrong_start_command);
// 	}
// 	// else if (map->checks.comm_find == FIND)
// 	// {
// 		// safe_start_room(map);
// 		// map->checks.comma_check[START] = CHECKED;
// 	// }
// }

bool			valid_rooms(t_map *map)
{
	if (!is_link(map->buffer.data))
	{
		// if (!is_comment(map))
		// {
			// else if (map->checks.ants_check == UNCHECKED)
				// check_amount_of_ants(map);
			// else if (map->checks.comm_check[START] == UNCHECKED)
				// check_start_command(map);
			// else if (map->checks.commands[END] == UNCHECKED)
				// check_end_command(map);
			// else if (map->checks.links == UNCHECKED)
				// check_rooms(map);
		// }
		// else
			// return (KEEP_READING);
		return (1);
	}
	// else if (is_all_checked(map->checks))
		// return (CHECKED);
	return (CAN_ADD_TO_HASHTABLE);
}
