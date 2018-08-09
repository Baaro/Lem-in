#ifndef TABLE_H
# define TABLE_H
# include <stdbool.h>
# include <stdlib.h>

typedef struct		s_rooms
{
    char			*name;
    size_t			name_len;
    int             id;
	bool			visited;
	bool			start;
	bool			end;
    struct s_rooms  *links;
}					t_rooms;

typedef struct      s_queue
{
        
}                   t_queue;

typedef struct		s_path
{
    size_t			size;
    struct s_rooms 	**rooms;
}					t_path;

#endif