#include "lem_in.h"

void		send_through_shortest_path(intmax_t ants, char *end)
{
	intmax_t	ant;

	ant = 0;
	while (ant < ants)
		ft_printf("L%jd-%s ", ++ant, end);
	ft_printf("\n");
}

bool		shortest_path_exist(t_atab *at, t_htab *ht)
{
	t_alst		*v;

	v = get_vertex(ht, at, ht->end);
	while (v && v->room)
	{
		if (is_start(ht, v))
			return (TRUE);
		v = v->next;
	}
	return (FALSE);
}