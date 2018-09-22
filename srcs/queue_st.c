/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 16:14:52 by vsokolog          #+#    #+#             */
/*   Updated: 2018/09/22 16:14:55 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	queue_clear_st(t_q_st *q)
{
	if (q->front)
		free(q->front);
	free(q);
}

bool	is_empty_st(t_q_st *q)
{
	return (q->size == 0 ? TRUE : FALSE);
}

t_q_st	*queue_init_st(void)
{
	t_q_st	*q;

	q = (t_q_st *)malloc(sizeof(t_q_st));
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
	return (q);
}

t_stack	*dequeue_st(t_q_st *q)
{
	t_node_st	*tmp;

	tmp = q->front;
	q->size != 0 ? q->size-- : 0;
	if (q->size)
	{
		q->front = q->front->next;
		free(tmp);
	}
	if (!q->size && q->front)
		q->size++;
	return (q->front->step);
}

void	enqueue_st(t_q_st *q, t_stack *step)
{
	if (q->front == NULL)
	{
		q->front = (t_node_st *)malloc(sizeof(t_node_st));
		q->front->step = step;
		q->front->next = NULL;
		q->rear = q->front;
		q->size++;
	}
	else
	{
		q->rear->next = (t_node_st *)malloc(sizeof(t_node_st));
		q->rear->next->step = step;
		q->rear->next->next = NULL;
		q->rear = q->rear->next;
		q->size++;
	}
}
