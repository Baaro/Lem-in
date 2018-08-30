/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_adjlists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:25:26 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/29 13:51:52 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "lem_in.h"

static char	**get_rooms(char *data)
{
 	return (ft_strsplit(data, '-'));
}

static bool		is_exists(t_htab *htab, char *name, unsigned long id)
{
	t_room	*tmp;

	if (htab->rooms[id]->name)
	{
		tmp = htab->rooms[id];
		while (tmp)
		{
			if (ft_strcmp(tmp->name, name) == 0)
				return (TRUE);
			tmp = tmp->next;
		}
	}
	return (FALSE);
}

static t_room	*get_room_from_htab(t_htab *htab, int id, char *name)
{
	t_room	*tmp;

	tmp = htab->rooms[id];
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static bool		find_elem_in_adjlists(t_adjlists *adjlsts, t_room *room)
{
	if (adjlsts->elems[room->index]->room)
		if (ft_strcmp(adjlsts->elems[room->index]->room->name, room->name) == 0)
			return (TRUE);
	return (FALSE);
}

static void		add_to_adjlists(t_adjlists *adjlsts, const t_room *room)
{
	adjlsts->elems[room->index]->room = (t_room *)room;
	adjlsts->elems[room->index]->next = NULL;
}

static bool		find_in_list(const t_adjelem *elem, const t_room *room)
{
	t_adjelem	*tmp;

	if (!elem || !room)
		return (FALSE);
	tmp = (t_adjelem *)elem;
	while (tmp->next != NULL)
	{
		if (ft_strcmp(tmp->room->name, room->name) == 0)
		   	return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}

static void		*add_to_list(t_adjelem *elem, const t_room *room)
{
	t_adjelem	*tmp;

	if (!elem || !room)
		return (NULL);
	tmp = (t_adjelem *)malloc(sizeof(t_adjelem));
	tmp->room = (t_room *)room;
	tmp->next = elem->next;
	elem->next = tmp;
	return (tmp);
}

static void		make_links(t_adjlists *adjlsts, t_htab *htab, char **rooms)
{
	unsigned long	id_first;
	unsigned long	id_second;
	t_room			*first_room;
	t_room			*second_room;
	
 	id_first = get_id(htab, rooms[FIRST], ft_strlen(rooms[FIRST]));
 	id_second = get_id(htab, rooms[SECOND], ft_strlen(rooms[SECOND]));
 	if (is_exists(htab, rooms[FIRST], id_first)
	&& is_exists(htab, rooms[SECOND], id_second))
 	{
		if (!(first_room = get_room_from_htab(htab, id_first, rooms[FIRST])))
			return ;
		if (!(second_room = get_room_from_htab(htab, id_second, rooms[SECOND])))
			return ;
		if (!find_elem_in_adjlists(adjlsts, first_room))
			add_to_adjlists(adjlsts, first_room);
		if (!find_elem_in_adjlists(adjlsts, second_room))
			add_to_adjlists(adjlsts, second_room);
		if (!find_in_list(adjlsts->elems[first_room->index], second_room))
			add_to_list(adjlsts->elems[first_room->index], second_room);
		if (!find_in_list(adjlsts->elems[second_room->index], first_room))
			add_to_list(adjlsts->elems[second_room->index], first_room);
 	}
}

void			create_adjlists(t_adjlists *adjlsts, t_htab *htab, t_buff *buff, t_info *info)
{
 	while (TRUE)
 	{
 		if (!is_comment(buff->line))
 		{
 			if (is_link(buff->line))
			{
				info->room = get_rooms(buff->line);
 				make_links(adjlsts, htab, info->room);
				free_room(info->room);
				free(info->room);
			}
 		}
 		if (!read_line(buff, &buff->line))
 			break ;
 	}
}
