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

static intmax_t	count_ants(char *line)
{
	intmax_t	ants;

	ants = 0;
	if (*line == '-')
		errors_ants(ANTS_IS_NEG);
	if (*line == '0')
		errors_ants(ANTS_IS_ZERO);
	while (*line)
	{
		if (ants > INT_MAX)
			errors_ants(TOO_FEW_ANTS);
		if (ft_isdigit(*line))
			ants = (ants * 10) + (*line) - '0';
		else
			errors_ants(WRONG_VALUE_OF_ANTS);
		line++;
	}
	return (ants);
}

bool			valid_ants(t_checks *c, char *line, intmax_t *ants)
{
	if (c->ants_check == UNCHECKED)
	{
		*ants = count_ants(line);
		c->ants_check = CHECKED;
		return (TRUE);
	}
	return (FALSE);
}
