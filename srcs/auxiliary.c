/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:58:00 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/10 15:58:03 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				free_all(size_t numargs, ...)
{
	va_list	ap;
	void	**to_free;
	size_t	i;

	i = -1;
	va_start(ap, numargs);
	while (++i < numargs)
	{
		to_free = va_arg(ap, void **);
		free(to_free);
	}
	va_end(ap);
}

bool				read_data(t_map *map, char **data)
{
	char	*tmp;
	int		flag;

	tmp = NULL;
	flag = get_next_line(INPUT, data);
	if (flag > 0)
	{
		map->buffer.info = ft_strcat(ft_strjoincl(map->buffer.info, *data, 0),
														tmp = ft_strdup("\n"));
		free(tmp);
	}
	else if (flag == 0)
		return (FALSE);
	else if (flag < 0)
	{
		// free_all(2, &data, &map->buffer.info);
		errors_input(WRONG_INPUT);
	}
	return (TRUE);
}
