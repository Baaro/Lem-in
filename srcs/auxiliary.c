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

// void				free_all(size_t numargs, ...)
// {
// 	va_list	ap;
// 	void	**to_free;
// 	size_t	i;

// 	i = -1;
// 	va_start(ap, numargs);
// 	while (++i < numargs)
// 	{
// 		to_free = va_arg(ap, void **);
// 		free(to_free);
// 	}
// 	va_end(ap);
// }

void		skip_amount_of_ants(const char *data)
{
	char	*tmp;

	if (is_comment(data))
	{
		tmp = get_line(data);
		ft_strdel(&tmp);
	}
	tmp = get_line(data);
	if (tmp)
		ft_strdel(&tmp);
}

// void     	free_dblarray(char **str)
// {
// 	size_t	i;

//     if (!str)
//         return ;
//     i = 0;
// 	while (str[i])
// 		free(str[i++]);
//     // free(str);
// }

char		*get_line(const char *data)
{
	static char	*tail;
	char		*pos;
	char		*line;

	pos = NULL;
	line = NULL;
	if (tail == NULL)
		tail = (char*)data;
	if ((pos = ft_strchr(tail, '\n')))
	{
		line = ft_strsub(tail, 0, pos - tail);
		tail = pos + 1;
	}
	return (line);
}

bool		read_line(t_buff *buff, char **line, int fd)
{
	char	*tmp;
	ssize_t	flag;

	tmp = NULL;
	flag = 0;
	if (*line)
		free(*line);
	if ((flag = get_next_line(fd, line)) != -1)
	{
		if (*line == NULL)
			errors_input(WRONG_INPUT);
		if (flag == 0)
				return (FALSE);
		buff->data = ft_strjoincl(ft_strjoincl(buff->data, *line, 0), 
				tmp = ft_strdup("\n"), 1);
	}
	else
	{
		free(buff->data);
		errors_input(WRONG_INPUT);
	}
	return (TRUE);
}

bool		is_exists(t_htab *htab, char *name, unsigned long id)
{
	t_room	*tmp;

	if (htab->rooms[id]->name)
	{
		tmp = htab->rooms[id];
		while (tmp && tmp->name)
		{
			if (ft_strcmp(tmp->name, name) == 0)
				return (TRUE);
			tmp = tmp->next;
		}
	}
	return (FALSE);
}

