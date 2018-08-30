/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hashtable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 08:31:20 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/29 11:11:23 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static bool		is_command(const char *line)
{
	if (is_start_command(line) || is_end_command(line))
		return (TRUE);
	return (FALSE);
}

static bool		is_room(const char *line)
{
	if (!is_comment(line) && !is_command(line))
	 	return (TRUE);
	return (FALSE);
}

static char		*get_line(const char *data)
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

static void		skip_amount_of_ants(const char *data)
{
	char	*tmp;

	tmp = get_line(data);
	ft_strdel(&tmp);
}


void			create_hashtable(t_htab *htab, t_buff *buff, t_info *info)
{
	skip_amount_of_ants(buff->data);
	while (TRUE)
	{
		buff->line = get_line(buff->data);
		if (is_link(buff->line))
			break ;
		if (is_room(buff->line))
			put_to_hashtable(htab, buff, info);
		ft_strdel(&buff->line);
	}
}
