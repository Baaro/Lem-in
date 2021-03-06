/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:17:30 by vsokolog          #+#    #+#             */
/*   Updated: 2018/09/22 12:17:31 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	rooms_init(t_room **rooms, ssize_t size)
{
	ssize_t	i;

	i = -1;
	while (++i < size)
	{
		if (!(rooms[i] = (t_room *)ft_memalloc(sizeof(t_room))))
			errors_memory(CANT_ALLOCATE_MEM, "rooms_init");
	}
}

void	room_set(t_htab *htab, t_room *room, t_info *info)
{
	if (!(room->name = ft_strdup(info->room)))
		errors_memory(CANT_ALLOCATE_MEM, "room_set");
	room->name_len = ft_strlen(room->name);
	room->id = info->id_room;
	room->index = info->cnt_rooms;
	if (info->num_start_elem == info->cnt_rooms)
	{
		htab->start = ft_strdup(room->name);
		room->start = TRUE;
	}
	if (info->num_end_elem == info->cnt_rooms)
	{
		htab->end = ft_strdup(room->name);
		room->end = TRUE;
	}
}

bool	room_exists(t_htab *htab, char *name, unsigned long id)
{
	t_room	*tmp;

	if (htab->rooms[id] != NULL)
	{
		tmp = htab->rooms[id];
		while (tmp && tmp->name)
		{
			if (ft_strcmp(tmp->name, name) == 0)
				return (TRUE);
			tmp = tmp->next;
		}
	}
	return (FALSE);
}

void	room_create(t_htab *htab, t_info *info)
{
	t_room	*tmp;

	if (!htab->rooms[info->id_room]->name)
		room_set(htab, htab->rooms[info->id_room], info);
	else
	{
		if (!(tmp = (t_room *)malloc(sizeof(t_room))))
			errors_memory(CANT_ALLOCATE_MEM, "room_create");
		room_set(htab, tmp, info);
		tmp->next = htab->rooms[info->id_room]->next;
		htab->rooms[info->id_room]->next = tmp;
		if (!htab->rooms[info->id_room]->next->next)
			htab->rooms[info->id_room]->next->next = NULL;
	}
}
