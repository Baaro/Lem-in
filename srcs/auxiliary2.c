#include "lem_in.h"

bool		is_garbage(const char *line)
{
	if (!is_link(line) && !is_comment(line))
		return (TRUE);
	return (FALSE);
}

bool		is_start(t_htab *ht, t_alst *v)
{
	if (ft_strcmp(ht->start, v->room->name) == 0)
		return (TRUE);
	return (FALSE);
}

bool		is_nearest(t_alst *tmp, size_t level)
{
	if (tmp->room && tmp->room->visited
	&& (level == 0 || level >= tmp->room->level))
		return (TRUE);
	return (FALSE);
}