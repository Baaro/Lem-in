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

#ifndef LEM_IN_H
# define LEM_IN_H
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
	WRONG_VALUE_OF_ANTS = 1,
	DASH_AT_THE_NAME_OF_ROOM,
	ANTS_IS_ZERO,
	ANTS_IS_NEG,
	TOO_FEW_ANTS,
	NO_START_COMMAND,
	NO_END_COMMAND,
	TWO_START_COMMANDS,
	TWO_END_COMMANDS,
	WRONG_X,
	WRONG_Y,
	X_BIGGER_THAN_INTMAX,
	Y_BIGGER_THAN_INTMAX,
	L_CHAR_AT_ROOM_NAME,
	UNPRINTBALE_NAME,
	NO_ROOMS,
	TWO_ROOMS_HAVE_THE_SAME_NAME,
	TWO_ROOMS_HAVE_THE_SAME_COORDS,
	THERE_ARE_NO_LINKS_WITH_START,
	START_EQUAL_END,
	UNKNOWN_ROOM,
	WRONG_LINKS,
	THERE_ARE_NO_LINKS,
	WRONG_INPUT,
	CANT_ALLOCATE_MEM,
	CANT_SETZERO,
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

typedef struct			s_buff
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
	unsigned int		id_coord;
	unsigned int		id_room;
	unsigned long		id_first;
	unsigned long		id_second;
	intmax_t			ants;
	size_t				amnt_of_rooms;
	size_t				num_start_elem;
	size_t				num_end_elem;
	size_t				cnt_rooms;
}						t_info;

typedef struct			s_storage
{
	t_checks			c;
	t_controller		contrllr;
	t_errors			errors;
	t_info				*info;
	t_buff				*buff;
}						t_storage;
/*
**--------------------Room----------------------------
*/
typedef struct			s_room
{
	char				*name;
	bool				visited;
	bool				in_queue;
	bool				shortest_path;
	bool				start;
	bool				end;
	unsigned long		id;
	size_t				name_len;
	size_t				index;
	size_t				level;
	struct s_room		*next;
}						t_room;
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
typedef struct			s_htab
{
	char				*start;
	char				*end;
	size_t				start_len;
	size_t				end_len;
	ssize_t				size;
	struct s_room		**rooms;
	struct s_coord		**coords;
}						t_htab;
/*
**--------------------Adjlists------------------------
*/
typedef struct			s_alst
{
	struct s_room		*room;
	struct s_alst		*next;
}						t_alst;
/*
**--------------------Adjtable------------------------
*/
typedef struct			s_atab
{
	ssize_t				size;
	struct s_alst		**lsts;
}						t_atab;
/*
**--------------------Stack---------------------------
*/
typedef struct			s_stack
{
	intmax_t			ant;
	struct s_alst		*vertex;
	struct s_stack		*next;
}						t_stack;
/*
**--------------------Queue---------------------------
*/
typedef struct			s_node
{
	struct s_alst		*vertex;
	struct s_node		*next;
}						t_node;

typedef struct			s_node_st
{
	struct s_stack		*step;
	struct s_node_st	*next;
}						t_node_st;

typedef struct			s_queue
{
	size_t				size;
	struct s_node		*front;
	struct s_node		*rear;
}						t_queue;

typedef struct			s_q_st
{
	size_t				size;
	struct s_node_st	*front;
	struct s_node_st	*rear;
}						t_q_st;
/*
**--------------------Path----------------------------
*/
typedef	struct			s_path
{
	size_t				steps;
	struct s_stack		*step;
	struct s_path		*next;
}						t_path;
/*
**--------------------Lstspaths-----------------------
*/
typedef struct			s_lp
{
	size_t				paths;
	intmax_t			ants_in_graph;
	intmax_t			final_ant;
	struct s_path		*front;
	struct s_path		*rear;
}						t_lp;

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
void					storage_init(t_storage *s);
void					valid_data(t_storage *s);
bool					valid_ants(t_checks *c, char *line, intmax_t *ants);
bool					valid_cmmnds(t_storage *s, t_checks *c, char *line);
bool					valid_room(const char *line);
bool					is_comment(const char *line);
bool					is_link(const char *line);
bool					is_commands(const char *line);
bool					is_start_command(const char *data);
bool					is_end_command(const char *data);
bool					is_room(const char *line);
bool					is_wrong_command(const char *line);
bool					is_garbage(const char *line);
bool					is_duplicate(const char *f_name, const char *s_name);
bool					is_start(t_htab *ht, t_alst *v);
bool					is_end(t_htab *ht, t_alst *v);
/*
**--------------------Errors-----------------------
*/
void					errors_commands(const t_errors e);
void					errors_ants(const t_errors e);
void					errors_rooms(const t_errors e);
void					errors_coordinates(const t_errors e);
void					errors_input(const t_errors e);
void					errors_memory(const t_errors e, const char *error_func);
void					errors_algorithm(const t_errors e);
void					errors_links(const t_errors e);
/*
**--------------------Room-------------------------
*/
void					rooms_init(t_room **rooms, ssize_t size);
void					room_create(t_htab *ht, t_info *info);
bool					room_exists(t_htab *ht, char *name, unsigned long id);
void					room_set(t_htab *ht, t_room *room, t_info *info);
char					**room_get(char *line);
/*
**--------------------Coordinates-------------------
*/
void					coords_init(t_coord **coord, ssize_t size);
void					coord_create(t_htab *ht, t_info *info);
bool					coord_exists(t_htab *ht, char *x_y, unsigned long id);
void					coord_set(t_coord *coord, t_info *info);
char					*coord_get(char *x, char *y);
/*
**--------------------Hashtable---------------------
*/
void					htab_init(t_htab *ht, t_storage *s);
void					htab_create(t_htab *ht, t_buff *b, t_info *i);
void					htab_set(t_htab *ht, t_info *i);
t_room					*htab_get(t_htab *ht, unsigned long id, char *name);
unsigned long			get_id(t_htab *ht, char *name, size_t name_len);
/*
**--------------------Adjlist------------------------
*/
void					alst_init(t_alst **lsts, ssize_t size);
bool					alst_exists(const t_alst *elem, const t_room *room);
void					*alst_put(t_alst *elem, const t_room *room);

