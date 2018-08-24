#ifndef TABLE_H
# define TABLE_H
# include <stdbool.h>
# include <stdlib.h>

typedef struct		    s_rooms
{
	char			    *name;
	size_t			    name_len;
	unsigned long		id;
	bool			    visited;
	bool				in_queue;
	bool			    start;
	bool			    end;
	struct s_rooms      *nxt_hsh_room;	// Next element in hashtable
	struct s_rooms		*nxt_adj_room;		// Next elem in adj_list
}					    t_rooms;

typedef struct		    s_table
{
	char				*start;
	char				*end;
	size_t				start_len;
	size_t				end_len;
	size_t			    size;
	struct s_rooms 	    **rooms;
}					    t_table;

typedef struct			s_node
{
	// char				*name;
	// int					v;
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
	// size_t				size;
	// struct s_rooms		**paths;
// }						t_paths;

#endif