/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_start_end_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:59:35 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/10 15:59:36 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool		is_start_command(const char *data)
{
	if (ft_strcmp(data, "##start") == 0)
		return (TRUE);
	return (FALSE);
}

bool		is_end_command(const char *data)
{
	if (ft_strcmp(data, "##end") == 0)
		return (TRUE);
	return (FALSE);
}
