/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:58:00 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/28 09:51:18 by vsokolog         ###   ########.fr       */
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

void     		free_room(char **room)
{
    if (!room)
        return ;
	while (*room)
    {
		free(*room);
		room++;
    }
}

bool				read_line(t_buff *buff, char **line)
{
	char	*tmp;
	ssize_t	flag;

	tmp = NULL;
	flag = 0;
	if (*line)
		free(*line);
	if ((flag = get_next_line(INPUT, line)) != -1)
	{
		if (*line == NULL)
			errors_input(WRONG_INPUT);
		if (flag == 0)
				return (FALSE);
		buff->data = ft_strcat(ft_strjoincl(buff->data, *line, 0),
				tmp = ft_strdup("\n"));
		free(tmp);
	}
	else
	{
		free(buff->data);
		errors_input(WRONG_INPUT);
	}
	return (TRUE);
}
