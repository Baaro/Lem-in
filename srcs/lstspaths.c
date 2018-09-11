#include "lem_in.h"

// void		path_clear(t_path *p)
// {
// }

void		lstpaths_put(t_lstpaths *lp, t_path *p, size_t steps) // Like queue
{

}

void		print_path(t_path *p)
{
	t_path	*tmp;

	tmp = p;
	while (tmp && tmp->room)
	{
		printf("[%s] -> ", tmp->room->name);
		tmp = tmp->next;
	}
	printf("\n");
}

void		lstpaths_init(t_lstpaths *lp)
{
	if (!(ft_memset(lp, 0, sizeof(t_lstpaths))))
		errors_memory(CANT_SETZERO, "lstpaths_init");
}

t_adjlst	*get_nearest_vertexes(t_adjtab *at, t_htab *ht, char *v)
{
	t_adjlst	*tmp;
	t_adjlst	*nearest_v;
	size_t		level;

	level = 0;
	tmp = get_vertex(ht, at, v);
	nearest_v = NULL;
	while (tmp && tmp->room)
	{
		if ((level == 0 || level <= tmp->room->level)
		&& tmp->room-visited)
			nearest_v = tmp;
		tmp = tmp->next;
	}
	return (nearest_v ? nearest_v : NULL);
}

t_path		*path_init(void)
{
	t_path		*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_path))))
		errors_memory(CANT_ALLOCATE_MEM, "path_init");
	return (tmp);
}

void		path_put(t_path **p, t_adjlst *v) // Like stack
{
	t_path		*tmp;

	if (p && v)
	{
		tmp = (t_path *)ft_memalloc(sizeof(t_path));
		tmp->room = v->room;
		tmp->room->visited = FALSE;
		tmp->next = *p;
		*p = tmp;
	}
}

void		path_create(t_path *p, t_adjtab *at, t_htab *ht, size_t *steps)
{
	t_adjlst	*tmp;
	t_adjlst	*end;

	end = get_vertex(ht, at, ht->end);
	tmp = end;
	while (TRUE)
	{
		path_put(&p, tmp->room);
		(*steps)++;
		if (!(tmp = get_nearest_vertexes(at, ht, tmp)))
		{
			path_clear(p);
			break ;
		}
	}
	if (tmp && tmp->room && ft_strcmp(tmp->room->name, ht->start) == 0)
		return (TRUE);
	return (FALSE);
}

void		lstpaths_create(t_lstpaths *lp, t_adjtab *at, t_htab *ht)
{
	t_path		*p;
	size_t 		steps;

	bfs(at, ht);
	q = queue_init();
	while (TRUE) // That means that "end" room still has the free visited vertex which we haven't come
	{
		steps = 0;
		p = path_init();
		if (!path_create(p, at, ht, &steps))
			break ;
		lstpaths_put(lp, p, steps); // Put path to lists of path, dont forget that you put address of current path to that list
		lp->paths++;
	}
}
