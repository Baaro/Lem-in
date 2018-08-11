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

bool				is_comment(const char *data)
{
	if (*data == '#' && !is_start_command(data) && !is_end_command(data))
		return (TRUE);
	return (FALSE);
}
