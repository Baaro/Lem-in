#include "lem_in.h"

// static t_queue  *init_queue(void)
// {
// 	t_queue *queue = (t_queue*)malloc(sizeof(t_queue));
// 	queue->front = NULL;
// 	queue->rear = NULL;
// 	queue->size = 0;
// 	return (queue);
// }

// static void     enqueue(t_queue *queue, t_table *table, int vertex)
// {
// 	if (queue->front == NULL)
// 	{
// 		queue->front = (t_node *)malloc(sizeof(t_node));
// 		queue->front->vertex = vertex;
// 		queue->front->next = NULL;		
// 		queue->rear = queue->front;
// 		queue->size++;
// 	}
// 	else if (!table->rooms[vertex]->in_queue)
// 	{
// 		queue->rear->next = (t_node *)malloc(sizeof(t_node));
// 		queue->rear->next->vertex = vertex;	
// 		queue->rear->next->next = NULL;
// 		queue->rear = queue->rear->next;
// 		queue->size++;
// 	}
// 	table->rooms[vertex]->in_queue = TRUE;
// }

// static bool		is_empty(t_queue *queue)
// {
// 	return (queue->size == 0 ? TRUE : FALSE);
// }

// static int		dequeue(t_queue *queue)
// {
// 	t_node	*tmp;
// 	int		vertex;

// 	tmp = queue->front;
// 	vertex = queue->front->vertex;
// 	queue->front = queue->front->next;
// 	free(tmp);
// 	queue->size--;
// 	return (vertex);
// }

// static int		get_start_vertex(t_table *table, char *name, size_t name_len)
// {
// 	return (get_id(table, name, name_len));
// }

// static void		visit_adj_rooms(t_table *table, int vertex)
// {
// 	if (table->rooms[v]->visited)
// 	{
// 		return ;
// 	}
// 	while (table->rooms[vertex]->next_room != NULL)
// }

// static void		print_queue(t_queue *queue, t_table *table)
// {
// 	t_node	*tmp;

// 	printf("\nqueue contains := {");
// 	tmp = queue->front;
// 	while (tmp)
// 	{
// 		if (tmp->next != NULL)
// 			printf("%s, ", table->rooms[tmp->vertex]->name);
// 		else
// 			printf("%s", table->rooms[tmp->vertex]->name);			
// 		tmp = tmp->next;
// 	}
// 	printf("}\n");
// 	printf("\n");
// }

// void            use_bfs(t_table *table)
// {
// 	t_queue	*queue;
// 	// t_paths	*tree;
// 	t_rooms	*current_room;
// 	int		current_vertex;

// 	// tree = init_tree();
// 	queue = init_queue();
// 	current_vertex = get_start_vertex(table, table->start, table->start_len);
// 	enqueue(queue, table, current_vertex);
// 	table->rooms[queue->front->vertex]->visited = TRUE;
	// while (!is_empty(queue))
	// {
	// 	print_queue(queue, table);
	// 	printf("Visited: %s\n", table->rooms[current_vertex]->name);
	// 	current_vertex = dequeue(queue);
	// 	current_room = table->rooms[current_vertex];
	// 	while (current_room)
	// 	{
	// 		if (current_room->visited == FALSE)
	// 		{
	// 			current_room->visited = TRUE;
	// 			enqueue(queue, table, current_room->id);
	// 		}
	// 		current_room = current_room->next_room;
	// 	}
	// }
	// printf("queue := {");
	// while (!is_empty(queue))
	// {
	// 	printf("%s ", table->rooms[queue->front->vertex]->name);
	// 	dequeue(queue);
	// }
	// printf("}\n");
// }