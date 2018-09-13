#include "lem_in.h"

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
		if (nearest_v && found_start(ht->start, nearest_v->room->name))
			break ;
		tmp = tmp->next;
	}
	return (nearest_v ? nearest_v : NULL);
}

void		lstpaths_put(t_lstpaths *lp, t_path *p) // Like queue
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
	// p->next = lp->front;
}

void		lstpaths_init(t_lstpaths *lp)
{
	if (!(ft_memset(lp, 0, sizeof(t_lstpaths))))
		errors_memory(CANT_SETZERO, "lstpaths_init");
}

void		lstpaths_print(t_lstpaths *lp)
{
	t_path	*p;

	p = lp->front;
	while (p)
	{
		path_print(p);
		p = p->next;
	}
}

void		lstpaths_create(t_lstpaths *lp, t_adjtab *at, t_htab *ht)
{
	t_path		*p;
	bool		found;

	bfs(at, ht);
	while (paths_exists(at, ht))
	{
		p = path_init();
		if (path_create(p, at, ht))
			lp->paths++;
		lstpaths_put(lp, p); // Put path to lists of path, dont forget that you put address of current path to that list
	}
	if (lp->paths)
		printf("paths: %zu\n", lp->paths);
	lstpaths_print(lp);
}
