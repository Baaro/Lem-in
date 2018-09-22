/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:58:05 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/29 12:35:00 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
# define LEM_IN
# include "../libft/includes/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>

# define TRUE 1
# define FALSE 0

# define CHECKED 1
# define UNCHECKED 0

# define NAME 0
# define X 1
# define Y 2

# define FIRST_ROOM 0
# define SECOND_ROOM 1

# define INPUT 0


/*
**--------------------Errors-----------------------
*/
typedef enum			e_errors
{
	/*
	** Ants
	*/
	WRONG_VALUE_OF_ANTS = 1,
	ANTS_IS_ZERO,
	ANTS_IS_NEG,
	TOO_FEW_ANTS,

	/* 
	** Commands
	*/
	NO_START_COMMAND,
	NO_END_COMMAND,
	TWO_START_COMMANDS,
	TWO_END_COMMANDS,
	/*
	** Coordinates
	*/
	WRONG_X,
	WRONG_Y,
	X_BIGGER_THAN_INTMAX,
	Y_BIGGER_THAN_INTMAX,

	/* 
	** Rooms
	*/
	L_CHAR_AT_ROOM_NAME,
	UNPRINTBALE_NAME,
	NO_ROOMS,
	TWO_ROOMS_HAVE_THE_SAME_NAME,
	TWO_ROOMS_HAVE_THE_SAME_COORDS,
	THERE_ARE_NO_LINKS_WITH_START,
	START_EQUAL_END,
	UNKNOWN_ROOM,	
	/* 
	** Links
	*/
	WRONG_LINKS,
	THERE_ARE_NO_LINKS,
	WRONG_INPUT,

	/* 
	** Memory
	*/
	CANT_ALLOCATE_MEM,
	CANT_SETZERO,

	/*
	** Algorithm
	*/
	THERE_ARE_NO_POSSIBLE_WAYS,
}						t_errors;

/*
**--------------------Storage----------------------
*/
typedef enum			e_controller
{
	READ = 1,
	VALID_ROOM,
	STOP_READ,
	GO_VALID,
}						t_controller;

typedef struct			s_checks
{
	bool				ants_check;
	bool				start_check;
	bool				end_check;
}						t_checks;

typedef struct 			s_buff
{
	int					fd;
	char				*line;
	char				*data;
}						t_buff;

typedef struct			s_info
{
	char				**room_coord;
	char				*line;
	char				*room;
	char				*first_room;
	char				*second_room;
	char				*coord;
	intmax_t			ants;
	size_t				amnt_of_rooms;
	size_t				num_start_elem;
	size_t				num_end_elem;
	size_t				cnt_rooms;
	unsigned int		id_coord;
	unsigned int		id_room;
	unsigned long		id_first;
	unsigned long		id_second;
}						t_info;

typedef struct			s_storage
{
	t_checks			chcks;
	t_controller		contrllr;
	t_errors			errors;
	struct s_info 		*info;
	struct s_buff		*buff;
}						t_storage;

/*
**--------------------Room----------------------------
*/
typedef struct		    s_room
{
	char			    *name;
	bool			    visited;
	bool				in_queue;
	bool			    start;
	bool			    end;
	size_t			    name_len;
	unsigned long		id;
	size_t				index;
	size_t				level;
	struct s_room      	*next;
}					    t_room;

/*
**--------------------Coordinates---------------------
*/
typedef struct			s_coord
{
	char				*x_y;
	size_t				x_y_len;
	unsigned long		id;
	struct s_coord		*next;
}						t_coord;

/*
**--------------------Hashtable-----------------------
*/
typedef struct		    s_htab
{
	char				*start;
	char				*end;
	size_t				start_len;
	size_t				end_len;
	size_t			    size;
	struct s_room 	    **rooms;
	struct s_coord		**coords;
}					    t_htab;

/*
**--------------------Adjlists------------------------
*/
typedef struct			s_adjlst
{
	struct s_room		*room;
	struct s_adjlst		*next;
}						t_adjlst;

/*
**--------------------Adjtable------------------------
*/
typedef struct			s_adjtab
{
	size_t				size;
	struct s_adjlst		**lsts;
}						t_adjtab;

