#include "lem_in.h"

void		lstpaths_init(t_lstpaths *lp)
{
	if (!(ft_memset(lp, 0, sizeof(t_lstpaths))))
		errors_memory(CANT_SETZERO, "lstpaths_init");
}

t_adjlst	*get_nearest_vertex(t_adjtab *at, t_htab *ht, char *name)
{
	t_adjlst	*tmp;
	t_adjlst	*nearest_v;
	size_t		level;

	level = 0;
	tmp = get_vertex(ht, at, name);
	nearest_v = NULL;
	while (tmp && tmp->room)
	{
		if (tmp->room && tmp->room->visited
		&& (level == 0 || level >= tmp->room->level))
		{
			level = tmp->room->level;
			nearest_v = tmp;
		}
		if (nearest_v && found_room(ht->start, nearest_v->room->name))
			break ;
		tmp = tmp->next;
	}
	return (nearest_v ? nearest_v : NULL);
}

void		lstpaths_put(t_lstpaths *lp, t_path *p)
{
	if (lp->front == NULL)
	{
		lp->front = p;
		lp->front->next = NULL;
		lp->rear = lp->front;
	}
	else
	{
		lp->rear->next = p;
		lp->rear->next->next = NULL;
		lp->rear = lp->rear->next;
	}
}

void		lstpaths_create(t_lstpaths *lp, t_adjtab *at, t_htab *ht)
{
	t_path		*p;

	bfs(at, ht);
	while (paths_exist(at, ht))
	{
		p = path_init();
		if (path_create(p, at, ht))
		{
			lp->paths++;
			lstpaths_put(lp, p);			
		}
	}
	if (!lp->paths)
		errors_algorithm(THERE_ARE_NO_POSSIBLE_WAYS);
}
