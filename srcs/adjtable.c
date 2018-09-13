#include "lem_in.h"

void		adjtab_clear(t_adjtab *adjtab)
{
	t_adjlst	*tmp;
	size_t		i;

	i = -1;
	while (++i < adjtab->size + 1)
	{
		tmp = adjtab->lsts[i];
		while (tmp)
		{
			tmp = adjtab->lsts[i]->next;
			free(adjtab->lsts[i]);
			adjtab->lsts[i] = tmp;
		}
	}
	free(adjtab->lsts);
}

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

void		adjtab_set(t_adjtab *adjtab, t_htab *htab, t_info *info)
{
	unsigned long	id_first;
	unsigned long	id_second;
	t_room			*first_room;
	t_room			*second_room;

 	id_first = get_id(htab, info->first_room, ft_strlen(info->first_room));
 	id_second = get_id(htab, info->second_room, ft_strlen(info->second_room));
 	if (room_exists(htab, info->first_room, id_first)
	&& room_exists(htab, info->second_room, id_second))
 	{
 		// printf("first: %s\n", info->first_room);
 		// printf("second: %s\n", info->second_room);
		if (!(first_room = hashtab_get(htab, id_first, info->first_room)))
			return ;
		if (!(second_room = hashtab_get(htab, id_second, info->second_room)))
			return ;	
		if (!adjtab_exists(adjtab, first_room))
			adjtab_put(adjtab, first_room);
		if (!adjtab_exists(adjtab, second_room))
			adjtab_put(adjtab, second_room);
		if (!adjlst_exists(adjtab->lsts[first_room->index], second_room))
			adjlst_put(adjtab->lsts[first_room->index], second_room);
		if (!adjlst_exists(adjtab->lsts[second_room->index], first_room))
			adjlst_put(adjtab->lsts[second_room->index], first_room);
 	}
}

void		adjtab_create(t_adjtab *at, t_htab *ht, t_buff *b, t_info *i)
{
 	while (TRUE)
 	{
 		if (!is_comment(b->line))
 		{
 			if (is_link(b->line))
			{
				info_get_links(i, b->line);
 				adjtab_set(at, ht, i);
				info_clear_links(i);
			}
 		}
 		if (!read_line(b, &b->line))
 			break ;
 	}
}