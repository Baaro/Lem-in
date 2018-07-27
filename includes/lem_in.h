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
# include <stdio.h> // delete it

# define MAX_ANTS 100000

# define TRUE 1
# define FALSE 0

# define START 1
# define END 0

# define VALID 1
# define INVALID 0

# define CHECKED 1
# define UNCHECKED 0

# define X 1
# define Y 0

# define ERROR 2
# define OUTPUT 1
# define INPUT 0


typedef enum			e_errors
{
	/* Ants */
	wrong_value_ants = 1,
	ants_is_zero,
	ants_is_neg,
	too_few_ants,
	/* Ants */

	/* Commands */
	no_start_command,
	no_end_command,
	unknown_command,
	/* Commands */

	/* Coordinates */
	wrong_coordinates_x,
	wrong_coordinates_y,
	/* Coordinates */

	/* Links */
	wrong_links,
	/* Links */
}						t_errors;

typedef enum			e_flags
{
	read_next_data = 1,	
	add_elem_to_hashtable,
	end_read_data,
}						t_flags;

typedef struct			s_checks
{
	bool				ants_check;
	bool				comm_check[2];
}						t_checks;

typedef struct 			s_buffer
{
	char				*data;
	char				*info;
}						t_buffer;


typedef struct			s_map
{
	intmax_t			ants;
	struct s_buffer		buffer;
	struct s_checks		checks;
	t_flags				flag;
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

/*--------------------Errors--------------------*/
void		errors_commands(const t_errors error);
void		errors_ants(const t_errors error);
// void		errors_rooms(const t_errors error);
/*--------------------Errors--------------------*/

bool 		read_data_from_input(t_map *map);

/*--------------------Validation--------------------*/
void		valid_data(t_map *map, t_flags *flag);

void		check_ants(t_checks *checks, const char *data, intmax_t *ants);

bool		is_link(char *data);

void		check_start_command(const char *data, t_checks *checks);
void		check_end_command(const char *data, t_checks *checks);

bool		is_start_command(const char *data);
bool		is_end_command(const char *data);
/*--------------------Validation--------------------*/



/*--------------------Algorithm--------------------*/
/*--------------------Algorithm--------------------*/


#endif
