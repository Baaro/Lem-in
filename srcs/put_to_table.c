#include "lem_in.h"

static void		put_data(t_rooms *room, t_info *info)
{
	if ((room->name = ft_strdup(info->room[NAME])) == NULL)
		return ;
	room->name_len = ft_strlen(info->room[NAME]);
	room->id = info->id;
	room->visited = 0;
	room->in_queue = 0;
	room->start = 0;
	room->end = 0;
	if (info->num_start_elem == info->cnt_rooms)
		room->start = TRUE;
	if (info->num_end_elem == info->cnt_rooms)
		room->end = TRUE;
}

static void		add_room_to_hashtable(t_htab *htab, t_info *info)
{
	t_rooms	*tmp;

	if (!htab->rooms[info->id]->name)
	 	put_data(htab->rooms[info->id], info);
	else
	{
		if ((tmp = (t_rooms *)malloc(sizeof(t_rooms))) == NULL)
			errors_memory(CANT_ALLOCATE_MEM, "add_room_to_hashtable");
		tmp->next = htab->rooms[info->id]->next;
		htab->rooms[info->id]->next = tmp;
		put_data(htab->rooms[info->id]->next, info);
		htab->rooms[info->id]->next->next = NULL;
	}
}

bool    	 	room_exists(t_htab *htab, t_info *info)
{
	t_rooms	*tmp;

	if (htab->rooms[info->id] != NULL)
	{
		tmp = htab->rooms[info->id];
		while (tmp->next != NULL)
		{
			if (ft_strcmp(tmp->name, info->room[NAME]) == 0)
				return (TRUE);
			tmp = tmp->next;
		}
	}
	return (FALSE);
}

int				get_id(t_htab *htab, char *room)
{
    size_t  name_len;
	size_t	hash;
	size_t	i;

	i = 0;
	hash = 0;
    name_len = ft_strlen(room);
	// printf("room: %s\n", info->room[NAME]);
	while (i < name_len)
	{
		hash += room[i++];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	return (hash % htab->size);
}

static char		**get_room(char *line)
{
	return (ft_strsplit(line, ' '));
}

static void		remember_start_end(t_htab *htab, t_rooms *room)
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

static void     free_room(char **room)
{
    if (!room)
        return ;
    else
    {
        while (*room)
        {
            free(*room);
            room++;
        }
    }
}

void		    put_to_hashtable(t_htab *htab, t_buff *buff, t_info *info)
{
	info->cnt_rooms++;
	info->room = get_room(buff->line);
	info->id = get_id(htab, info->room[NAME]);
	if (!room_exists(htab, info))
	{
		add_room_to_hashtable(htab, info);
		if (htab->start == NULL || htab->end == NULL)
			remember_start_end(htab, htab->rooms[info->id]);
        free_room(info->room);		
		free(info->room);
	}
	else
	{
		free_room(info->room);
		free(info->room);
		errors_rooms(TWO_ROOMS_AS_THE_SAME_NAME);
	}
}
