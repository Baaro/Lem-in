#include "lem_in.h"

void		queue_clear(t_queue *queue)
{
	if (queue->front)
		free(queue->front);
	free(queue);
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

void		enqueue(t_queue *queue, t_adjlst *v, size_t level)
{
	if (queue->front == NULL)
	{
		queue->front = (t_node *)malloc(sizeof(t_node));
		queue->front->vertex = v;
		queue->front->next = NULL;
		queue->rear = queue->front;
		queue->size++;
	}
	else if (!level || !v->room->in_queue)
	{
		queue->rear->next = (t_node *)malloc(sizeof(t_node));
		queue->rear->next->vertex = v;
		queue->rear->next->next = NULL;
		queue->rear = queue->rear->next;
		queue->size++;
	}
	v->room->level = level;
	v->room->in_queue = TRUE;
	v->room->visited = TRUE;
}

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

t_queue_st		*queue_init_st(void)
{
	t_queue_st	*queue;

	queue = (t_queue_st *)malloc(sizeof(t_queue_st));
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
	return (queue);
}

t_stack			*dequeue_st(t_queue_st *queue)
{
	t_node_st	*tmp;

	tmp = queue->front;
	queue->size != 0 ? queue->size-- : 0;
	if (queue->size)
	{
		queue->front = queue->front->next;
		free(tmp);
	}
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
