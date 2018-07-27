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
#include <stdio.h>

// static void	check_room(const char *data)
// {
	// 
// }

static bool		is_end_checked(const t_checks checks)
{
	if (checks.comm_check[END] == UNCHECKED)
		errors_commands(no_end_command);
	return (CHECKED);
}

static void		check_data(t_map *map, t_flags *flag)
{
	if (map->checks.ants_check == UNCHECKED)
	{
		check_ants(&map->checks, map->buffer.data, &map->ants);
		*flag = read_next_data;
		printf("PREPARE FOR RUN, ANTS ARE READY\n");
	}
	else if (map->checks.comm_check[START] == UNCHECKED)
	{
		check_start_command(map->buffer.data, &map->checks);
		*flag = read_next_data;
		printf("is a start command baby\n");
	}
	else if (map->checks.comm_check[END] == UNCHECKED)
	{
		check_end_command(map->buffer.data, &map->checks);
		*flag = read_next_data;
		printf("is an end command baby\n");
	}
	else if (is_link(map->buffer.data) && is_end_checked(map->checks))
	{
		*flag = end_read_data;
		printf("THE END\n");
	}
	// else if (check_room(map->buffer.data))
		// *flag = add_elem_to_hashtable;
}

static bool		is_comment(char *data)
{
	if (*data == '#' && !is_start_command(data) && !is_end_command(data))
		return (TRUE);
	return (FALSE);
}

void			valid_data(t_map *map, t_flags *flag)
{
	if (!is_comment(map->buffer.data))
		check_data(map, flag);
	else
		*flag = read_next_data;
}
