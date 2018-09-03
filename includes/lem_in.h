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
# include <stdio.h> // delete it

# define MAX_ANTS 100000

# define TRUE 1
# define FALSE 0

# define CHECKED 1
# define UNCHECKED 0

# define NAME 0
# define X 1
# define Y 2

# define FIRST 0
# define SECOND 1

# define INPUT 0

# define EXIT_FAILURE 1

/*
**--------------------Errors-----------------------
*/
typedef enum			e_errors
{
	/* Ants */
	WRONG_VALUE_OF_ANTS = 1,
	ANTS_IS_ZERO,
	ANTS_IS_NEG,
	TOO_FEW_ANTS,
	/* Ants */

	/* Commands */
	NO_START_COMMAND,
	NO_END_COMMAND,
	/* Commands */

	/* Coordinates */
	WRONG_X,
	WRONG_Y,
	X_BIGGER_THAN_INTMAX,
	Y_BIGGER_THAN_INTMAX,
	/* Coordinates */

	/* Rooms */
	L_CHAR_AT_ROOM_NAME,
	UNPRINTBALE_NAME,
	NO_ROOMS,
	TWO_ROOMS_HAVE_THE_SAME_NAME,
	TWO_ROOMS_HAVE_THE_SAME_COORDS,
	/* Rooms */

	/* Links */
	WRONG_LINKS,
	UNKNOWN_ROOM,
	/* Links */

	WRONG_INPUT,
	/* Mem */
	CANT_ALLOCATE_MEM,
	CANT_SETZERO,
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
	char				*line;
	char				*data;
}						t_buff;

typedef struct			s_info
{
	char				**line;
	char				*room;
	char				*coord;
	unsigned long		id_room;
	unsigned long		id_coord;
	intmax_t			ants;
	size_t				amnt_of_rooms;
	size_t				num_start_elem;
	size_t				num_end_elem;
	size_t				cnt_rooms;
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
**--------------------Room---------------------------
*/
typedef struct		    s_room
{
	char			    *name;
	size_t			    name_len;
	unsigned long		id;
	size_t				index;
	bool			    visited;
	bool				in_queue;
	bool			    start;
	bool			    end;
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
**--------------------Queue-----------------------
*/
typedef struct			s_node
{
	struct s_adjlst		*vertex;
	struct s_node		*next;
}						t_node;

typedef struct          s_queue
{
	size_t				size;
	struct s_node		*front;
	struct s_node		*rear;
}                       t_queue;

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

/*
**--------------------Errors-----------------------
*/
void			errors_commands(const t_errors error);
void			errors_ants(const t_errors error);
void			errors_rooms(const t_errors error);
void			errors_coordinates(const t_errors error);
void			errors_input(const t_errors error);
void			errors_memory(const t_errors error, const char *error_func);

/*
**--------------------Room-------------------------
*/
void			rooms_init(t_room **rooms, size_t size);
void			room_create(t_htab *htab, t_info *info);
bool			room_exists(t_htab *htab, char *name, unsigned long	id);
void			room_set(t_room *room, t_info *info);
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
void			coords_clear(t_coord **coords, size_t size);

/*
**--------------------Hashtable---------------------
*/
void			hashtab_init(t_htab *htab, t_storage *strg);
void    		hashtab_create(t_htab *htab, t_buff *buff, t_info *info);
void		    hashtab_set(t_htab *htab, t_info *info);
t_room			*hashtab_get(t_htab *htab, unsigned long id, char *name);
unsigned long	get_id(t_htab *htab, char *name, size_t name_len);
void			hashtab_clear(t_htab *htab);

/*
**--------------------Adjlist--------------------------
*/
void			adjlst_init(t_adjlst **lists, size_t size);
bool			adjlst_exists(const t_adjlst *elem, const t_room *room);
void			*adjlst_put(t_adjlst *elem, const t_room *room);
// void			adjlist_clear();

/*
**--------------------Adjtable----------------------
*/
void			adjtab_init(t_adjtab *adjtab, t_htab *htab);
void			adjtab_create(t_adjtab *at, t_htab *ht, t_buff *b, t_info *i);
bool         	adjtab_exists(t_adjtab *adjtab, t_room *room);
void			adjtab_set(t_adjtab *adjtab, t_htab *htab, char **rooms);
void         	adjtab_put(t_adjtab *adjtab, const t_room *room);
t_adjlst		*adjtab_get(t_adjtab *adjtab, t_room *room);
void			adjtab_print(t_adjtab *adjtab, ssize_t i);
void			adjtab_clear(t_adjtab *adjtab);

/*
**--------------------Info--------------------------
*/
void			info_init(t_info **info);
void			info_get(t_info *info, t_htab *htab, t_buff *buff);
void			info_clear(t_info *info);

/*
**--------------------Buff--------------------------
*/
void			buff_clear(t_buff *buff);
void			buff_init(t_buff **buff);

/*
**--------------------Queue------------------------
*/
t_queue			*queue_init(void);
void			enqueue(t_queue *queue, t_adjlst *curr_vertex);
t_adjlst		*dequeue(t_queue *queue);
bool			is_empty(t_queue *queue);
bool			in_queue(t_adjlst *curr_vertex);
void			print_queue(t_queue *queue);

/*
**--------------------Bfs--------------------
*/
void			bfs(t_adjtab *adjtab, t_htab *htab);

/*
**--------------------Auxiliary--------------------
*/
bool			read_line(t_buff *buff, char **line);
void			free_room(char **room);
void     		free_dblarray(char **str);
void			room_clear(t_room **rooms, size_t size);
void			free_all(size_t numargs, ...);

void			hashtable_print_room(t_htab *htab, int i);
void			hashtable_print_coord(t_htab *htab, int i);

void			print_adjtable(t_adjtab *adjtab, ssize_t i);
void			init_buff(t_buff **buff);

void			init_storage(t_storage *strg);

void			remember_start_end(t_htab *htab, t_room *room);
void			skip_amount_of_ants(const char *data);
char			*get_line(const char *data);
void			remember_start_end(t_htab *htab, t_room *room);
bool			is_exists(t_htab *htab, char *name, unsigned long id);
char			**get_rooms(char *data);

#endif
