/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 16:13:52 by vsokolog          #+#    #+#             */
/*   Updated: 2018/09/22 16:13:54 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	htab_init(t_htab *ht, t_storage *s)
{
	if (s->info->amnt_of_rooms < 1)
		errors_rooms(NO_ROOMS);
	if (!(ht = ft_memset(ht, 0, sizeof(t_htab))))
		errors_memory(CANT_SETZERO, "init_ht");
	ht->size = s->info->amnt_of_rooms;
	if (!(ht->rooms = (t_room **)malloc(sizeof(t_room *) * ht->size)))
	{
		free(ht->rooms);
		errors_memory(CANT_ALLOCATE_MEM, "init_ht");
	}
	if (!(ht->coords = (t_coord **)malloc(sizeof(t_coord *) * ht->size)))
	{
		free(ht->coords);
		errors_memory(CANT_ALLOCATE_MEM, "init_ht");
	}
	rooms_init(ht->rooms, ht->size);
	coords_init(ht->coords, ht->size);
}
