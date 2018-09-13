/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:49:35 by vsokolog          #+#    #+#             */
/*   Updated: 2018/07/23 16:49:40 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static bool	is_delim(char c)
{
	return  (c == ' ' || c == '\t' || c == '\n');
}

static bool	valid_first_name_room(char **line)
{
	while (**line && ft_isprint(**line) && **line != '-' && !is_delim(**line))
		(*line)++;
	if (**line == '-')
	{
		(*line)++;
		return (TRUE);
	}
	return (FALSE);
}

static bool	valid_second_name_room(char *line)
{
	while (*line)
	{
		if (!ft_isprint(*line) || is_delim(*line))
			return (FALSE);
		line++;
	}
	return (TRUE);
}

bool		is_link(const char *line)
{
	char	*tmp;

	tmp = (char *)line;
	if (valid_first_name_room(&tmp))
		if (valid_second_name_room(tmp))
			return (TRUE);
	return (FALSE);
}
