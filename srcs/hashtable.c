/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 16:14:41 by vsokolog          #+#    #+#             */
/*   Updated: 2018/09/22 16:14:43 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

unsigned long	get_id(t_htab *ht, char *name, size_t name_len)
{
	size_t	hash;
	size_t	i;

	i = 0;
	hash = 0;
	while (i < name_len)
	{
		hash += name[i++];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash = hash % ht->size;
	return (hash == 0 ? 1 : hash);
}

t_room			*htab_get(t_htab *ht, unsigned long id, char *name)
{
	t_room	*tmp;

	tmp = ht->rooms[id];
	while (tmp && tmp->name)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void			htab_set(t_htab *ht, t_info *i)
{
	if (!room_exists(ht, i->room, i->id_room))
	{
		if (!coord_exists(ht, i->coord, i->id_coord))
		{
			room_create(ht, i);
			coord_create(ht, i);
		}
		else
			errors_rooms(TWO_ROOMS_HAVE_THE_SAME_COORDS);
	}
	else
		errors_rooms(TWO_ROOMS_HAVE_THE_SAME_NAME);
}

bool			start_equal_end(t_htab *ht)
{
	if (ht)
		if (ft_strcmp(ht->start, ht->end) == 0)
			return (TRUE);
	return (FALSE);
}

void			htab_create(t_htab *ht, t_buff *b, t_info *i)
{
	skip_amount_of_ants(b->data);
	while (TRUE)
	{
		i->line = get_line(b->data);
		if (!is_comment(i->line))
		{
			if (is_link(i->line))
				break ;
			if (is_room(i->line))
			{
				info_get_rooms(i, ht, b);
				htab_set(ht, i);
				info_clear_rooms(i);
			}
		}
		ft_strdel(&i->line);
	}
	if (start_equal_end(ht))
		errors_rooms(START_EQUAL_END);
}