/*
**--------------------Stack---------------------------
*/
typedef struct 			s_stack
{
	intmax_t			ant;
	struct s_adjlst		*vertex;
	struct s_stack		*next;
}						t_stack;

/*
**--------------------Queue---------------------------
*/
typedef struct			s_node
{
	struct s_adjlst		*vertex;
	struct s_node		*next;
}						t_node;

typedef struct			s_node_st
{
	struct s_stack		*step;
	struct s_node_st	*next;
}						t_node_st;

typedef struct          s_queue
{
	size_t				size;
	struct s_node		*front;
	struct s_node		*rear;
}                       t_queue;

typedef struct          s_queue_st
{
	size_t				size;
	struct s_node_st	*front;
	struct s_node_st	*rear;
}                       t_queue_st;

/*
**--------------------Path----------------------------
*/
typedef	struct			s_path
{
	size_t 				steps;
	struct s_stack		*step;
	struct s_path		*next;
}						t_path;

/*
**--------------------Lstspaths-----------------------
*/
typedef struct			s_lstpaths
{
	size_t				paths;
	intmax_t			ants_in_graph;
	intmax_t			final_ant;
	struct s_path		*front;
	struct s_path		*rear;
}						t_lstpaths;

typedef struct			s_args
{
	bool				ht;
	bool				at;
	bool				p;
	bool				a;
}						t_args;
/*
**--------------------Validation--------------------
*/
void			storage_init(t_storage *strg);
void			valid_data(t_storage *strg);
bool			valid_ants(t_checks *chcks, const char *line, intmax_t *ants);
bool			valid_commands(t_storage *storage, t_checks *chcks, char *line);
bool			valid_room(const char *line);
bool			is_comment(const char *line);
bool			is_link(const char *line);
bool			is_commands(const char *line);
bool			is_start_command(const char *data);
bool			is_end_command(const char *data);
bool			is_room(const char *line);
bool			is_wrong_command(const char *line);
bool			is_garbage(const char *line);
bool			is_duplicate(const char *f_name, const char *s_name);

/*
**--------------------Errors-----------------------
*/
void			errors_commands(const t_errors error);
void			errors_ants(const t_errors error);
void			errors_rooms(const t_errors error);
void			errors_coordinates(const t_errors error);
void			errors_input(const t_errors error);
void			errors_memory(const t_errors error, const char *error_func);
void			errors_algorithm(const t_errors error);
void			errors_links(const t_errors error);

/*
**--------------------Room-------------------------
*/
void			rooms_init(t_room **rooms, size_t size);
void			room_create(t_htab *htab, t_info *info);
bool			room_exists(t_htab *htab, char *name, unsigned long	id);
void			room_set(t_htab *htab, t_room *room, t_info *info);
char			**room_get(char *line);
void			rooms_clear(t_room **rooms, size_t size);

/*
**--------------------Coordinates-------------------
*/
void			coords_init(t_coord **coord, size_t size);
void   		 	coord_create(t_htab *htab, t_info *info);
bool    		coord_exists(t_htab *htab, char *x_y, unsigned long id);
void			coord_set(t_coord *coord, t_info *info);
char    		*coord_get(char *x, char *y);

/*
**--------------------Hashtable---------------------
*/
void			hashtab_init(t_htab *htab, t_storage *strg);
void    		hashtab_create(t_htab *htab, t_buff *buff, t_info *info);
bool			hashtab_exists(t_htab *htab, char *name, unsigned long id);
void		    hashtab_set(t_htab *htab, t_info *info);
t_room			*hashtab_get(t_htab *htab, unsigned long id, char *name);
unsigned long	get_id(t_htab *htab, char *name, size_t name_len);

/*
**--------------------Adjlist------------------------
*/
void			adjlst_init(t_adjlst **lists, size_t size);
bool			adjlst_exists(const t_adjlst *elem, const t_room *room);
void			*adjlst_put(t_adjlst *elem, const t_room *room);

/*
**--------------------Adjtable----------------------
*/
void			adjtab_init(t_adjtab *adjtab, size_t size);
void			adjtab_create(t_adjtab *at, t_htab *ht, t_buff *b, t_info *i);
bool         	adjtab_exists(t_adjtab *adjtab, t_room *room);
bool			adjtab_set(t_adjtab *adjtab, t_htab *htab, t_info *info);
void         	adjtab_put(t_adjtab *adjtab, const t_room *room);
t_adjlst		*adjtab_get(t_adjtab *adjtab, t_room *room);

