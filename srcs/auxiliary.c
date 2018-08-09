#include "lem_in.h"

void				free_all(size_t numargs, ...)
{
	va_list	ap;
	void	**to_free;
	size_t	i;

	i = -1;
	va_start(ap, numargs);
	while (++i < numargs)
	{
		to_free = va_arg(ap, void **);
		free(to_free);
	}
}

char				*read_data(t_map *map, char *data)
{
	char	*tmp;

	tmp = NULL;
	if (get_next_line(INPUT, &data) > 0)
	{
		map->buffer.info = ft_strcat(ft_strjoincl(map->buffer.info, data, 0),
														tmp = ft_strdup("\n"));
		free(tmp);
	}
	else
	{
		free_all(2, &data, &map->buffer.info);
		errors_input(WRONG_INPUT);
	}
	return (data);
}