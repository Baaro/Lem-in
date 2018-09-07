#include "lem_in.h"

void	adjlst_init(t_adjlst **lsts, size_t size)
{
	size_t	i;

	/*
	** We don't use zero index because each null element in hashtable contain zero index
	*/
	i = -1;
	while (++i < size)
	{
		if (!(lsts[i] = (t_adjlst *)ft_memalloc(sizeof(t_adjlst))))
			errors_memory(CANT_ALLOCATE_MEM, "adjlst_init");
	}
}

bool	adjlst_exists(const t_adjlst *elem, const t_room *room)
{
	t_adjlst	*tmp;

	if (elem && room)
	{
		tmp = (t_adjlst *)elem;
		while (tmp && tmp->room != NULL)
		{
			if (ft_strcmp(tmp->room->name, room->name) == 0)
			   	return (TRUE);
			tmp = tmp->next;
		}
	}
	return (FALSE);
}

void	*adjlst_put(t_adjlst *elem, const t_room *room)
{
	t_adjlst	*tmp;

	if (elem && room)
	{
		tmp = (t_adjlst *)malloc(sizeof(t_adjlst));
		tmp->room = (t_room *)room;
		tmp->next = elem->next;
		elem->next = tmp;
	}
	return (tmp);
}