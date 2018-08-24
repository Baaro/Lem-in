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

static bool	valid_first_name_room(char **line)
{
	while (**line && ft_isprint(**line) && **line != '-')
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
		if (!ft_isprint(*line))
			return (FALSE);
		line++;
	}
	return (TRUE);
}

bool		is_link(char *line)
{
	if (valid_first_name_room(&line))
		if (valid_second_name_room(line))
			return (TRUE);
	return (FALSE);
}
