#include "../includes/lem_in.h"
#include <stdio.h>

static void	init_map(t_map *map)
{
	*map = (t_map){0, {NULL, ft_strnew(0)}, {0, {0, 0}, {0, 0}}, 0};
}

// static void	init_hashtable()
// {
// 
// }

static void	create_map(t_map *map/*, t_hashtable *hashtable*/)
{
	bool	flag;

	flag = 0;
	while (read_data_from_input(map))
	{
		flag = valid_rooms(map);
		printf("flag: %d\n", flag);
		// if (flag == CAN_ADD_TO_HASHTABLE)
			// add_elem_to_hashtable(map/*, hashtable*/);
		// else if (flag == HASHTABLE_IS_CREATED)
			// break ;
	}
}

int			main(void)
{
	// t_hashtable	hashtable;
	t_map		map;

	init_map(&map);
	// init_hashtable(&room);
	create_map(&map/*, &hashtable*/);
	// find_shortest_path(hashtable);
	// free_room(room);
	return (0);
}