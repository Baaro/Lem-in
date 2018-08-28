/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:58:05 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/28 17:23:31 by vsokolog         ###   ########.fr       */
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
	TWO_ROOMS_AS_THE_SAME_NAME,
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
	char				**room;
	char				*line;
	int					id;
	intmax_t			ants;
	size_t				amnt_of_rooms;
	size_t				num_start_elem;
	size_t				num_end_elem;
	size_t				cnt_rooms;
}						t_info;

typedef struct			s_storage
{
	t_info 				info;
	t_buff				buff;
	t_checks			chcks;
	t_controller		contrllr;
	t_errors			errors;
}						t_storage;

/*
**--------------------Hashtable--------------------
*/
typedef struct		    s_room
{
	char			    *name;
	size_t			    name_len;
	int					id;
	size_t				index;
	bool			    visited;
	bool				in_queue;
	bool			    start;
	bool			    end;
	struct s_room      *next;
}					    t_room;

typedef struct		    s_htab
{
	char				*start;
	char				*end;
	size_t				start_len;
	size_t				end_len;
	size_t			    size;
	struct s_room 	    **rooms;
}					    t_htab;

/*
**--------------------Adjlists---------------------
*/
typedef struct			s_adjelem
{
	struct s_room		*room;
	struct s_adjelem	*next;
}						t_adjelem;

typedef struct			s_adjlists
{
	size_t				size;
	struct s_adjelem	**elems;
}						t_adjlists;

/*
**--------------------Queue-----------------------
*/
typedef struct			s_node
{
//	char				*name;
//	int					id;
	struct s_room		*room;
	struct s_node		*next;
}						t_node;

typedef struct          s_queue
{
	struct s_node		*front;
	struct s_node		*rear;
	size_t				size;
}                       t_queue;

/*
**--------------------Validation-------------------
*/
void	valid_data(t_storage *strg);
bool	valid_ants(t_checks *chcks, const char *line, intmax_t *ants);
bool	valid_commands(t_storage *storage, t_checks *chcks, char *line);
bool	valid_room(const char *line);
bool	is_comment(const char *line);
bool	is_link(const char *line);
bool	is_start_command(const char *line);
bool	is_end_command(const char *line);
bool    room_exists(t_htab *htab, char *name, int id);

/*
**--------------------Errors-----------------------
*/
void	errors_commands(const t_errors error);
void	errors_ants(const t_errors error);
void	errors_rooms(const t_errors error);
void	errors_coordinates(const t_errors error);
void	errors_input(const t_errors error);
void	errors_memory(const t_errors error, const char *error_func);

/*
**--------------------Hashtable--------------------
*/
void	init_hashtable(t_htab *htab, t_storage *strg);
int		get_id(t_htab *htab, char *name, size_t name_len);
void    put_to_hashtable(t_htab *htab, t_buff *buff, t_info *info);
void    create_hashtable(t_htab *htab, t_buff *buff, t_info *info);
void	create_links(t_htab *htab, t_storage *strg);

/*
**-------------------Adjlists----------------------
*/
void	init_adjlists(t_adjlists *adjlists, t_htab *htab);
void	create_adjlists(t_adjlists *adjlsts, t_htab *htab, t_buff *buff);
/*
**--------------------Queue------------------------
*/
t_queue *init_queue(void);
void	enqueue(t_queue *queue, t_htab *htab, int vertex);
int 	dequeue(t_queue *queue);
bool	is_empty(t_queue *queue);

/*
**--------------------Algorithm--------------------
*/
void	use_bfs(t_htab *htab);

/*
**--------------------Auxiliary--------------------
*/
bool	read_line(t_buff *buff, char **line);
void	free_room(char **room);
void	free_all(size_t numargs, ...);
#endif
