#include "lem_in.h"

t_queue					*init_queue(void)
{
	t_queue *queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
	return (queue);
}

bool					is_empty(t_queue *queue)
{
	return (queue->size == 0 ? TRUE : FALSE);
}

t_adjelem				*dequeue(t_queue *queue)
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

static bool				is_visited(t_adjelem *curr_vertex)
{
	if (curr_vertex->room->visited == TRUE)
		return (TRUE);
	return (FALSE);
}

static bool				in_queue(t_adjelem *curr_vertex)
{
	if (curr_vertex->room->in_queue == TRUE)
		return (TRUE);
	return (FALSE);
}

void					enqueue(t_queue *queue, t_adjelem *curr_vertex)
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

static t_adjelem		*get_vertex(t_htab *htab, t_adjlists *adjlsts, char *name)
{
	unsigned long	id;
	t_adjelem		*vertex;
	t_room			*room;

	id = get_id(htab, name, ft_strlen(name));
	room = hashtable_get(htab, id, name);
	vertex = adjlists_find(adjlsts, room);
	return (vertex);
}

void					mark_as_visited(t_adjelem *curr_vertex)
{
	curr_vertex->room->visited = TRUE;
}

static void				print_queue(t_queue *queue)
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

void				use_bfs(t_adjlists *adjlsts, t_htab *htab)
{
	t_queue		*queue;	
	t_adjelem	*curr_vertex;

	queue = init_queue();
	curr_vertex = get_vertex(htab, adjlsts, htab->start);
	enqueue(queue, curr_vertex);
	while (!is_empty(queue))
	{
		print_queue(queue);
		// printf("Visited: [%s]\n", curr_vertex->room->name);
		// printf("current: %s\n", curr_vertex->room->name);
		while (curr_vertex)
		{
			if (!is_visited(curr_vertex) && !in_queue(curr_vertex))
			{
				mark_as_visited(curr_vertex);	
				enqueue(queue, curr_vertex);
			}
			curr_vertex = curr_vertex->next;
		}
		curr_vertex = dequeue(queue);
		curr_vertex = get_vertex(htab, adjlsts, curr_vertex->room->name);
	}
}
