/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:58:22 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/10 15:58:23 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static size_t	remember_num_of_command(size_t current_num)
{
	return (current_num);
}

static bool		check_end_command(t_storage *storage, t_checks *checks, const char *data)
{
	if (checks->end_check == UNCHECKED && is_end_command(data))
	{
		if (checks->start_check  == CHECKED)
		{
			checks->end_check = CHECKED;
			storage->info.num_end_elem = remember_num_of_command(
											storage->info.amnt_of_rooms + 1);
			return (TRUE);
		}
		else
			errors_commands(NO_START_COMMAND);
	}
	return (FALSE);
}

static bool		check_start_command(t_storage *storage, t_checks *checks, const char *data)
{
	if (checks->start_check == UNCHECKED && is_start_command(data))
	{
		checks->start_check = CHECKED;
		storage->info.num_start_elem = remember_num_of_command(
										storage->info.amnt_of_rooms + 1);
		return (TRUE);
	}
	return (FALSE);
}

bool			valid_commands(t_storage *storage, t_checks *checks, char *data)
{
	if (check_start_command(storage, checks, data))
		return (TRUE);
	if (check_end_command(storage, checks, data))
		return (TRUE);
	return (FALSE);
}
