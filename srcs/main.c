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

static void	create_hashtable_of_rooms(t_map *map/*, t_hashtable *hashtable*/)
{
	short	flag;

	flag = READ_DATA;
	while (TRUE)
	{
		if (flag == READ_DATA)
		{
			read_data_from_input(map);
			flag = valid_data(map);
		}
		if (flag == CAN_ADD_TO_HASHTABLE)
		{
			add_elem_to_hashtable(map/*, hashtable*/);
			flag = READ_DATA;
		}
		if (flag == END_READ)
			break ;
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