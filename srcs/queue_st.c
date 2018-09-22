/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:17:25 by vsokolog          #+#    #+#             */
/*   Updated: 2018/09/22 12:17:27 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		queue_clear_st(t_queue_st *queue)
{
	if (queue->front)
		free(queue->front);
	free(queue);
}

bool		is_empty_st(t_queue_st *queue)
{
	return (queue->size == 0 ? TRUE : FALSE);
}

t_queue_st	*queue_init_st(void)
{
	t_queue_st	*queue;

	queue = (t_queue_st *)malloc(sizeof(t_queue_st));
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
	return (queue);
}

t_stack		*dequeue_st(t_queue_st *queue)
{
	t_node_st	*tmp;

	tmp = queue->front;
	queue->size != 0 ? queue->size-- : 0;
	if (queue->size)
	{
		queue->front = queue->front->next;
		free(tmp);
	}
	if (!queue->size && queue->front)
		queue->size++;
	return (queue->front->step);
}

void		enqueue_st(t_queue_st *queue, t_stack *step)
{
	if (queue->front == NULL)
	{
		queue->front = (t_node_st *)malloc(sizeof(t_node_st));
		queue->front->step = step;
		queue->front->next = NULL;
		queue->rear = queue->front;
		queue->size++;
	}
	else
	{
		queue->rear->next = (t_node_st *)malloc(sizeof(t_node_st));
		queue->rear->next->step = step;
		queue->rear->next->next = NULL;
		queue->rear = queue->rear->next;
		queue->size++;
	}
}
