/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:32:25 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/29 13:35:56 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		put_data(t_room *room, t_info *info)
{
	if ((room->name = ft_strdup(info->room[NAME])) == NULL)
		return ;
	room->name_len = ft_strlen(info->room[NAME]);
	room->id = info->id;
	room->index = info->cnt_rooms;
	if (info->num_start_elem == info->cnt_rooms)
		room->start = TRUE;
	if (info->num_end_elem == info->cnt_rooms)
		room->end = TRUE;
}

static char		**get_room(char *line)
{
	return (ft_strsplit(line, ' '));
}

static void		remember_start_end(t_htab *htab, t_room *room)
{
	if (room->start == TRUE)
	{
		htab->start = ft_strdup(room->name);
		htab->start_len = room->name_len;
	}
	else if (room->end == TRUE)
	{
		htab->end = ft_strdup(room->name);
		htab->end_len = room->name_len;
	}
}

bool			room_exists(t_htab *htab, char *name)
{
	t_room			*tmp;
	unsigned long	id;

	id = get_id(htab, name, ft_strlen(name));
	if (htab->rooms[id] != NULL)
	{
		tmp = htab->rooms[id];
		while (tmp->next != NULL)
		{
			if (ft_strcmp(tmp->name, name) == 0)
				return (TRUE);
			tmp = tmp->next;
		}
	}
	return (FALSE);
}

bool			coord_exists(t_htab *htab, char *x_y)
{
	t_coord			*tmp;
	unsigned long	id;

	id = get_id(htab, x_y, ft_strlen(x_y));
	if (htab->coords[id] != NULL)
	{
		tmp = htab->coords[id];
		while (tmp->next != NULL)
		{
			if (ft_strcmp(tmp->x_y, x_y) == 0)
				return (TRUE);
			tmp = tmp->next;
		}
	}
	return (FALSE);
}

static void		put(t_htab *htab, t_info *info)
{
	t_room	*tmp;

	if (!htab->rooms[info->id]->name)
	 	put_data(htab->rooms[info->id], info);
	else
	{
		if ((tmp = (t_room *)malloc(sizeof(t_room))) == NULL)
			errors_memory(CANT_ALLOCATE_MEM, "add_room_to_hashtable");
		tmp->next = htab->rooms[info->id]->next;
		htab->rooms[info->id]->next = tmp;
		put_data(htab->rooms[info->id]->next, info);
		htab->rooms[info->id]->next->next = NULL;
	}
}

unsigned long	get_id(t_htab *htab, char *name, size_t name_len)
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
	hash = hash % htab->size;
	return (hash == 0 ? hash + 1 : hash);
}

void		    hashtable_put(t_htab *htab, t_buff *buff, t_info *info)
{
	info->cnt_rooms++;
	info->room = get_room(buff->line);
	if (!room_exists(htab, info->room[NAME]))
	// && !coord_exists(htab, ft_strcat(info->room[X], info->room[Y])))
	{
		put(htab, info);
		if (htab->start == NULL || htab->end == NULL)
			remember_start_end(htab, htab->rooms[info->id]);
        free_room(info->room);		
		free(info->room);
	}
	else // just ignore this IT'S DONT WORK!
	{
		printf("HELL\n");
		free_room(info->room);
		free(info->room);
		errors_rooms(TWO_ROOMS_AS_THE_SAME_NAME);
	}
}
