#include "lem_in.h"

static void	init_map(t_map *map)
{
	*map = (t_map){0, 0, 0, 0, {NULL, ft_strnew(0)}, {0, 0, 0}, 0, 0};
}

static void	init_path(t_path *path, size_t amount_of_rooms)
{	
	if (amount_of_rooms < 1)
		errors_rooms(NO_ROOMS);
	if ((path->rooms = (t_rooms **)malloc(sizeof(t_rooms *) * amount_of_rooms)) == NULL)
	{
		free(path->rooms);
		errors_rooms(CANT_ALLOCATE_MEM);
	}
	ft_bzero(path->rooms, amount_of_rooms);
	// while (i < size_of_path)
		// path->rooms[i++] = NULL;
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
	pos = ft_strchr(*data, '\n')
	while (*data != '\n')
		data++;
	return (++data);
}

static int		create_id(char *name, size_t path_size, size_t name_len)
{
	size_t	hash;
	size_t	i;

	i = 0;
	hash = 0;
	while (i < name_len)
	{
		hash += name[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return (hash % path_size);
}

static void		put_room(t_path *path, char *data)
{
	char		**room;
	int			id;
	static int	i = 0;

	room = ft_strsplit(data, ' ');
	id = create_id(room[NAME], path->size, ft_strlen(room[NAME]));
	printf("id[%d]: %d\n",  i, id);
	// create_room(id, path->rooms[id], room);
	// clear_room(room);
}

static void		create_path(const t_map *map, t_path *path)
{
	/**							   **
	*	/--makepath					*
	*		/--putroomsInPath		*
	*			/--readData	(info)	*
	*			/--putData			*
	*			/--stopIfLinks		*
	*		/--createLinksOfrooms	*
	*			/--readData			*
	*			/--putLinks			*
	**							  **/
	char	*data;
	size_t	i;

	i = -1;
	data = map->buffer.info;
	while (++i < path->size)
	{
		if (is_link(data))
			break ;
		if (is_room(data))
			put_room(path, data);
		data = get_next_data(data);
	}
	// printf("data: %s\n", data);
}

int				main(void)
{
	t_path			path;
	t_map			map;

	init_map(&map);
	valid_map(&map);

	init_path(&path, map.amount_of_rooms);
	create_path(&map, &path);
	// create_links(&map, &path);
	// find_shortest_path_in_map(map, path);
	// show_shortest_path(map, path);
	return (0);
}