#include "lem_in.h"

void		adjtab_clear(t_adjtab *adjtab)
{
	t_adjlst	*tmp;
	size_t		i;

	i = 0;
	while (++i < adjtab->size)
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
	// t_room *tmp;

	// tmp = (t_room *)room;
	adjtab->lsts[room->index]->room = (t_room *)room;
	printf("n: [%s]	", adjtab->lsts[room->index]->room->name);
	printf("i: [%zu]\n", adjtab->lsts[room->index]->room->index);
	// printf("name: %s\n", adjtab->lsts[room->index]->room->name);
	adjtab->lsts[room->index]->next = NULL;
}

void		adjtab_set(t_adjtab *adjtab, t_htab *htab, char **rooms)
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
		if (!(first_room = hashtab_get(htab, id_first, rooms[FIRST])))
			return ;
		if (!(second_room = hashtab_get(htab, id_second, rooms[SECOND])))
			return ;
		if (!adjtab_exists(adjtab, first_room))
		{
			printf("first: -> ");
			adjtab_put(adjtab, first_room);
		}
		if (!adjtab_exists(adjtab, second_room))
		{
			printf("second: -> ");			
			adjtab_put(adjtab, second_room);
		}
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
				i->line = get_rooms(b->line);
 				adjtab_set(at, ht, i->line);
 				free_dblarray(i->line);
			}
 		}
 		if (!read_line(b, &b->line))
 			break ;
 	}
}