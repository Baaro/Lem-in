#include "lem_in.h"

bool		in_queue(t_adjlst *curr_vertex)
{
	if (curr_vertex->room->in_queue == TRUE)
		return (TRUE);
	return (FALSE);
}

t_queue		*queue_init(void)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
	return (queue);
}

bool		is_empty(t_queue *queue)
{
	return (queue->size == 0 ? TRUE : FALSE);
}

t_adjlst	*dequeue(t_queue *queue)
{
	t_node	*tmp;

	tmp = queue->front;
	queue->size != 0 ? queue->size-- : 0;
	if (queue->size)
	{
		queue->front = queue->front->next;
		free(tmp);
	}
	return (queue->front->vertex);
}

void		enqueue(t_queue *queue, t_adjlst *curr_vertex)
{
	if (queue->front == NULL)
	{
		queue->front = (t_node *)malloc(sizeof(t_node));
		queue->front->vertex = curr_vertex;
		queue->front->next = NULL;
		queue->rear = queue->front;
		queue->size++;
	}
	else if (!in_queue(curr_vertex))
	{
		queue->rear->next = (t_node *)malloc(sizeof(t_node));
		queue->rear->next->vertex = curr_vertex;
		queue->rear->next->next = NULL;
		queue->rear = queue->rear->next;
		queue->size++;
	}
	curr_vertex->room->in_queue = TRUE;
}