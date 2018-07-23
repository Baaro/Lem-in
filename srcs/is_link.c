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

static bool	valid_first_room(char **data)
{
	while (**data && ft_isalnum(**data))
		(*data)++;
	if (**data == '-')
	{
		(*data)++;
		return (VALID);
	}
	return (INVALID);
}

static bool	valid_second_room(char *data)
{
	while (*data)
	{
		if (!ft_isalnum(*data))
			return (INVALID);
		data++;
	}
	return (VALID);
}

bool		is_link(const char *data)
{
	char	*tmp_data;

	ft_printf("%s\n", (char *)data);
	tmp_data = (char *)data;
	if (valid_first_room(&tmp_data))
		if (valid_second_room(tmp_data))
			return (TRUE);
	return (FALSE);
}