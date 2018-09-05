#include "lem_in.h"

void			hashtab_clear(t_htab *htab)
{
	rooms_clear(htab->rooms, htab->size);
	coords_clear(htab->coords, htab->size);
	ft_strdel(&htab->start);
	ft_strdel(&htab->end);
}

t_room			*hashtab_get(t_htab *htab, unsigned long id, char *name)
{
	t_room	*tmp;

	tmp = htab->rooms[id];
	while (tmp && tmp->name)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

unsigned long	get_id(t_htab *htab, char *name, size_t name_len)
{
	size_t	hash;
	size_t	i;

	i = 0;
	hash = 0;
	while (i < name_len)
	{
		hash += name[i++];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash = hash % htab->size;
	return (hash == 0 ? hash + 1 : hash);
}

void			hashtab_set(t_htab *htab, t_info *info)
{
	if (!room_exists(htab, info->room, info->id_room))
	{
		if (!coord_exists(htab, info->coord, info->id_coord))
		{
			room_create(htab, info);
			coord_create(htab, info);
		}
		else
			errors_rooms(TWO_ROOMS_HAVE_THE_SAME_COORDS);
	}
	else
		errors_rooms(TWO_ROOMS_HAVE_THE_SAME_NAME);
}

void			hashtab_create(t_htab *htab, t_buff *buff, t_info *info)
{
	skip_amount_of_ants(buff->data);
	while (TRUE)
	{
		info->line = get_line(buff->data);
		if (is_link(info->line))
			break ;
		if (is_room(info->line))
		{
			info_get_rooms(info, htab, buff);
			hashtab_set(htab, info);
			info_clear_rooms(info);
		}
		ft_strdel(&info->line);
	}
	ft_strdel(&info->line);
}