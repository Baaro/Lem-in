#include "lem_in.h"

static t_rooms 	*make_room(t_map *map, int id, char *name, size_t count_room)
{
	t_rooms	*new_room;

	if ((new_room = (t_rooms *)malloc(sizeof(t_rooms))) == NULL)
		return (NULL);
	if ((new_room->name = ft_strdup(name)) == NULL)
		return (NULL);
	new_room->name_len = ft_strlen(new_room->name);
	new_room->id = id;
	new_room->visited = 0;
	if (map->num_start_elem == count_room)
		new_room->start = TRUE;
	if (map->num_end_elem == count_room)
		new_room->end = TRUE;
	new_room->next_room = NULL;
	return (new_room);
}

bool     room_exists(t_adj_lists *adj_lists, int id, char *name)
{
	if (adj_lists->rooms[id] != NULL)
		if (adj_lists->rooms[id]->name != NULL)
			if (ft_strcmp(adj_lists->rooms[id]->name, name) == 0)
				return (TRUE);
	return (FALSE);
}

int      get_id(t_adj_lists *adj_lists, char *name, size_t name_len)
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
	return (hash % adj_lists->size);
}

static char     **get_data_of_room(char *data)
{
	return (ft_strsplit(data, ' '));
}

static void		save_name_of_start_end_rooms(t_adj_lists *adj_lists, t_rooms *room, int id)
{
	if (room->start)
	{
		adj_lists->start = ft_strdup(room->name);
		adj_lists->start_len = room->name_len;	
	}
	else if (room->end)
	{
		adj_lists->end = ft_strdup(room->name);	
		adj_lists->end_len = room->name_len;
	}
}

void		    put_room_to_adj_lists(t_map *map, t_adj_lists *adj_lists, char *data, size_t *cnt_rooms)
{
	char	**room;
	int		id;

	room = get_data_of_room(data);
	id = get_id(adj_lists, room[NAME], ft_strlen(room[NAME]));
	(*cnt_rooms)++;
	if (!room_exists(adj_lists, id, room[NAME]))
	{
		adj_lists->rooms[id] = make_room(map, id, room[NAME], *cnt_rooms);
		if (adj_lists->start == NULL || adj_lists->end == NULL)
			save_name_of_start_end_rooms(adj_lists, adj_lists->rooms[id], id);					
		free_all(3, room[NAME], room[X], room[Y]);		
	}
	else
	{
		free_all(3, room[NAME], room[X], room[Y]);
		errors_rooms(TWO_ROOMS_AS_THE_SAME_NAME);
	}	
}
