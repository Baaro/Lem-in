/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:58:32 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/10 15:58:33 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static intmax_t count_ants(const char *line)
{
	intmax_t	ants;

	ants = 0;
	if (*line == '-')
		errors_ants(ANTS_IS_NEG);
	else if (*line == 0)
		errors_ants(ANTS_IS_ZERO);
	while (*line && ants < MAX_ANTS)
	{
		if (ft_isdigit(*line))
			ants = (ants * 10) + (*line) - '0';
		else
			errors_ants(WRONG_VALUE_OF_ANTS);
		line++;
	}
	if (ants > MAX_ANTS)
		errors_ants(TOO_FEW_ANTS);
	else if (ants == 0)
		errors_ants(ANTS_IS_ZERO);
	return (ants);
}

bool		valid_ants(t_checks *checks, const char *line, intmax_t *ants)
{
	if (checks->ants_check == UNCHECKED)
	{
		*ants = count_ants(line);
		checks->ants_check = CHECKED;
		return (TRUE);
	}
	return (FALSE);
}
