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

static void		add_room_to_hashtab(t_table *tab, t_info *info)
{
	t_rooms	*tmp;

	if (!tab->rooms[info->id]->name)
	 	put_data(tab->rooms[info->id], info);
	else
	{
		if ((tmp = (t_rooms *)malloc(sizeof(t_rooms))) == NULL)
			errors_memory(CANT_ALLOCATE_MEM);
		tmp->nxt_hsh_room = tab->rooms[info->id]->nxt_hsh_room;
		tab->rooms[info->id]->nxt_hsh_room = tmp;
		put_data(tab->rooms[info->id]->nxt_hsh_room, info);
		tab->rooms[info->id]->nxt_hsh_room->nxt_hsh_room = NULL;
	}
}

bool    	 	room_exists(t_table *tab, t_info *info)
{
	t_rooms	*tmp;

	if (tab->rooms[info->id] != NULL)
	{
		tmp = tab->rooms[info->id];
		while (tmp->nxt_hsh_room != NULL)
		{
			if (ft_strcmp(tmp->name, info->room[NAME]) == 0)
				return (TRUE);
			tmp = tmp->nxt_hsh_room;
		}
	}
	return (FALSE);
}

int				get_id(t_table *tab, t_info *info)
{
    size_t  name_len;
	size_t	hash;
	size_t	i;

	i = 0;
	hash = 0;
    name_len = ft_strlen(info->room[NAME]);
	while (i < name_len)
	{
		hash += info->room[NAME][i++];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	return (hash % tab->size);
}

static char		**get_room(char *line)
{
	return (ft_strsplit(line, ' '));
}

static void		remember_start_end(t_table *tab, t_rooms *room)
{
	if (room->start == TRUE)
	{
		tab->start = ft_strdup(room->name);
		tab->start_len = room->name_len;	
	}
	else if (room->end == TRUE)
	{
		tab->end = ft_strdup(room->name);
		tab->end_len = room->name_len;
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
    // free(room);
}

void		    put_to_table(t_table *tab, t_info *info)
{
	info->cnt_rooms++;
	info->room = get_room(info->line);
	info->id = get_id(tab, info);
	// if (!room_exists(tab, info))
	// {
	// 	add_room_to_hashtab(tab, info);
	// 	if (tab->start == NULL || tab->end == NULL)
	// 		remember_start_end(tab, tab->rooms[info->id]);
        // free_room(info->room);
		// free(info->room[0]);
		// free(info->room[1]);		
		// free_all(3, info->room[NAME], info->room[X], info->room[Y]);
	// }
	// else
	// {
    //     free_room(info->room);        
	// // 	// free_all(3, room[NAME], room[X], room[Y]);
	// 	errors_rooms(TWO_ROOMS_AS_THE_SAME_NAME);
	// }
}
