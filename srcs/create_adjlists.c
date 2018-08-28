/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_adjlists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:25:26 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/28 17:57:46 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "lem_in.h"

static char	**get_rooms(char *data)
{
 	return (ft_strsplit(data, '-'));
}

// static void	add_room(t_room *room, t_room *new_room)
// {
// 	if (!room || !new_room)
// 		return ;
// 	while (room->next_room != NULL)
// 		room = room->next_room;
// 	room->next_room = new_room;
// 	new_room->next_room = NULL;
// }
//
// static t_rooms	*new_room(const t_room *room)
// {
// 	t_rooms	*new_room;
//
// 	if ((new_room = (t_rooms *)malloc(sizeof(t_rooms))) == NULL)
// 		return (NULL);
// 	new_room->name = ft_strdup(room->name);
// 	new_room->name_len = room->name_len;
// 	new_room->id = room->id;
// 	new_room->visited = room->visited;
// 	new_room->start = room->start;
// 	new_room->end = room->end;
// 	new_room->next_room = NULL;
// 	return (new_room);
//}

static t_room	*get_room_from_htab(t_htab *htab, int id, char *name)
{
	t_room	*tmp;

	tmp = htab->rooms[id];
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

//static bool		find_elem_in_adjlists(t_adjlists *adjlsts, t_room *room)
//{
//	if (adjlsts->elems[room->index] != NULL)
//		if (ft_strcmp(adjlsts->elems[room->index]->room->name, room->name) == 0)
//			return (TRUE);
//	return (FALSE);
//}
//
//static void		add_to_adjlists(t_adjlists *adjlsts, const t_room *room)
//{
//	adjlsts->elems[room->index]->room = (t_room *)room;
//	adjlsts->elems[room->index]->next = NULL; 
//}
//
//static bool		find_in_list(const t_adjelem *elem, const t_room *room)
//{
//	t_adjelem	*tmp;
//
//	if (!elem || !room)
//		return (FALSE);
//	tmp = (t_adjelem *)elem;
//	while (tmp->next != NULL)
//	{
//		if (ft_strcmp(tmp->room->name, room->name) == 0)
//		   	return (TRUE);
//		tmp = tmp->next;
//	}
//	return (FALSE);
//}
//
//static void		*add_to_list(t_adjelem *elem, const t_room *room)
//{
//	t_adjelem	*tmp;
//	
//	if (!elem || !room)
//		return (NULL);
//	tmp = (t_adjelem *)malloc(sizeof(t_adjelem));
//	tmp->room = (t_room *)room;
//	tmp->next = elem->next;
//	elem->next = tmp;
//	return (tmp);
//}
//
static void		make_links(t_adjlists *adjlsts, t_htab *htab, char **rooms)
{
	int		id_first;
	int		id_second;
	t_room	*first_room;
	t_room	*second_room;
	
	adjlsts = NULL;
	printf("first: %s second: %s\n", rooms[FIRST], rooms[SECOND]);
 	id_first = get_id(htab, rooms[FIRST], ft_strlen(rooms[FIRST]));
 	id_second = get_id(htab, rooms[SECOND], ft_strlen(rooms[SECOND]));
 	if (room_exists(htab, rooms[FIRST], id_first) && room_exists(htab, rooms[SECOND], id_second))
 	{
		if (!(first_room = get_room_from_htab(htab, id_first, rooms[FIRST])))
			return ;
		printf("first_room: id: %d name: %s\n", id_first, first_room->name);
		if (!(second_room = get_room_from_htab(htab, id_second, rooms[SECOND])))
			return ;
		printf("id: %d name: %s\n", id_second, second_room->name);
//		if (!find_elem_in_adjlsts(adjlsts, first_room))
//			add_to_adjlists(adjlsts, first_room);
//		if (!find_elem_elem_in_adjlsts(adjlsts, second_room))
//			add_to_adjlists(adjlsts, second_room);
//		if (!find_in_list(adjlsts->elems[first_room->index]), second_room)
//			add_to_list(adjlsts->elems[first_room->index], second_room);
//		if (!find_in_list(adjlsts->elems[second_room->index]), first_room)
//			add_to_list(adjlsts->elems[second_room->index], first_room);		
 	}
}

void			create_adjlists(t_adjlists *adjlsts, t_htab *htab, t_buff *buff)
{
	char	**room;

	room = NULL;
 	while (TRUE)
 	{
 		if (!is_comment(buff->line))
 		{
 			if (is_link(buff->line))
			{
//				printf("line: %s\n", buff->line);
 				make_links(adjlsts, htab, room = get_rooms(buff->line));
 //			else // Use break and try to create path or just ignore this line
 //				errors_rooms(UNKNOWN_ROOM);
				free_room(room);
				free(room);
			}
 		}
 		if (!read_line(buff, &buff->line))
 			break ;
 	}
}
