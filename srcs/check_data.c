
#include "lem_in.h"

static intmax_t	count_ants(const char *data)
{
	intmax_t	ants;

	ants = 0;
	if (*str == '-')
		errors_ants(ants_is_neg);
	else if (*str == 0)
		errors_ants(ants_is_zero);
	while (*str && ants < MAX_ANTS)
	{
		if (ft_isdigit(*str))
			ants = (ants * 10) + (*str) - '0';
		else
			errors_ants(wrong_value_ants);
		str++;
	}
	if (ants < MAX_ANTS)
		errors_ants(to_few_ants);
	return (ants);
}

static bool		check_amount_of_ants(t_map *map)
{
	map->ants = count_ants(map->buffer.data);
	map->checks.ants = CHECKED;
	return (VALID);
}

static void		check_start_coomand(t_map *map)
{
	if (map->checks.comm_find == NOTFOUND)
	{
		if (is_start_command(map->buffer.data))
			map->checks.comm_find == FOUND;
		else
			errors_commands(wrong_start_command);
	}
	// else if (map->checks.comm_find == FIND)
	// {
		// safe_start_room(map);
		// map->checks.comma_check[START] = CHECKED;
	// }
}