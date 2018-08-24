#include "lem_in.h"

static bool		is_command(const char *line)
{
	if (is_start_command(line) || is_end_command(line))
		return (TRUE);
	return (FALSE);
}

static bool		is_room(const char *line)
{
	if (!is_comment(line) && !is_command(line))
	 	return (TRUE);
	return (FALSE);
}

static char		*get_line(char *line)
{
	static char	*tail;
	char		*pos;
	char		*new_line;

	pos = NULL;
	new_line = NULL;
	if (tail == NULL)
		tail = line;
	if ((pos = ft_strchr(tail, '\n')))
	{
		new_line = ft_strsub(tail, 0, pos - tail);
		tail = pos + 1;
	}
	return (new_line);
}

static void		skip_amount_of_ants(char *data)
{
	char	*tmp;

	tmp = get_line(data);
	ft_strdel(&tmp);
}

static void		init_room(t_rooms **room)
{
	(*room)->name = NULL;
	(*room)->name_len = 0;
	(*room)->id = 0;
	(*room)->visited = 0;
	(*room)->in_queue = 0;	
	(*room)->start = 0;
	(*room)->end = 0;
	(*room)->nxt_hsh_room = NULL;
	(*room)->nxt_adj_room = NULL;	
}

static void		init_tab(t_table *tab, size_t amnt_of_rooms)
{	
	size_t	i;

	i = 0;
	if (amnt_of_rooms < 1)
		errors_rooms(NO_ROOMS);
	if (!(tab->rooms = (t_rooms **)malloc(sizeof(t_rooms *) * amnt_of_rooms)))
	{
		free(tab->rooms);
		errors_rooms(CANT_ALLOCATE_MEM);
	}
	while (i < amnt_of_rooms)
	{
		tab->rooms[i] = (t_rooms *)malloc(sizeof(t_rooms));
		init_room(&tab->rooms[i]);
		i++;
	}
	tab->start = NULL;
	tab->end = NULL;
	tab->size = amnt_of_rooms;
	tab->start_len = 0;
	tab->end_len = 0;
}

static void		print_list(t_table *tab, int i)
{
	t_rooms	*tmp;

	tmp =  tab->rooms[i];
	printf("%s-> ",tmp->name);
	while (tmp->nxt_hsh_room != NULL)
	{
		tmp = tmp->nxt_hsh_room;
		printf("%s -> ", tmp->name);
	}
	printf("\n");
}

void			create_hashtable(t_buffer *buff, t_table *tab, t_info *info)
{
	init_tab(tab, info->amnt_of_rooms);
	skip_amount_of_ants(buff->data);
	while (TRUE)
	{
		info->line = get_line(buff->data);
		if (is_link(info->line))
			break ;
		if (is_room(info->line))	
			put_to_table(tab, info);
		ft_strdel(&info->line);
	}
	// create_adj_lists(storage, tab);
	// int i = 0;
	// while (i < (int)tab->size)
		// print_list(tab, i++);
}
