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

void			print_adjlists(t_adjlists *adjlsts, ssize_t i)
{
	t_adjelem	*tmp;

	tmp = adjlsts->elems[i];
	printf("%s -> ", tmp->room->name);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		printf("%s -> ", tmp->room->name);
	}
	printf("\n");
}

void		print_htab(t_htab *htab, int i)
{
	t_room	*tmp;

	tmp = htab->rooms[i];
	printf("[i:%zu]%s[id:%lu] -> ", tmp->index, tmp->name, tmp->id);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		printf("[%zu]%s[id:%lu] -> ", tmp->index, tmp->name, tmp->id);
	}
	printf("\n");
}