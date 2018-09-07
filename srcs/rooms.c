#include "lem_in.h"

void	rooms_clear(t_room **rooms, size_t size)
{
	t_room		*tmp;
	size_t		i;

	i = -1;
	while (++i < size)
	{
		tmp = rooms[i];
		while (tmp)
		{
			tmp = rooms[i]->next;
			if (rooms[i]->name)
				free(rooms[i]->name);
			free(rooms[i]);
			rooms[i] = tmp;
		}
	}
	free(rooms);
}

void	rooms_init(t_room **rooms, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
	{
		if (!(rooms[i] = (t_room *)ft_memalloc(sizeof(t_room))))
			errors_memory(CANT_ALLOCATE_MEM, "rooms_init");
		// if (!(rooms[i] = ft_memset(rooms[i], 0, sizeof(t_room))))
		// 	errors_memory(CANT_SETZERO, "rooms_init");
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

bool	room_exists(t_htab *htab, char *name, unsigned long	id)
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