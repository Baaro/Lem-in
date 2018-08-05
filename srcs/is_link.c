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

static bool	valid_first_name_room(char **data)
{
	while (**data && ft_isprint(**data) && **data != '-')
		(*data)++;
	if (**data == '-')
	{
		(*data)++;
		return (TRUE);
	}
	return (FALSE);
}

static bool	valid_second_name_room(char *data)
{
	while (*data)
	{
		if (!ft_isprint(*data))
			return (FALSE);
		data++;
	}
	return (TRUE);
}

bool		is_link(char *data)
{
	if (valid_first_name_room(&data))
		if (valid_second_name_room(data))
			return (TRUE);
	return (FALSE);
}
