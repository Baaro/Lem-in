#include "lem_in.h"

static char		**get_rooms(char *data)
{
	return (ft_strsplit(data, '-'));
}

static void		add_elem(t_rooms *room, t_rooms *new_room)
{
	if (!room || !new_room)
		return ;
	while (room->next_room != NULL)
		room = room->next_room;
	room->next_room = new_room;
	new_room->next_room = NULL;
}

static t_rooms	*new_elem(const t_rooms *room)
{
	t_rooms	*new_room;

	if ((new_room = (t_rooms *)malloc(sizeof(t_rooms))) == NULL)
		return (NULL);
	new_room->name = ft_strdup(room->name);
	new_room->name_len = room->name_len;
	new_room->id = room->id;
	new_room->visited = room->visited;
	new_room->start = room->start;
	new_room->end = room->end;
	new_room->next_room = NULL;
	return (new_room);
}

static void		make_links(t_path *path, char **rooms)
{
	int	id_first;
	int	id_second;

	id_first = get_id(path, rooms[FIRST], ft_strlen(rooms[FIRST]));
	id_second = get_id(path, rooms[SECOND], ft_strlen(rooms[SECOND]));
	if (room_is_exist(path, id_first, rooms[FIRST])
	&& room_is_exist(path, id_second, rooms[SECOND]))
	{
		add_elem(path->rooms[id_first],
									new_elem(path->rooms[id_second]));
		add_elem(path->rooms[id_second],
									new_elem(path->rooms[id_first]));
	// printf("%s -> %s\n", path->rooms[id_first]->name, path->rooms[id_second]->name);
	// printf("%s -> %s\n", path->rooms[id_second]->name, path->rooms[id_first]->name);	
	}
}

void			add_links(t_map *map, t_path *path)
{
	char	**room;

	room = NULL;
	while (TRUE)
	{
		if (!is_comment(map->buffer.data))
		{
			if (is_link(map->buffer.data))
				make_links(path, room = get_rooms(map->buffer.data));
			else				
				errors_rooms(UNKNOWN_ROOM);
			free_all(2, room[FIRST], room[SECOND]);
		}
		if (!read_data(map, &map->buffer.data))
			break ;
	}
}
