/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:44:23 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/29 17:44:25 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			print_queue(t_queue *queue)
{
	t_node	*tmp;

	printf("\nqueue contains := {");
	tmp = queue->front;
	while (tmp)
	{
		if (tmp->next != NULL)
			printf("%s, ", tmp->vertex->room->name);
		else
			printf("%s", tmp->vertex->room->name);
		tmp = tmp->next;
	}
	printf("}\n");
	printf("\n");
}

void			adjtab_print(t_adjtab *adjtab, ssize_t i)
{
	t_adjlst	*tmp;

	tmp = adjtab->lsts[i];
	while (tmp && tmp->room)
	{
		if (tmp->room)
			printf("%s -> ", tmp->room->name);
		tmp = tmp->next;
	}
	printf("\n");
}

void		hashtable_print_room(t_htab *htab, int i)
{
	t_room	*tmp;

	tmp = htab->rooms[i];
	printf("[%zu]%s[id:%lu] -> ", tmp->index, tmp->name, tmp->id);
	while (tmp && tmp->name)
	{
		if (ft_strcmp(htab->start, tmp->name) == 0)
			printf("\nS: %s[%lu]\n", tmp->name, tmp->id);
		if (ft_strcmp(htab->end, tmp->name) == 0)
			printf("\nE: %s[%lu]\n", tmp->name, tmp->id);
		printf("[%zu]%s[id:%lu] -> ", tmp->index, tmp->name, tmp->id);
		tmp = tmp->next;
	}
	printf("\n");
}

void		hashtable_print_coord(t_htab *htab, int i)
{
	t_coord	*tmp;

	tmp = htab->coords[i];
	printf("[%zu]%s -> ", tmp->id, tmp->x_y);
	while (tmp && tmp->x_y)
	{

		printf("[%zu]%s -> ", tmp->id, tmp->x_y);
		tmp = tmp->next;
	}
	printf("\n");
}