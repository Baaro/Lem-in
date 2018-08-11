#include "lem_in.h"

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

static void		skip_amount_of_ants(char **data, char *info)
{
	*data = get_next_data(info);
	ft_strdel(data);
}

static void		init_room(t_rooms **room)
{
	(*room)->name = NULL;
	(*room)->name_len = 0;
	(*room)->id = 0;
	(*room)->visited = 0;
	(*room)->start = 0;
	(*room)->end = 0;
	(*room)->next_room = NULL;
}

static void		init_path(t_path *path, size_t amount_of_rooms)
{	
	size_t i;

	i = 0;
	if (amount_of_rooms < 1)
		errors_rooms(NO_ROOMS);
	if ((path->rooms = (t_rooms **)malloc(sizeof(t_rooms *) * amount_of_rooms)) == NULL)
	{
		free(path->rooms);
		errors_rooms(CANT_ALLOCATE_MEM);
	}
	while (i < amount_of_rooms)
	{
		path->rooms[i] = (t_rooms *)malloc(sizeof(t_rooms));
		init_room(&path->rooms[i++]);
	}
	path->size = amount_of_rooms;
}

// static void	print_list(int id, t_path *path)
// {
// 	printf("[%s] -> ", path->rooms[id]->name);
// 	while (path->rooms[id]->next_room != NULL)
// 	{
// 		path->rooms[id] = path->rooms[id]->next_room;		
// 		printf("%s -> ", path->rooms[id]->name);
// 	}
// 	printf("\n");
// }

void		make_path(t_map *map, t_path *path)
{
	char	*data;
	size_t	count_rooms;

	data = NULL;
	count_rooms = 0;
	init_path(&map->path, map->amount_of_rooms);
	skip_amount_of_ants(&data, map->buffer.info);
	while (TRUE)
	{
		data = get_next_data(map->buffer.info);	
		if (is_link(data))
			break ;
		if (is_room(data))
			put_room_to_path(map, path, data, &count_rooms);
		ft_strdel(&data);
	}
	add_links(map, path);
	// int id = 0;
	// while (id < path->size)
	// 	print_list(id++, path);
	// use_bfs();
}