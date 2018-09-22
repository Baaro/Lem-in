/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:15:46 by vsokolog          #+#    #+#             */
/*   Updated: 2018/09/22 12:15:47 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	hashtab_init(t_htab *htab, t_storage *strg)
{
	if (strg->info->amnt_of_rooms < 1)
		errors_rooms(NO_ROOMS);
	if (!(htab = ft_memset(htab, 0, sizeof(t_htab))))
		errors_memory(CANT_SETZERO, "init_htab");
	htab->size = strg->info->amnt_of_rooms;
	if (!(htab->rooms = (t_room **)malloc(sizeof(t_room *) * htab->size)))
	{
		free(htab->rooms);
		errors_memory(CANT_ALLOCATE_MEM, "init_htab");
	}
	if (!(htab->coords = (t_coord **)malloc(sizeof(t_coord *) * htab->size)))
	{
		free(htab->coords);
		errors_memory(CANT_ALLOCATE_MEM, "init_htab");
	}
	rooms_init(htab->rooms, htab->size);
	coords_init(htab->coords, htab->size);
}