/*
**--------------------Adjtable----------------------
*/
void					atab_init(t_atab *at, ssize_t size);
void					atab_crte(t_atab *at, t_htab *ht, t_buff *b, t_info *i);
bool					atab_exists(t_atab *at, t_room *room);
bool					atab_set(t_atab *at, t_htab *htab, t_info *info);
void					atab_put(t_atab *at, const t_room *room);
t_alst					*atab_get(t_atab *a, t_room *room);
/*
**--------------------Info--------------------------
*/
void					info_init(t_info **info);
void					info_get_rooms(t_info *info, t_htab *htab);
void					info_get_links(t_info *info, char *line);
void					info_clear_links(t_info *info);
void					info_clear_rooms(t_info *info);
/*
**--------------------Buff--------------------------
*/
void					buff_init(t_buff **b);
/*
**--------------------Queue------------------------
*/
t_queue					*queue_init(void);
void					enqueue(t_queue *q, t_alst *curr_v, size_t level);
t_alst					*dequeue(t_queue *q);
bool					is_empty(t_queue *q);
void					queue_clear(t_queue *q);
void					queue_print(t_queue *q);
/*
**--------------------Queue_st------------------------
*/
bool					is_empty_st(t_q_st *queue);
t_q_st					*queue_init_st(void);
void					enqueue_st(t_q_st *queue, t_stack *v);
t_stack					*dequeue_st(t_q_st *queue);
void					queue_clear_st(t_q_st *queue);
void					queue_print_st(t_q_st *queue);
/*
**--------------------Lstspaths---------------------
*/
void					lstpaths_init(t_lp *lp);
void					lstpaths_create(t_lp*lp, t_atab *at, t_htab *ht);
void					lstpaths_put(t_lp*lp, t_path *p);
void					lstpaths_print(t_lp *lp);
/*
**--------------------Path------------------------
*/
t_path					*path_init(void);
bool					path_create(t_path *p, t_atab *at, t_htab *ht);
bool					paths_exist(t_atab *at, t_htab *ht);
void					path_put(t_path *p, t_alst *vertex);
void					path_del(t_path *p);
bool					found_room(const char *to_find, const char *found);
/*
**--------------------BFS--------------------------
*/
void					bfs(t_atab *at, t_htab *ht);
/*
**--------------------Send_ants--------------------
*/
void					send_ants(t_lp *lp, intmax_t ants, char *end);
void					atgraph(t_lp *lp, t_q_st *q, intmax_t *ants, char *e);
void					antsput(t_lp *lp, t_q_st *q, intmax_t *a, bool *aig);
void					antsshft(t_lp *lp, t_q_st *q, intmax_t *ants, char *e);
void					antstep(t_lp *lp, t_q_st *q, intmax_t *ants, char *end);
void					step(t_q_st *q, bool clear);
/*
**--------------------Vertexes--------------------
*/
t_alst					*get_vertex(t_htab *ht, t_atab *aat, char *name);
t_alst					*get_nearest_vertex(t_atab *at, t_htab *ht, t_alst *v);
/*
**--------------------Reader----------------------
*/
bool					read_line(t_buff *buff, char **line);
char					*get_line(const char *data);
void					save_data(char **data, char *line);
/*
**--------------------Args------------------------
*/
void					args_init(t_args *a);
bool					args_analyze(t_args *a, int argc, char **argv);
void					args_print(t_args *a, t_lp *lp, t_atab *at, t_htab *ht);
void					print_all(t_lp *lp, t_atab *at, t_htab *ht);
void					usage_print(void);
void					htab_print_room(t_htab *ht);
void					htab_print_coord(t_htab *ht);
void					atab_print(t_atab *at);
void					lstpaths_print(t_lp *lp);
bool					is_a(char *argv);
bool					is_ht(char *argv);
bool					is_at(char *argv);
bool					is_p(char *argv);
bool					is_u(char *argv);
/*
**--------------------Aux--------------------
*/
void					init_storage(t_storage *s);
void					remember_start_end(t_htab *htab, t_room *room);
void					skip_amount_of_ants(const char *data);
void					clear(t_htab *ht, t_atab *at, t_storage *s, t_lp *lp);

#endif
