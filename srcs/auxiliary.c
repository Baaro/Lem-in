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

bool		is_duplicate(const char *f_name, const char *s_name)
{
	if (ft_strcmp(f_name, s_name) == 0)
		return (TRUE);
	return (FALSE);
}

bool		is_garbage(const char *line)
{
	if (is_wrong_command(line) || !is_link(line))
		return (TRUE);
	return (FALSE);
}

void		skip_amount_of_ants(const char *data)
{
	char	*tmp;

	while (TRUE)
	{
		tmp = get_line(data);
		if (!is_comment(tmp))
			break ;
		ft_strdel(&tmp);
	}
	if (tmp)
		ft_strdel(&tmp);
}

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

bool		read_line(t_buff *buff, char **line)
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
