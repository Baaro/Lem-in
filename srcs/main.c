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
	if (error == max_ants)
		ft_printf("\x1b[31mERROR:\x1b[0m Value of ants is bigger than 100 000!\n");
	else if (error == incorrect_type_ants)
		ft_printf("\x1b[31mERROR:\x1b[0m Value of ants is not a number!\n");
	else if (error == negative_num)
		ft_printf("\x1b[31mERROR:\x1b[0m Value of ants is negative!\n");
	exit(1)
}

static void		errors_rooms(t_errors error)
{

}

static intmax_t	count_ants(const char *str)
{
	intmax_t	ants;

	ants = 0;
	if (*str == '-')
		return (NEGATIVE);
	while (*str && ants < MAX_ANTS)
	{
		if (ft_isdigit(*str))
			ants = (ants * 10) + (*str) - '0';
		else
			return (INVALID);
		str++;
	}
	return (VALID);
}

static void		check_amount_of_ants(t_map *map)
{
	map->ants = count_ants(map->buffer.data);
	if (map->ants == INVALID)
		errors_ants(incorrect_type_ants);
	if (map->ants > MAX_ANTS)
		errors_ants(max_ants);
	if (map->ants == NEGATIVE)
		errors_ants(negative_num);
	map->checks.ants = CHECKED;
}

static void		check_start_coomands(t_map *map)
{
	if (map->checks.commands[END] == CHECKED)
		errors_rooms(end_before_start);
	read_data_from_input(map);
}

static bool		check_data(t_map *map)
{
	if (map->checks.ants == UNCHECKED)
		check_amount_of_ants(map);
	if (map->checks.commands[START] == UNCHECKED)
		check_start_commands(map);
	if (map->checks.commands[END] == UNCHECKED)
		check_end_commands(map);
	// check_rooms();
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
		// create_shortest_path(room);
	// free_room(room);
	return (0);
}