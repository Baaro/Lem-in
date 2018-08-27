/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:58:00 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/27 14:14:18 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	va_end(ap);
}

bool				read_line(t_storage *strg, char **line)
{
	char	*tmp;
	int		flag;

	tmp = NULL;
	if (*line)
		free(*line);
	flag = get_next_line(INPUT, line);
	if (flag > 0)
	{
		strg->buff.data = ft_strcat(ft_strjoincl(strg->buff.data, *line, 0),
				tmp = ft_strdup("\n"));
		free(tmp);
	}
	else if (flag == 0)
	{
		free(*line);
		return (FALSE);
	}
	else if (flag < 0)
	{
		free_all(2, line, &strg->buff.data);
		errors_input(WRONG_INPUT);
	}
	return (TRUE);
}
