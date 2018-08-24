/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_storage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:47:19 by vsokolog          #+#    #+#             */
/*   Updated: 2018/07/23 16:47:20 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static bool				end_is_checked(const t_checks *checks)
{
	if (checks->start_check == UNCHECKED)
		errors_commands(NO_END_COMMAND);
	return (TRUE);
}

static t_controller		valid_data(t_storage *storage, t_checks *checks, char *data)
{
	if (!is_comment(data))
	{
		if (valid_ants(checks, data, &storage->info.ants))
			return (READ);
		if (valid_commands(storage, checks, data))
			return (READ);
		if (is_link(data) && end_is_checked(checks))
			return (STOP_READ);
		if (valid_room(data))
			return (VALID_ROOM);
	}
	return (READ);
}

void					valid_map(t_storage *storage)
{
	storage->controller = READ;
	while (TRUE)
	{
		if (storage->controller == READ)
		{
			if (read_line(storage, &storage->buffer.line))
				storage->controller = GO_VALID;
		}
		if (storage->controller == GO_VALID)
		{
			storage->controller = valid_data(storage, &storage->checks, storage->buffer.line);
			if (storage->controller == VALID_ROOM)
			{
				storage->info.amnt_of_rooms++;
				storage->controller = READ;
			}
			else if (storage->controller == STOP_READ)
				break ;
		}
	}
}