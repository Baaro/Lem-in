
#include "lem_in.h"

static size_t	remember_position_of_elem(size_t size_of_hashtable)
{
	return (size_of_hashtable);
}

bool	check_start_command(t_map *map, t_checks *checks, const char *data)
{
	if (checks->comm_check[START] == UNCHECKED && is_start_command(data))
	{
		checks->comm_check[START] = CHECKED;
		map->pos_start_elem = remember_position_of_elem(map->size_of_hashtable);
		return (TRUE);
	}
	return (FALSE);
}

bool	check_end_command(t_map *map, t_checks *checks, const char *data)
{
	if (checks->comm_check[END] == UNCHECKED && is_end_command(data))
	{
		if (checks->comm_check[START] == CHECKED)
		{
			checks->comm_check[END] = CHECKED;
			map->pos_end_elem = remember_position_of_elem(map->size_of_hashtable);
			return (TRUE);
		}
		else
			errors_commands(no_start_command);
	}
	return (FALSE);
}