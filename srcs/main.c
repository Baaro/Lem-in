#include "../includes/lem_in.h"

static void	init_map(t_map *map)
{
	*map = (t_map){0, 0, 0, 0, {NULL, ft_strnew(0)}, {0, {0, 0}}, 0, 0};
}

// static void	init_hashtable(t_hashtable *hashtable)
// {
// }

static void	validation(t_map *map/*, t_hashtable *hashtable*/)
{
	map->flag = read_next_data;
	while (TRUE)
	{
		if (map->flag == read_next_data)
		{
			read_data_from_input(map);
			map->flag = go_valid;
		}
		if (map->flag == go_valid)
			map->flag = valid_data(map, &map->checks);
		if (map->flag == add_elem_to_hashtable)
		{
			map->size_of_hashtable++;
			map->flag = read_next_data;
		}
		if (map->flag == end_read_data)
			break ;
	}
}

int			main(void)
{
	// t_hashtable	hashtable;
	t_map		map;

	init_map(&map);
	validation(&map);
	// create_hashtable(&map, &hashtable);
	printf("size: %zu\n", map.size_of_hashtable);
	printf("start: %zu\n", map.pos_start_elem);
	printf("end: %zu\n", map.pos_end_elem);
		
	// find_shortest_path(hashtable);
	return (0);
}