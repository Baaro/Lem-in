#include "../includes/lem_in.h"

static void	init_map(t_map *map)
{
	*map = (t_map){0, {NULL, ft_strnew(0)}, {0, {0, 0}}, 0, 0};
}

// static void	init_hashtable()
// {
// 
// }

static void	create_hashtable_of_rooms(t_map *map/*, t_hashtable *hashtable*/)
{
	map->flag = read_next_data;
	while (TRUE)
	{
		if (map->flag == read_next_data || map->flag == add_elem_to_hashtable)
			read_data_from_input(map);
		// else if (map->flag == add_elem_to_hashtable)
			// add_data_to_hashtable(map/*, hashtable*/);
		else if (map->flag == end_read_data)
			break ;
		map->flag = valid_data(map, &map->checks);
	}
}

int			main(void)
{
	// t_hashtable	hashtable;
	t_map		map;

	init_map(&map);
	// init_hashtable(&room);
	create_hashtable_of_rooms(&map/*, &hashtable*/);
	// find_shortest_path(hashtable);
	// free_room(room);
	return (0);
}