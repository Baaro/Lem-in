#include "lem_in.h"

static t_queue  *init_queue(void)
{
	t_queue *queue = (t_queue*)malloc(sizeof(t_queue));
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
	return (queue);
}

static void     enqueue(t_queue *queue, t_adj_lists *adj_lists, int vertex)
{
	if (queue->front == NULL)
	{
		queue->front = (t_node *)malloc(sizeof(t_node));
		queue->front->vertex = vertex;
		queue->front->next = NULL;		
		queue->rear = queue->front;
		queue->size++;
	}
	else if (!adj_lists->rooms[vertex]->in_queue)
	{
		queue->rear->next = (t_node *)malloc(sizeof(t_node));
		queue->rear->next->vertex = vertex;	
		queue->rear->next->next = NULL;
		queue->rear = queue->rear->next;
		queue->size++;
	}
	adj_lists->rooms[vertex]->in_queue = TRUE;
}

static bool		is_empty(t_queue *queue)
{
	return (queue->size == 0 ? TRUE : FALSE);
}

static int		dequeue(t_queue *queue)
{
	t_node	*tmp;
	int		vertex;

	tmp = queue->front;
	vertex = queue->front->vertex;
	queue->front = queue->front->next;
	free(tmp);
	queue->size--;
	return (vertex);
}

static int		get_start_vertex(t_adj_lists *adj_lists, char *name, size_t name_len)
{
	return (get_id(adj_lists, name, name_len));
}

// static void		visit_adj_rooms(t_adj_lists *adj_lists, int vertex)
// {
// 	if (adj_lists->rooms[v]->visited)
// 	{
// 		return ;
// 	}
// 	while (adj_lists->rooms[vertex]->next_room != NULL)
// }

static void		print_queue(t_queue *queue, t_adj_lists *adj_lists)
{
	t_node	*tmp;

	printf("\nqueue contains := {");
	tmp = queue->front;
	while (tmp)
	{
		if (tmp->next != NULL)
			printf("%s, ", adj_lists->rooms[tmp->vertex]->name);
		else
			printf("%s", adj_lists->rooms[tmp->vertex]->name);			
		tmp = tmp->next;
	}
	printf("}\n");
	printf("\n");
}

void            use_bfs(t_adj_lists *adj_lists)
{
	t_queue	*queue;
	// t_paths	*tree;
	t_rooms	*current_room;
	int		current_vertex;

	// tree = init_tree();
	queue = init_queue();
	current_vertex = get_start_vertex(adj_lists, adj_lists->start, adj_lists->start_len);
	enqueue(queue, adj_lists, current_vertex);
	adj_lists->rooms[queue->front->vertex]->visited = TRUE;
	while (!is_empty(queue))
	{
		print_queue(queue, adj_lists);
		printf("Visited: %s\n", adj_lists->rooms[current_vertex]->name);
		current_vertex = dequeue(queue);
		current_room = adj_lists->rooms[current_vertex];
		while (current_room)
		{
			if (current_room->visited == FALSE)
			{
				current_room->visited = TRUE;
				enqueue(queue, adj_lists, current_room->id);
			}
			current_room = current_room->next_room;
		}
	}
	// printf("queue := {");
	// while (!is_empty(queue))
	// {
	// 	printf("%s ", adj_lists->rooms[queue->front->vertex]->name);
	// 	dequeue(queue);
	// }
	// printf("}\n");
}