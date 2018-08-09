#include "lem_in.h"

static void		init_map(t_map *map)
{
	*map = (t_map){0, 0, 0, 0, {NULL, ft_strnew(0)}, {0, 0, 0}, 0, 0, {0, NULL}};
}

static void		init_path(t_path *path, size_t amount_of_rooms)
{	
	if (amount_of_rooms < 1)
		errors_rooms(NO_ROOMS);
	if ((path->rooms = (t_rooms **)malloc(sizeof(t_rooms *) * amount_of_rooms)) == NULL)
	{
		free(path->rooms);
		errors_rooms(CANT_ALLOCATE_MEM);
	}
	ft_bzero(path->rooms, amount_of_rooms);
	path->size = amount_of_rooms;
}

static bool		is_command(const char *data)
{
	if (is_start_command(data) || is_end_command(data))
		return (TRUE);
	return (FALSE);
}

static bool		is_room(const char *data)
{
	 if (!is_comment(data) && !is_command(data))
	 	return (TRUE);
	return (FALSE);
}

static char		*get_next_data(char *data)
{
	static char	*tail;
	char		*pos;
	char		*new_data;

	pos = NULL;
	new_data = NULL;
	if (tail == NULL)
		tail = data;
	if ((pos = ft_strchr(tail, '\n')))
	{
		new_data = ft_strsub(tail, 0, pos - tail);
		tail = pos + 1;
	}
	return (new_data);
}

static int		get_id(t_path *path, char *name, size_t name_len)
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
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return (hash % path->size);
}

static bool		room_is_exist(t_path *path, int id, char *name)
{
	if (path->rooms[id]->name != NULL
	&& path != NULL
	&& ft_strcmp(path->rooms[id]->name, name) == 0)
		return (TRUE);
	return (FALSE);
}

// static t_rooms	*make_room(t_map *map, int id, char *name, size_t count_room)
// {
// 	t_rooms	*new_room;

// 	if ((new_room = (t_rooms *)malloc(sizeof(t_rooms))) == NULL)
// 		return (NULL);
// 	if ((new_room->name = ft_strdup(name)) == NULL)
// 		return (NULL);
// 	new_room->name_len = ft_strlen(new_room->name);
// 	new_room->id = id;
// 	new_room->visited = 0;
// 	if (map->num_start_elem == count_room)
// 		new_room->start = 1;
// 	else
// 		new_room->start = 0;
// 	if (map->num_end_elem == count_room)
// 		new_room->end = 1;
// 	else
// 		new_room->end = 0;
// 	new_room->links = NULL;
// 	return (new_room);
// }

static char		**get_data_of_room(char *data)
{
	return (ft_strsplit(data, ' '));
}

static void		put_room_to_path(t_map *map, t_path *path, char *data, size_t *count_rooms)
{
	char	**room;
	int		id;
	int		a;

	a = map->ants;
	room = get_data_of_room(data);
	id = get_id(path, room[NAME], ft_strlen(room[NAME]));
	(*count_rooms)++;
	if (!room_is_exist(path, id, room[NAME]))
		// path->rooms[id] = make_room(map, id, room[NAME], *count_rooms);
		printf("hello\n");
	else
	{
		free_all(5, path, room, room[NAME], room[X], room[Y]);
		errors_rooms(TWO_ROOMS_AS_SAME_NAME);
	}
	// printf("%s[%d]", path->rooms[id]->name, id);	
	// free_all(room);
}

static void		skip_amount_of_ants(char **data, char *info)
{
	*data = get_next_data(info);
	ft_strdel(data);
}

static void		make_path(t_map *map, t_path *path)
{
	char	*data;
	size_t	room;

	data = NULL;
	room = 0;
	skip_amount_of_ants(&data, map->buffer.info);
	while (TRUE)
	{
		data = get_next_data(map->buffer.info);		
		if (is_link(data))
			break ;
		if (is_room(data))
			put_room_to_path(map, path, data, &room);
		ft_strdel(&data);
	}
	printf("Can make links: %s\n", data);
	// make_links();
}

int				main(void)
{
	t_map	map;

	init_map(&map);
	valid_map(&map);

	init_path(&map.path, map.amount_of_rooms);
	make_path(&map, &map.path);
	// create_links(&map, &path);
	// find_shortest_path_in_map(map, path);
	// show_shortest_path(map, path);
	return (0);
}