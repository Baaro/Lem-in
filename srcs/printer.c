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

void		usage_print(void)
{
	ft_printf("usage:\n");
	ft_printf("[-at] adjacency table;\n");
	ft_printf("[-ht] hash table;\n");
	ft_printf("[-p]  paths which were found;\n");
	ft_printf("[-a]  show all info.\n");
	printf("\n");
}

void		lstpaths_print(t_lstpaths *lp)
{
	t_path		*p;
	t_stack		*tmp;

	p = lp->front;
	while (p)
	{
		tmp = p->step;		
		if (tmp)
			ft_printf("steps: %zu\n", p->steps);
		while (tmp && tmp->vertex->room)
		{
			ft_printf("|%s|\n", tmp->vertex->room->name);
			tmp = tmp->next;
		}
		p = p->next;
	}
}

void			adjtab_print(t_adjtab *adjtab)
{
	t_adjlst	*tmp;
	ssize_t		i;

	i = -1;
	ft_printf("\n\x1b[35mADJLISTS\x1b[0m\n");	
	while (++i < adjtab->size)
	{
		tmp = adjtab->lsts[i];
		if (tmp->room && tmp->room->name)
		{
			ft_printf("[%s] -> ", tmp->room->name);
			while (tmp->next)
			{
				tmp = tmp->next;		
				if (tmp->room && tmp->room->name)
					ft_printf("%s -> ", tmp->room->name);
			}
			ft_printf("\n");		
		}
	}
	ft_printf("\n");	
}

void		hashtable_print_room(t_htab *htab)
{
	t_room		*tmp;
	ssize_t		i;

	i = -1;
	ft_printf("\n\x1b[33mHASHTABLE_ROOM\x1b[0m\n");
	while (++i < htab->size)
	{
		tmp = htab->rooms[i];
		if (tmp && tmp->name)
		{
			ft_printf("[id:%lu] %s -> ", tmp->id, tmp->name);
			while (tmp->next)
			{
				tmp = tmp->next;			
				if (tmp && tmp->name)		
					ft_printf("[id:%lu] %s -> ", tmp->id, tmp->name);
			}
			ft_printf("\n");
		}
	}
}

void		hashtable_print_coord(t_htab *htab)
{
	t_coord		*tmp;
	ssize_t		i;

	i = -1;
	ft_printf("\n\x1b[33mHASHTABLE_COORDNATES\x1b[0m\n");
	while (++i < htab->size)
	{
		tmp = htab->coords[i];
		if (tmp && tmp->x_y)
		{
			ft_printf("[id:%zu] %s -> ", tmp->id, tmp->x_y);
			while (tmp->next)
			{
				tmp = tmp->next;
				if (tmp && tmp->x_y)
					ft_printf("[id:%zu] %s -> ", tmp->id, tmp->x_y);
			}
			ft_printf("\n");		
		}
	}
}
