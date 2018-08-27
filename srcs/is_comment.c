/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_comment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:59:08 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/10 15:59:09 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool				is_comment(const char *line)
{
	if (*line == '#' && !is_start_command(line) && !is_end_command(line))
		return (TRUE);
	return (FALSE);
}
