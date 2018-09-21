#include "lem_in.h"

bool		adjtab_exists(t_adjtab *adjtab, t_room *room)
{
	if (adjtab->lsts[room->index]
	&& adjtab->lsts[room->index]->room
	&& adjtab->lsts[room->index]->room->name)
	{
		if (ft_strcmp(adjtab->lsts[room->index]->room->name, room->name) == 0)
			return (TRUE);
	}
	return (FALSE);
}

t_adjlst	*adjtab_get(t_adjtab *adjtab, t_room *room)
{
	if (adjtab->lsts[room->index]->room)
		if (ft_strcmp(adjtab->lsts[room->index]->room->name, room->name) == 0)
			return (adjtab->lsts[room->index]);
	return (NULL);
}

void		adjtab_put(t_adjtab *adjtab, const t_room *room)
{
	adjtab->lsts[room->index]->room = (t_room *)room;
	adjtab->lsts[room->index]->next = NULL;
}

bool		adjtab_check(t_adjtab *adjtab, t_room *f_room, t_room *s_room)
{
	if (is_duplicate(f_room->name,  s_room->name))
		return (FALSE);
	if (!adjtab_exists(adjtab, f_room))
		adjtab_put(adjtab, f_room);
	if (!adjtab_exists(adjtab, s_room))
		adjtab_put(adjtab, s_room);
	if (adjlst_exists(adjtab->lsts[f_room->index], s_room)
	|| adjlst_exists(adjtab->lsts[s_room->index], f_room))
		return (FALSE);
	adjlst_put(adjtab->lsts[f_room->index], s_room);
	adjlst_put(adjtab->lsts[s_room->index], f_room);
	return (TRUE);
}

bool		adjtab_set(t_adjtab *adjtab, t_htab *htab, t_info *i)
{
	t_room			*first_room;
	t_room			*second_room;

 	i->id_first = get_id(htab, i->first_room, ft_strlen(i->first_room));
 	i->id_second = get_id(htab, i->second_room, ft_strlen(i->second_room));
 	if (room_exists(htab, i->first_room, i->id_first)
	&& room_exists(htab, i->second_room, i->id_second))
 	{
		if (!(first_room = hashtab_get(htab, i->id_first, i->first_room)))
			return (FALSE);
		if (!(second_room = hashtab_get(htab, i->id_second, i->second_room)))
			return (FALSE);
		if (!adjtab_check(adjtab, first_room, second_room))
			return (FALSE);
 	}
	else
		return (FALSE);
	return (TRUE);
}

void		adjtab_create(t_adjtab *at, t_htab *ht, t_buff *b, t_info *i)
{
 	while (TRUE)
 	{
 		if (!is_comment(b->line))
 		{
			if (is_garbage(b->line))
				break ;
			info_get_links(i, b->line);
			if (!adjtab_set(at, ht, i))
			{
				info_clear_links(i);					
				return ;
			}
			info_clear_links(i); // here is double free !!!
 		}
		save_data(&b->data, b->line);		 
 		if (!read_line(b, &b->line))
 			break ;
 	}
}