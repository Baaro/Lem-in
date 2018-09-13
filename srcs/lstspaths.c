#include "lem_in.h"

void		path_del(t_path *p)
{
	while (p->path)
	{
		free(p->path);
		p->path = p->path->next;
	}
	free(p);
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
	lp->paths++;
}

bool		found_start(char *start, char *name)
{
	if (ft_strcmp(start, name) == 0)
		return (TRUE);
	return (FALSE);
}

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
		if (nearest_v && found_start(ht->start, nearest_v->room->name))
			break ;
		tmp = tmp->next;
	}
	return (nearest_v ? nearest_v : NULL);
}

t_path		*path_init(void)
{
	t_path		*p;

	if (!(p = ft_memalloc(sizeof(t_path))))
		errors_memory(CANT_ALLOCATE_MEM, "path_init");
	p->steps = -1;
	return (p);
}

void		path_put(t_path *p, t_room *room) // Like stack
{
	t_stack		*tmp;

	if (p && room)
	{
		if (!(tmp = (t_stack *)ft_memalloc(sizeof(t_stack))))
			errors_memory(CANT_ALLOCATE_MEM, "path_put");
		tmp->room = room;
		tmp->room->visited = FALSE;
		tmp->next = p->path;
		p->path = tmp;
		p->steps++;
	}
}

bool		paths_exists(t_adjtab *at, t_htab *ht)
{
	t_adjlst	*vertex;

	vertex = get_vertex(ht, at, ht->end);
	while (vertex && vertex->room)
	{
		if (vertex->room->visited)
			return (TRUE);
		vertex = vertex->next;
	}
	return (FALSE);
}

void		path_create(t_path *p, t_adjtab *at, t_htab *ht)
{
	t_adjlst	*vertex;
	bool		found;

	found = FALSE;
	vertex = get_vertex(ht, at, ht->end);
	path_put(p, vertex->room);
	while ((vertex = get_nearest_vertex(at, ht, vertex->room->name)))
	{
		path_put(p, vertex->room);
		if (found_start(ht->start, vertex->room->name))
		{
			vertex->room->visited = TRUE;
			found = TRUE;
			break ;
		}
	}
	if (!found)
		path_del(p);
}

void		path_print(t_path *p)
{
	t_stack		*tmp;

	tmp = p->path;
	if (tmp)
	printf("steps: %zu\n", p->steps);
	while (tmp && tmp->room)
	{
		printf("|%s|\n", tmp->room->name);
		tmp = tmp->next;
	}
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

There are no possbile ways from start to end.

void		lstpaths_create(t_lstpaths *lp, t_adjtab *at, t_htab *ht)
{
	t_path		*p;

	bfs(at, ht);
	while (paths_exists(at, ht))
	{
		p = path_init();
		path_create(p, at, ht);
		lstpaths_put(lp, p); // Put path to lists of path, dont forget that you put address of current path to that list
		lp->paths++;
	}
	lstpaths_print(lp);
}
