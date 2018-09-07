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
}

void			adjtab_print(t_adjtab *adjtab, ssize_t i)
{
	t_adjlst	*tmp;

	tmp = adjtab->lsts[i];
	if (tmp->room && tmp->room->name)
	{
		printf("[%s] -> ", tmp->room->name);
		while (tmp->next)
		{
			tmp = tmp->next;		
			if (tmp->room && tmp->room->name)
				printf("%s -> ", tmp->room->name);
		}
		printf("\n");		
	}
}

void		hashtable_print_room(t_htab *htab, int i)
{
	t_room	*tmp;

	tmp = htab->rooms[i];
	if (tmp && tmp->name)
	{
		printf("[id:%lu] %s -> ", tmp->id, tmp->name);
		while (tmp->next)
		{
			tmp = tmp->next;			
			if (tmp && tmp->name)		
				printf("[id:%lu] %s -> ", tmp->id, tmp->name);
		}
		printf("\n");
	}
}

void		hashtable_print_coord(t_htab *htab, int i)
{
	t_coord	*tmp;

	tmp = htab->coords[i];
	if (tmp && tmp->x_y)
	{
		printf("[id:%zu] %s -> ", tmp->id, tmp->x_y);
		while (tmp->next)
		{
			tmp = tmp->next;
			if (tmp && tmp->x_y)
				printf("[id:%zu] %s -> ", tmp->id, tmp->x_y);
		}
		printf("\n");		
	}
}