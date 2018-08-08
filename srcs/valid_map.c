/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:47:19 by vsokolog          #+#    #+#             */
/*   Updated: 2018/07/23 16:47:20 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static bool				end_is_checked(const t_checks *checks)
{
	if (checks->start_check == UNCHECKED)
		errors_commands(NO_END_COMMAND);
	return (TRUE);
}

static t_controller		valid_data(t_map *map, t_checks *checks, char *data)
{
	if (!is_comment(data))
	{
		if (valid_ants(checks, data, &map->ants))
			return (READ_DATA);
		if (valid_commands(map, checks, data))
			return (READ_DATA);
		if (is_link(data) && end_is_checked(checks))
			return (STOP_READ_DATA);
		if (valid_room(data))
			return (ADD_ELEM_TO_TABLE);
	}
	return (READ_DATA);
}

static void			free_strings(char **one, char **two)
{
	if (*one)
		ft_strdel(one);
	if (*two)
		ft_strdel(two);
}

char				*read_data(t_map *map, char *data)
{
	char	*tmp;

	tmp = NULL;
	if (get_next_line(INPUT, &data) > 0)
	{
		map->buffer.info = ft_strcat(ft_strjoincl(map->buffer.info, data, 0),
														tmp = ft_strdup("\n"));
		free(tmp);
	}
	else
	{
		free_strings(&data, &map->buffer.info);
		errors_input(WRONG_INPUT);
	}
	return (data);
}

void					valid_map(t_map *map)
{
	map->controller = READ_DATA;
	while (TRUE)
	{
		if (map->controller == READ_DATA)
		{
			map->buffer.data = read_data(map, map->buffer.data);
			map->controller = GO_VALID;
		}
		if (map->controller == GO_VALID)
		{
			map->controller = valid_data(map, &map->checks, map->buffer.data);
			if (map->controller == ADD_ELEM_TO_TABLE)
			{
				map->amount_of_rooms++;
				map->controller = READ_DATA;
			}
			else if (map->controller == STOP_READ_DATA)
				break ;
		}
	}
}