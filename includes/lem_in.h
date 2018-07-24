/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:58:05 by vsokolog          #+#    #+#             */
/*   Updated: 2018/07/10 12:58:08 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
# define LEM_IN
# include "../libft/includes/libft.h"
# include <stdbool.h>

# define MAX_ANTS 100000

# define TRUE 1
# define FALSE 0

# define START 1
# define END 0

# define CHECKED 1
# define UNCHECKED 0

# define FOUND 1
# define NOTFOUND 0

# define VALID 1
# define INVALID 0

# define X 1
# define Y 0

# define OUTPUT 1
# define INPUT 0

# define READ_DATA 0
# define CAN_ADD_TO_HASHTABLE -1
# define END_READ 1

typedef enum			e_errors
{
	/* Ants */
	wrong_value_ants = 1,
	ants_is_zero,
	ants_is_neg,
	too_few_ants,
	/* Ants */

	/* Commands */
	wrong_start_command,
	wrong_end_command,
	unknown_command,
	no_end,
	no_start,
	/* Commands */

	/* Coordinates */

	/* Coordinates */

	/* Links */

	/* Links */
}						t_errors;

/* This structure is a coordinator for controller */
typedef struct			s_checks
{
	bool				ants_check;
	bool				comm_check[2];
	bool				comm_find[2];
	// bool				comm_check[2];
	// bool				coord_check;
	// bool				rooms_check;
	// bool				comm_find[2];
	// bool				links_find;
}						t_checks;

typedef struct 			s_buffer
{
	char				*data;
	char				*info;
}						t_buffer;

/* Brain of the programm */
typedef struct			s_map
{
	intmax_t			ants;
	struct s_buffer		buffer;
	struct s_checks		checks;
	t_errors			errors;
}						t_map;

/* */
// typedef struct			s_rooms
// {
// 	char				*name;
// 	size_t				ant;
// 	struct s_links		*next;
// }						t_rooms;

// /* */
// typedef struct			s_map
// {
// 	size_t				size;
// 	struct s_rooms		**rooms;
// }						t_map;

// typedef struct      	s_node
// {
// 	struct s_node   	*next;
// 	struct s_node   	*prev;
// 	char            	*name;
// 	bool				checked;
// 	bool            	start;
// 	bool            	end;
// }                   	t_node;

bool		is_link(const char *data);
bool		valid_data(t_map *map);

/* Errors */
void		errors_commands(const t_errors error);
void		errors_ants(const t_errors error);
/* Errors */

bool 		read_data_from_input(t_map *map);

bool		is_start_command(char *data);
bool		is_end_command(char *data);


bool		valid_first_name_room(char **data);
bool		valid_second_name_room(char **data);

#endif
