/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 16:14:16 by vsokolog          #+#    #+#             */
/*   Updated: 2018/09/22 16:14:18 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		queue_clear(t_queue *q)
{
	if (q->front)
		free(q->front);
	free(q);
}

t_queue		*queue_init(void)
{
	t_queue	*q;

	q = (t_queue *)malloc(sizeof(t_queue));
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
	return (q);
}

bool		is_empty(t_queue *q)
{
	return (q->size == 0 ? TRUE : FALSE);
}

t_alst		*dequeue(t_queue *q)
{
	t_node	*tmp;

	tmp = q->front;
	q->size != 0 ? q->size-- : 0;
	if (q->size)
	{
		q->front = q->front->next;
		free(tmp);
	}
	return (q->front->vertex);
}

void		enqueue(t_queue *q, t_alst *curr_v, size_t level)
{
	if (q->front == NULL)
	{
		q->front = (t_node *)malloc(sizeof(t_node));
		q->front->vertex = curr_v;
		q->front->next = NULL;
		q->rear = q->front;
		q->size++;
	}
	else if (!level || !curr_v->room->in_queue)
	{
		q->rear->next = (t_node *)malloc(sizeof(t_node));
		q->rear->next->vertex = curr_v;
		q->rear->next->next = NULL;
		q->rear = q->rear->next;
		q->size++;
	}
	curr_v->room->level = level;
	curr_v->room->in_queue = TRUE;
	curr_v->room->visited = TRUE;
}
