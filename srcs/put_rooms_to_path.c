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
		new_room->start = 1;
	else
		new_room->start = 0;
	if (map->num_end_elem == count_room)
		new_room->end = 1;
	else
		new_room->end = 0;
	new_room->next_room = NULL;
	return (new_room);
}

bool     room_is_exist(t_path *path, int id, char *name)
{
	if (path->rooms[id] != NULL)
		if (path->rooms[id]->name != NULL)
			if (ft_strcmp(path->rooms[id]->name, name) == 0)
				return (TRUE);
	return (FALSE);
}

int      get_id(t_path *path, char *name, size_t name_len)
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
	return (hash % path->size);
}

static char     **get_data_of_room(char *data)
{
	return (ft_strsplit(data, ' '));
}

void		    put_room_to_path(t_map *map, t_path *path, char *data, size_t *count_rooms)
{
	char	**room;
	int		id;

	room = get_data_of_room(data);
	id = get_id(path, room[NAME], ft_strlen(room[NAME]));
	(*count_rooms)++;
	if (!room_is_exist(path, id, room[NAME]))
	{
		path->rooms[id] = make_room(map, id, room[NAME], *count_rooms);
		free_all(3, room[NAME], room[X], room[Y]);		
	}
	else
	{
		free_all(3, room[NAME], room[X], room[Y]);
		errors_rooms(TWO_ROOMS_AS_THE_SAME_NAME);
	}
}
