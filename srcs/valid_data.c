/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_strg.c                                       :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:47:19 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/27 14:04:28 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static bool				end_is_checked(const t_checks *chcks)
{
	if (chcks->start_check == UNCHECKED)
		errors_commands(NO_END_COMMAND);
	return (TRUE);
}

static t_controller		valid_line(t_storage *strg, t_checks *chcks, char *line)
{
	if (!is_comment(line))
	{
		if (valid_ants(chcks, line, &strg->info.ants))
			return (READ);
		if (valid_commands(strg, chcks, line))
			return (READ);
		if (is_link(line) && end_is_checked(chcks))
			return (STOP_READ);
		if (valid_room(line))
			return (VALID_ROOM);
	}
	return (READ);
}

void					valid_data(t_storage *strg)
{
	strg->contrllr = READ;
	while (TRUE)
	{
		if (strg->contrllr == READ)
		{
			if (read_line(strg, &strg->buff.line))
				strg->contrllr = GO_VALID;
		}
		if (strg->contrllr == GO_VALID)
		{
			strg->contrllr = valid_line(strg, &strg->chcks, strg->buff.line);
			if (strg->contrllr == VALID_ROOM)
			{
				strg->info.amnt_of_rooms++;
				strg->contrllr = READ;
			}
			else if (strg->contrllr == STOP_READ)
			{
				free(strg->buff.line);
				break ;
			}
		}
	}
}
