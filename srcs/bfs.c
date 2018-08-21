#include "lem_in.h"

static t_queue  *init_queue(void)
{
	t_queue *queue = (t_queue*)malloc(sizeof(t_queue));
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
	return (queue);
}

static void     enqueue(t_queue *queue, t_adj_lists *adj_lists, t_rooms *room)
{
	if (queue->front == NULL)
	{
		queue->front = (t_node *)malloc(sizeof(t_node));
		queue->front->room = (t_rooms *)malloc(sizeof(t_rooms));
		queue->front->room = room;
		queue->rear = queue->front;
	}
	else
	{
		queue->rear->next = (t_node *)malloc(sizeof(t_node));
		queue->rear->next->room = (t_rooms *)malloc(sizeof(t_rooms));
		queue->rear->next->room = room;
		queue->rear->next->next = NULL;
		queue->rear = queue->rear->next;
	}
	queue->size++;	
}

static bool		is_empty(t_queue *queue)
{
	return (queue->size == 0 ? TRUE : FALSE);
}

static void		dequeue(t_queue *queue, t_adj_lists *adj_lists, int *id)
{
	t_node	*tmp;

	tmp = queue->front;
	queue->front = queue->front->next;
	free(tmp);
	*id = get_id(adj_lists, queue->front->room->name, queue->front->room->name_len);
	queue->size--;
}

void            use_bfs(t_map *map, t_adj_lists *adj_lists)
{
	t_queue *queue;
	int     id;

	queue = init_queue();
	id = get_id(adj_lists, adj_lists->start, adj_lists->start_len);
	enqueue(queue, adj_lists, adj_lists->rooms[id]);
	// printf("Before: q := {%s, %s, %s};\n", queue->front->room->name,
	// 										queue->front->next->room->name,
	// 														queue->rear->room->name);
	// dequeue(queue, adj_lists, &id);
	// printf("After: q := {%s, %s}.\n", queue->front->room->name,
	// 														queue->front->next->room->name);													
	while (!is_empty(queue))
	{
		while ((adj_lists->rooms[id]->next_room) != NULL)
		{
			if (adj_lists->rooms[id]->visited == FALSE)
				adj_lists->rooms[id]->visited = TRUE;
			enqueue(queue, adj_lists->rooms[id]);
		}
		dequeue(queue, adj_lists, &id);
	}
}