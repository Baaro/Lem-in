
#include "lem_in.h"

static size_t	remember_num_of_command(size_t current_num)
{
	return (current_num);
}

static bool		check_end_command(t_map *map, t_checks *checks, const char *data)
{
	if (checks->end_check == UNCHECKED && is_end_command(data))
	{
		if (checks->start_check  == CHECKED)
		{
			checks->end_check = CHECKED;
			map->num_end_elem = remember_num_of_command(map->amount_of_rooms);
			return (TRUE);
		}
		else
			errors_commands(NO_START_COMMAND);
	}
	return (FALSE);
}

static bool		check_start_command(t_map *map, t_checks *checks, const char *data)
{
	if (checks->start_check == UNCHECKED && is_start_command(data))
	{
		checks->start_check = CHECKED;
		map->num_start_elem = remember_num_of_command(map->amount_of_rooms);
		return (TRUE);
	}
	return (FALSE);
}

bool			valid_commands(t_map *map, t_checks *checks, char *data)
{
	if (check_start_command(map, checks, data))
		return (TRUE);
	if (check_end_command(map, checks, data))
		return (TRUE);
	return (FALSE);
}