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
	return (c == ' ' || c == '\t' || c == '\n');
}

static bool	valid_link(char *line)
{
	size_t	delim;

	delim = 0;
	while (*line && ft_isprint(*line))
	{
		if ((*line) == '-')
			delim++;
		if (delim > 1 || is_delim(*line))
			return (FALSE);
		line++;
	}
	return (delim == 1 ? TRUE : FALSE);
}

bool		is_link(const char *line)
{
	char	*tmp;

	tmp = (char *)line;
	if (valid_link(tmp))
		return (TRUE);
	return (FALSE);
}
