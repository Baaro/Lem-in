#include "../includes/lem_in.h"
#include <stdio.h>

static void		init_map(t_map *map)
{
	*map = (t_map){0, {NULL, ft_strnew(0)}, {0, 0, 0, 0, 0}};
}

// static void	init_room(t_room *room)
// {
// 	*room = (t_room){NULL, NULL, NULL, 0, 0};
// }

static void		errors_ants(const t_errors error)
{
	if (error == too_few_ants)
		ft_printf("\x1b[31mERROR:\x1b[0m Value of ants is bigger than 100 000!\n");
	else if (error == incorrect_type_ants)
		ft_printf("\x1b[31mERROR:\x1b[0m Value of ants is not a number!\n");
	else if (error == neg_ants)
		ft_printf("\x1b[31mERROR:\x1b[0m Value of ants is negative!\n");
	exit(1);
}

static void		errors_rooms(t_errors error)
{

}

static void		errors_commands(const t_errors error)
{
	if (error = wrong_start_command)
		ft_printf("\x1b[31mERROR:\x1b[0m ##start command is invalid");
	else if (error == wrong_end_command)
		ft_printf("\x1b[31mERROR:\x1b[0m ##end command is invalid");
	else if (error == unknown_command)
		ft_printf("\x1b[31mERROR:\x1b[0m The data has unknown command");
}

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
		if (ft_strcmp(map->buffer.data, "##start") == 0)
			map->checks.comm_find == FIND;
		else
			errors_commands(wrong_start_command);
	}
	// else if (map->checks.comm_find == FIND)
	// {
		// safe_start_room(map);
		// map->checks.comma_check[START] = CHECKED;
	// }
}

static bool		is_all_checked(const t_checks checks)
{
	// if (map->checks.ants_check == UNCHECKED)
		// errors_ants();
	else if (map->checks.coom_check[START] == UNCHECKED)
		errors_commands();
	else if (map->checks.coom_check[END] == UNCHECKED)
		errors_commands();
	// else if (map->checks.coord_check == UNCHECKED);
		// return (UNCHECKED);
	return (CHECKED);
}

static bool		valid_room(t_map *map)
{
	if (is_not_link(map))
	{
		if (is_not_comment(map))
		{
			else if (map->checks.ants_check == UNCHECKED)
				check_amount_of_ants(map);
			else if (map->checks.comma_check[START] == UNCHECKED)
				check_start_command(map);
			// else if (map->checks.commands[END] == UNCHECKED)
				// check_end_command(map);
			// else if (map->checks.links == UNCHECKED)
				// check_rooms(map);
		}
		else
			return (KEEP_READING);
	}
	else if (is_all_checked(map->checks))
		return (CHECKED);
	return (CAN_ADD_TO_HASHTABLE);
}


static bool 	read_data_from_input(t_map *map)
{
	if (get_next_line(INPUT, &map->buffer.data) > 0)
	{
		map->buffer.info = ft_strjoincl(map->buffer.info, map->buffer.data, 0);
		return (TRUE);
	}
	return (FALSE);
}

static void		create_map(t_map *map/*, t_hashtable *hashtable*/)
{
	bool		flag;

	flag = 0;
	while (read_data_from_input(map))
	{
		flag = valid_room(map)
		if (flag == CAN_ADD_TO_HASHTABLE)
			add_elem_to_hashtable(map/*, hashtable*/);
		else if (flag == HASHTABLE_IS_CREATED)
			break ;
	}
}

int			main(void)
{
	t_hashtable	hashtable;
	t_map		map;

	init_map(&map);
	// init_hashtable(&room);
	create_map(&map/*, &hashtable*/);
	// find_shortest_path(hashtable);
	// free_room(room);
	return (0);
}