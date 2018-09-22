/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:58:22 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/27 14:02:28 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static size_t	remember_num_of_command(size_t current_num)
{
	return (current_num);
}

static bool		chck_e_cmmnd(t_storage *s, t_checks *c, const char *line)
{
	if (c->end_check == CHECKED && is_end_command(line))
		errors_commands(TWO_END_COMMANDS);
	if (c->end_check == UNCHECKED && is_end_command(line))
	{
		c->end_check = CHECKED;
		s->info->num_end_elem = remember_num_of_command(
											s->info->amnt_of_rooms + 1);
		return (TRUE);
	}
	return (FALSE);
}

static bool		chck_s_cmmnd(t_storage *s, t_checks *c, const char *line)
{
	if (c->start_check == CHECKED && is_start_command(line))
		errors_commands(TWO_START_COMMANDS);
	if (c->start_check == UNCHECKED && is_start_command(line))
	{
		c->start_check = CHECKED;
		s->info->num_start_elem = remember_num_of_command(
										s->info->amnt_of_rooms + 1);
		return (TRUE);
	}
	return (FALSE);
}

bool			valid_cmmnds(t_storage *s, t_checks *c, char *line)
{
	if (chck_s_cmmnd(s, c, line))
		return (TRUE);
	if (chck_e_cmmnd(s, c, line))
		return (TRUE);
	return (FALSE);
}
