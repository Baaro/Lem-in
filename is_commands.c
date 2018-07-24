/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:12:31 by vsokolog          #+#    #+#             */
/*   Updated: 2018/07/24 15:12:34 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool		is_start_command(char *data)
{
	if (ft_strcmp(data, "##start") == 0)
		return (TRUE)
	return (FALSE);
}

bool		is_end_command(char *data)
{
	if (ft_strcmp(data, "##end") == 0)
		return (TRUE)
	return (FALSE);
}
