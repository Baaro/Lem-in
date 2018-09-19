#include "lem_in.h"

t_adjlst	*get_vertex(t_htab *htab, t_adjtab *adjtab, char *name)
{
	unsigned long	id;
	t_adjlst		*vertex;
	t_room			*room;

	id = get_id(htab, name, ft_strlen(name));
	room = hashtab_get(htab, id, name);
	vertex = adjtab_get(adjtab, room);
	return (vertex);
}

void			bfs(t_adjtab *adjtab, t_htab *htab)
{
	t_queue		*queue;
	t_adjlst	*v;
	size_t		level;

	level = 1;
	queue = queue_init();
	if (!(v = get_vertex(htab, adjtab, htab->start)))
			errors_rooms(THERE_ARE_NO_LINKS_WITH_START);
	enqueue(queue, v, level);
	while (!is_empty(queue))
	{
		// queue_print(queue);
		level = v->room->level;
		while (v)
		{
			if (!v->room->visited
			&& !v->room->in_queue)
				enqueue(queue, v, level + 1);
			v = v->next;
		}
		v = dequeue(queue);
		v = get_vertex(htab, adjtab, v->room->name);
		// printf("room[%s] has level: %zu\n", v->room->name, v->room->level);
	}
	queue_clear(queue);
}
