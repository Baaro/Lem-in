#include "lem_in.h"

static t_adjlst	*get_vertex(t_htab *htab, t_adjtab *adjtab, char *name)
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
	t_adjlst	*curr_vertex;
	size_t		level;

	level = 0;
	queue = queue_init();	
	curr_vertex = get_vertex(htab, adjtab, htab->start);
	enqueue(queue, curr_vertex, level);
	while (!is_empty(queue))
	{
		print_queue(queue);
		level = curr_vertex->room->level;
		while (curr_vertex)
		{
			if (!curr_vertex->room->visited
			&& !curr_vertex->room->in_queue)
			{
				curr_vertex->room->visited = TRUE;
				enqueue(queue, curr_vertex, level + 1);
			}
			curr_vertex = curr_vertex->next;
		}
		curr_vertex = dequeue(queue);
		curr_vertex = get_vertex(htab, adjtab, curr_vertex->room->name);
		// printf("%s level: %zu\n", curr_vertex->room->name, curr_vertex->room->level);
	}
	queue_clear(queue);
}
