#include "lem_in.h"

void	coords_clear(t_coord **coords, size_t size)
{
	t_coord		*tmp;
	size_t		i;

	i = -1;
	while (++i < size)
	{
		tmp = coords[i];
		while (tmp)
		{
			tmp = coords[i]->next;
			if (coords[i]->x_y)
				free(coords[i]->x_y);
			free(coords[i]);
			coords[i] = tmp;
		}
	}
	free(coords);
}

void	coords_init(t_coord **coord, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
	{
		if (!(coord[i] = (t_coord *)malloc(sizeof(t_coord))))
			errors_memory(CANT_ALLOCATE_MEM, "coord_init");
		if (!(coord[i] = ft_memset(coord[i], 0, sizeof(t_coord))))
			errors_memory(CANT_SETZERO, "coord_init");
	}
}

void	coord_set(t_coord *coord, t_info *info)
{
	if (!(coord->x_y = ft_strredup(info->coord)))
		errors_memory(CANT_ALLOCATE_MEM, "coord_set");
	coord->x_y_len = ft_strlen(coord->x_y);
	coord->id = info->id_coord;
}

bool    coord_exists(t_htab *htab, char *x_y, unsigned long id)
{
	t_coord	*tmp;

	if (htab->coords[id] != NULL)
	{
		tmp = htab->coords[id];
		while (tmp && tmp->x_y)
		{
			if (ft_strcmp(tmp->x_y, x_y) == 0)
				return (TRUE);
			tmp = tmp->next;
		}
	}
	return (FALSE);
}

void    coord_create(t_htab *htab, t_info *info)
{
	t_coord	*tmp;

	if (!htab->coords[info->id_coord]->x_y)
	 	coord_set(htab->coords[info->id_coord], info);
	else
	{
		if (!(tmp = (t_coord *)malloc(sizeof(t_coord))))
			errors_memory(CANT_ALLOCATE_MEM, "coord_create");
		coord_set(tmp, info);
		tmp->next = htab->coords[info->id_coord]->next;
		htab->coords[info->id_coord]->next = tmp;
		if (!htab->coords[info->id_coord]->next->next)
			htab->coords[info->id_coord]->next->next = NULL;
	}
}