/*
**--------------------Info--------------------------
*/
void			info_init(t_info **info);
void			info_get_rooms(t_info *info, t_htab *htab, t_buff *buff);
void			info_get_links(t_info *info, char *line);
void			info_clear_links(t_info *info);
void			info_clear_rooms(t_info *info);

/*
**--------------------Buff--------------------------
*/
void			buff_init(t_buff **buff);

/*
**--------------------Queue------------------------
*/
t_queue			*queue_init(void);
void			enqueue(t_queue *queue, t_adjlst *curr_vertex, size_t level);
t_adjlst		*dequeue(t_queue *queue);
bool			is_empty(t_queue *queue);
void			queue_clear(t_queue *queue);
void			queue_print(t_queue *queue);

bool			is_empty_st(t_queue_st *queue);
t_queue_st		*queue_init_st(void);
void			enqueue_st(t_queue_st *queue, t_stack *v);
t_stack			*dequeue_st(t_queue_st *queue);
void			queue_clear_st(t_queue_st *queue);
void			queue_print_st(t_queue_st *queue);

/*
**--------------------Lstspaths---------------------
*/
void		    lstpaths_init(t_lstpaths *lp);
void			lstpaths_create(t_lstpaths *lp, t_adjtab *at, t_htab *ht);
void			lstpaths_put(t_lstpaths *lp, t_path *p);
void			lstpaths_print(t_lstpaths *lp);
/*
**--------------------Path------------------------
*/
t_path			*path_init(void);
bool			path_create(t_path *p, t_adjtab *at, t_htab *ht);
bool			paths_exist(t_adjtab *at, t_htab *ht);
void			path_put(t_path *p, t_adjlst *vertex);
void			path_del(t_path *p);
bool			found_room(const char *to_find, const char *found);

/*
**--------------------BFS--------------------------
*/
void			bfs(t_adjtab *adjtab, t_htab *htab);
/*
**--------------------Send_ants--------------------------
*/
void	    	send_ants(t_lstpaths *lp, intmax_t ants, char *end);
void			atgraph(t_lstpaths *lp, t_queue_st *q, intmax_t *ants, char *end);
void			antsput(t_lstpaths *lp, t_queue_st *q, intmax_t *a, bool *aig);
void			antsshft(t_lstpaths *lp, t_queue_st *q, intmax_t *ants, char *e);
void			antsstep(t_lstpaths *lp, t_queue_st *q, intmax_t *ants, char *end);
void			step(t_queue_st *q, bool clear);

/*
**--------------------Vertexes--------------------
*/
t_adjlst		*get_vertex(t_htab *htab, t_adjtab *adjtab, char *name);
t_adjlst		*get_nearest_vertex(t_adjtab *at, t_htab *ht, char *name);

/*
**--------------------Reader--------------------
*/
bool			read_line(t_buff *buff, char **line);
char			*get_line(const char *data);
void			save_data(char **data, char *line);

/*
**--------------------Args--------------------
*/
void			args_init(t_args *args);
bool			args_analyze(t_args *args, int argc, char **argv);
void			args_print(t_args *args, t_lstpaths *lp, t_adjtab *at, t_htab *ht);
void			print_all(t_lstpaths *lp, t_adjtab *at, t_htab *ht);
void			usage_print(void); 
void			hashtable_print_room(t_htab *htab);
void			hashtable_print_coord(t_htab *htab);
void			adjtab_print(t_adjtab *adjtab);
void			lstpaths_print(t_lstpaths *lp);

bool			is_a(char *argv);
bool			is_ht(char *argv);
bool			is_at(char *argv);
bool			is_p(char *argv);
bool			is_u(char *argv);

void			init_storage(t_storage *strg);
void			remember_start_end(t_htab *htab, t_room *room);
void			skip_amount_of_ants(const char *data);
void			clear(t_htab *ht, t_adjtab *at, t_storage *strg, t_lstpaths *lp);


#endif
