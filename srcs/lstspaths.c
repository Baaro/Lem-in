#include "lem_in.h"

void		lstpaths_init(t_lstpaths *lp)
{
	if (!(ft_memset(lp, 0, sizeof(t_lstpaths))))
		errors_memory(CANT_SETZERO, "lstpaths_init");
}

t_adjlst	*get_visited_vertexes(t_adjtab *at, t_htab *ht)
{
	t_adjlst	*v;

	v = get_vertex(ht, at, ht->end); // we begin from the finish vertex
	v = v->next;
	while (v && !v->room->visited)
		v = v->next;
	return (v ? v : NULL);
}

t_path		*path_init(void)
{
	t_path	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_path))))
		errors_memory(CANT_ALLOCATE_MEM, "path_init");
	return (tmp);
}

void		path_create(t_path *p, t_adjlst *v, t_adjtab *at, t_htab *ht)
{
	t_adjlst	*tmp;

	tmp = get_vertex(ht, at, v->room->name);
	path_put(p, tmp);
	while (tmp && tmp->room)
	{
		if (tmp->visited)
		{
			tmp->visited = FALSE;			
			path_create(p, v, at, ht);
		}
		tmp = tmp->next;
	}
}

void		lstpaths_put(t_lstpaths **lp, t_path *p)
{
	t_lstpaths	*tmp;

	if (lp && p)
	{
		tmp = (t_lstpaths *)malloc(sizeof(t_lstpaths));
		tmp->path = p;
		tmp->next = *lp;
		*lp = tmp;
	}
}


void		lstpaths_create(t_lstpaths *lp, t_adjtab *at, t_htab *ht)
{
	t_path		*p;
	t_adjlst	*v;

	bfs(at, ht);
	while ((v = get_visited_vertexes(at, ht))) // That means that "end" room still has the free visited vertex which we haven't come
	{
		p = path_init(); // Init new path (malloc)
		v->room->visited = FALSE;
		path_create(p, v, at, ht);	// In this func will be DFS algorithm
		lstpaths_put(&lp, p); // Put path to lists of path, dont forget that you put address of current path to that list
	}
	printf("After loop\n");
	// lstpaths_sort(lp); // Sort paths by amount of steps
}
