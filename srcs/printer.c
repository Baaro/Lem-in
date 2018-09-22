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

void	usage_print(void)
{
	ft_printf("usage:\n");
	ft_printf("[-at] adjacency table;\n");
	ft_printf("[-ht] hash table;\n");
	ft_printf("[-p]  paths which were found;\n");
	ft_printf("[-a]  show all info.\n");
	ft_printf("\n");
}

void	lstpaths_print(t_lp *lp)
{
	t_path		*p;
	t_stack		*tmp;

	p = lp->front;
	ft_printf("\x1b[36mPATHS:\x1b[0m\n");
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
		ft_printf("\n");
		p = p->next;
	}
	ft_printf("\n");
}

void	atab_print(t_atab *at)
{
	t_alst		*tmp;
	ssize_t		i;

	i = -1;
	ft_printf("\n\x1b[35mADJLISTS:\x1b[0m\n");
	while (++i < at->size + 1)
	{
		tmp = at->lsts[i];
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

void	htab_print_room(t_htab *ht)
{
	t_room		*tmp;
	ssize_t		i;

	i = -1;
	ft_printf("\n\x1b[33mHASHTABLE_ROOM:\x1b[0m\n");
	while (++i < ht->size)
	{
		tmp = ht->rooms[i];
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

void	htab_print_coord(t_htab *ht)
{
	t_coord		*tmp;
	ssize_t		i;

	i = -1;
	ft_printf("\n\x1b[33mHASHTABLE_COORDNATES:\x1b[0m\n");
	while (++i < ht->size)
	{
		tmp = ht->coords[i];
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
