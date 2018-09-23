/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjtable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 16:13:24 by vsokolog          #+#    #+#             */
/*   Updated: 2018/09/22 16:13:26 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool		atab_exists(t_atab *a, t_room *room)
{
	if (a->lsts[room->index]
	&& a->lsts[room->index]->room
	&& a->lsts[room->index]->room->name)
	{
		if (ft_strcmp(a->lsts[room->index]->room->name, room->name) == 0)
			return (TRUE);
	}
	return (FALSE);
}

t_alst		*atab_get(t_atab *a, t_room *room)
{
	if (a->lsts[room->index]->room)
		if (ft_strcmp(a->lsts[room->index]->room->name, room->name) == 0)
			return (a->lsts[room->index]);
	return (NULL);
}

bool		atab_check(t_atab *a, t_room *f_room, t_room *s_room)
{
	if (is_duplicate(f_room->name, s_room->name))
		return (FALSE);
	if (!atab_exists(a, f_room))
	{
		a->lsts[f_room->index]->room = f_room;
		a->lsts[f_room->index]->next = NULL;
	}
	if (!atab_exists(a, s_room))
	{
		a->lsts[s_room->index]->room = s_room;
		a->lsts[s_room->index]->next = NULL;
	}
	if (!alst_exists(a->lsts[f_room->index], s_room))
		alst_put(a->lsts[f_room->index], s_room);	
	if (!alst_exists(a->lsts[s_room->index], f_room))
		alst_put(a->lsts[s_room->index], f_room);
	return (TRUE);
}

bool		atab_set(t_atab *a, t_htab *ht, t_info *i)
{
	t_room	*first_room;
	t_room	*second_room;

	i->id_first = get_id(ht, i->first_room, ft_strlen(i->first_room));
	i->id_second = get_id(ht, i->second_room, ft_strlen(i->second_room));
	if (room_exists(ht, i->first_room, i->id_first)
	&& room_exists(ht, i->second_room, i->id_second))
	{
		if (!(first_room = htab_get(ht, i->id_first, i->first_room)))
			return (FALSE);
		if (!(second_room = htab_get(ht, i->id_second, i->second_room)))
			return (FALSE);
		if (!atab_check(a, first_room, second_room))
			return (FALSE);
	}
	else
		return (FALSE);
	return (TRUE);
}

void		atab_crte(t_atab *at, t_htab *ht, t_buff *b, t_info *i)
{
	while (TRUE)
	{
		if (!is_comment(b->line))
		{
			if (is_link(b->line))
			{
				info_get_links(i, b->line);
				if (!atab_set(at, ht, i))
				{
					info_clear_links(i);
					return ;
				}
				info_clear_links(i);
			}
			else
				break ;
		}
		save_data(&b->data, b->line);
		if (!read_line(b, &b->line))
			break ;
	}
}
