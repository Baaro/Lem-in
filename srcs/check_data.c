
#include "lem_in.h"

static intmax_t count_ants(const char *data)
{
	intmax_t	ants;

	ants = 0;
	if (*data == '-')
		errors_ants(ants_is_neg);
	else if (*data == 0)
		errors_ants(ants_is_zero);
	while (*data && ants < MAX_ANTS)
	{
		if (ft_isdigit(*data))
			ants = (ants * 10) + (*data) - '0';
		else
			errors_ants(wrong_value_ants);
		data++;
	}
	if (ants < MAX_ANTS)
		errors_ants(too_few_ants);
	return (ants);
}

void		check_amount_of_ants(t_map *map)
{
	map->ants = count_ants(map->buffer.data);
	map->checks.ants_check = CHECKED;
}

bool        check_start_command(t_map *map)
{

}

bool        check_end_command(t_map *map)
{

}

void		check_coomands(t_map *map)
{
    if (check_start_command(map) == FOUND)
        check_end_command(map);
	if (map->checks.comm_find[START] == NOTFOUND)
	{
		if (is_start_command(map->buffer.data))
			map->checks.comm_find[START] = FOUND; // Triggers for start room
		// else
			// errors_commands(wrong_start_command);
	}
	else
    {
        if (map->checks.comm_find[END] == NOTFOUND)
	    {
		    if (is_end_command(map->buffer.data))
			    map->checks.comm_find[END] = FOUND;
		// else
			// errors_commands(wrong_start_command);
    	}
    }
}