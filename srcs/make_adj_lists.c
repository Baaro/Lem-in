#include "lem_in.h"

static bool		is_command(const char *data)
{
	if (is_start_command(data) || is_end_command(data))
		return (TRUE);
	return (FALSE);
}

static bool		is_room(const char *data)
{
	if (!is_comment(data) && !is_command(data))
	 	return (TRUE);
	return (FALSE);
}

static char		*get_next_data(char *data)
{
	static char	*tail;
	char		*pos;
	char		*new_data;

	pos = NULL;
	new_data = NULL;
	if (tail == NULL)
		tail = data;
	if ((pos = ft_strchr(tail, '\n')))
	{
		new_data = ft_strsub(tail, 0, pos - tail);
		tail = pos + 1;
	}
	return (new_data);
}

static void		skip_amount_of_ants(char **data, char *info)
{
	*data = get_next_data(info);
	ft_strdel(data);
}

static void		init_room(t_rooms **room)
{
	(*room)->name = NULL;
	(*room)->name_len = 0;
	(*room)->id = 0;
	(*room)->visited = 0;
	(*room)->start = 0;
	(*room)->end = 0;
	(*room)->next_room = NULL;
}

static void		init_adj_lists(t_adj_lists *adj_lists, size_t amnt_of_rooms)
{	
	size_t	i;

	i = 0;
	if (amnt_of_rooms < 1)
		errors_rooms(NO_ROOMS);
	if (!(adj_lists->rooms = (t_rooms **)malloc(sizeof(t_rooms *) * amnt_of_rooms)))
	{
		free(adj_lists->rooms);
		errors_rooms(CANT_ALLOCATE_MEM);
	}
	while (i < amnt_of_rooms)
	{
		adj_lists->rooms[i] = (t_rooms *)malloc(sizeof(t_rooms));
		init_room(&adj_lists->rooms[i]);
		i++;
	}
	adj_lists->size = amnt_of_rooms;
	adj_lists->start_len = 0;
	adj_lists->end_len = 0;
}

static void	print_list(int i, t_adj_lists *adj_lists)
{
	t_rooms	*tmp;

	tmp =  adj_lists->rooms[i];
	printf("%s-> ",tmp->name);
	while (tmp->next_room != NULL)
	{	
		tmp = tmp->next_room;
		printf("%s -> ", tmp->name);
	}
	printf("\n");
}

void		make_adj_lists(t_map *map, t_adj_lists *adj_lists)
{
	char	*data;
	size_t	cnt_rooms;

	data = NULL;
	cnt_rooms = 0;
	init_adj_lists(&map->adj_lists, map->amnt_of_rooms);
	skip_amount_of_ants(&data, map->buffer.info);
	while (TRUE)
	{
		data = get_next_data(map->buffer.info);
		if (is_link(data))
			break ;
		if (is_room(data))
			put_to_adj_lists(map, adj_lists, data, &cnt_rooms);
		ft_strdel(&data);
	}
	create_links(map, adj_lists);
	int i = 0;
	while (i < (int)adj_lists->size)
		print_list(i++, adj_lists);
}