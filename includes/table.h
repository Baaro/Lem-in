#ifndef TABLE_H
# define TABLE_H
# include <stdbool.h>
# include <stdlib.h>

typedef struct		    s_rooms
{
	char			    *name;
	size_t			    name_len;
	int                 id;
	bool			    visited;
	bool				in_queue;
	bool			    start;
	bool			    end;
	struct s_rooms      *next_room;
}					    t_rooms;
typedef struct		    s_adj_lists
{
	char				*start;
	char				*end;
	size_t			    size;
	size_t				start_len;
	size_t				end_len;
	struct s_rooms 	    **rooms;
}					    t_adj_lists;
typedef struct			s_node
{
	struct s_rooms		*room;
	struct s_node		*next;
}						t_node;
typedef struct          s_queue
{
	struct s_node		*front;
	struct s_node		*rear;
	size_t				size;
}                       t_queue;


// typedef struct			s_paths
// {
// 	size_t				size;
// 	struct s_rooms		**paths; 
// }						t_path;
// typedef struct			s_visited_table
// {
// 	struct	s_rooms		**rooms;
// }						t_visited_table;

#endif