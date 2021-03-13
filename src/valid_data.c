/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:28:28 by vsokolog          #+#    #+#             */
/*   Updated: 2018/09/22 13:28:30 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static bool			commands_is_checked(const t_checks *c)
{
	if (c->end_check == UNCHECKED)
		errors_commands(NO_END_COMMAND);
	else if (c->start_check == UNCHECKED)
		errors_commands(NO_START_COMMAND);
	return (TRUE);
}

static t_controller	valid_line(t_storage *s, t_checks *c, char *line)
{
	if (!is_comment(line))
	{
		if (valid_ants(c, line, &s->info->ants))
			return (READ);
		if (valid_cmmnds(s, c, line))
			return (READ);
		if (is_link(line) && commands_is_checked(c))
			return (STOP_READ);
		if (valid_room(line))
			return (VALID_ROOM);
	}
	return (READ);
}

void				valid_data(t_storage *s)
{
	s->contrllr = READ;
	while (TRUE)
	{
		if (s->contrllr == READ)
		{
			if (read_line(s->buff, &s->buff->line))
				s->contrllr = GO_VALID;
			else
				errors_links(THERE_ARE_NO_LINKS);
		}
		if (s->contrllr == GO_VALID)
		{
			s->contrllr = valid_line(s, &s->c, s->buff->line);
			save_data(&s->buff->data, s->buff->line);
			if (s->contrllr == VALID_ROOM)
			{
				s->info->amnt_of_rooms++;
				s->contrllr = READ;
			}
			else if (s->contrllr == STOP_READ)
				break ;
		}
	}
}
