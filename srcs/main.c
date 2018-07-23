#include "../includes/lem_in.h"
#include <stdio.h>

static void		init_map(t_map *map)
{
	// map = (t_map*)malloc(sizeof(t_map));
	*map = (t_map){0, {NULL, ft_strnew(0)}, {0, {0,0}, 0, 0, 0}};
}

// static void	init_room(t_room *room)
// {
// 	*room = (t_room){NULL, NULL, NULL, 0, 0};
// }

static void		errors_ants(t_errors error)
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

static void		errors_commands(t_errors error)
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

	if (*str == '-')
		errors_ants(ants_is_neg);
	else if (*str == 0)
		errors_ants(ants_is_zero);
	ants = 0;
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
	return (VALID);
}

static bool		check_amount_of_ants(t_map *map)
{
	map->ants = count_ants(map->buffer.data);
	map->checks.ants = CHECKED;
	return (VALID);
}

static void		check_start_coomand(t_map *map)
{
	errors_commands(wrong_start_command);
	read_data_from_input(map);
}

static bool		check_data(t_map *map)
{
	if (is_not_comment(map))
	{
		if (is_link(map->buffer.data))
			return (VALID);
		else if (map->checks.ants == UNCHECKED)
			check_amount_of_ants(map);
		else if (map->checks.commands[START] == UNCHECKED)
			check_start_command(map);
		else if (map->checks.commands[END] == UNCHECKED)
			check_end_command(map);
		else if (map->checks.links == UNCHECKED)
			check_rooms(map);
	}
	return (UNVALID);
}

static bool 	read_data_from_input(t_map *map)
{
	if (get_next_line(0, &map->buffer.data) > 0)
	{
		map->buffer.info = ft_strjoincl(map->buffer.info, map->buffer.data, 0);
		return (TRUE);
	}
	return (FALSE);
}

static bool		data_is_valid(t_map *map)
{
	while (read_data_from_input(map))
		if (check_data(map))
			return (VALID);
	return (UNVALID);
}

int			main(void)
{
	t_map	map;
	// t_room			*room;

	init_map(&map);
	// init_room(&room);
	if (data_is_valid(&map))
	{
		// create_map(map);
		// find_shortest_path(room);
	}
	// free_room(room);
	return (0);
}