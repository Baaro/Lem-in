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
# include "table.h"
# include <stdbool.h>
# include <limits.h>
# include <stdio.h> // delete it

# define MAX_ANTS 100000

# define TRUE 1
# define FALSE 0

# define CHECKED 1
# define UNCHECKED 0

# define NAME 0
# define X 1
# define Y 2

# define INPUT 0

# define EXIT_FAILURE 1

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
	/* Rooms */

	/* Links */
	WRONG_LINKS,
	/* Links */
	WRONG_INPUT,
	CANT_ALLOCATE_MEM,	
}						t_errors;

typedef enum			e_controller
{
	READ_DATA = 1,	
	ADD_ELEM_TO_TABLE,
	STOP_READ_DATA,
	GO_VALID,
}						t_controller;

typedef struct			s_checks
{
	bool				ants_check;
	bool				start_check;
	bool				end_check;
}						t_checks;

typedef struct 			s_buffer
{
	char				*data;
	char				*info;
}						t_buffer;


typedef struct			s_map
{
	intmax_t			ants;
	size_t				amount_of_rooms;
	size_t				num_start_elem;
	size_t				num_end_elem;
	t_buffer			buffer;
	t_checks			checks;
	t_controller		controller;
	t_errors			errors;
}						t_map;


/*
**-------------------Errors-------------------------
*/
void			errors_commands(const t_errors error);
void			errors_ants(const t_errors error);
void			errors_rooms(const t_errors error);
void			errors_coordinates(const t_errors error);
void			errors_input(const t_errors error);
void			errors_memory(const t_errors error);

/*
**--------------------Validation--------------------
*/
void			valid_map(t_map *map);
bool			valid_ants(t_checks *checks, const char *data, intmax_t *ants);
bool			valid_commands(t_map *map, t_checks *checks, char *data);
bool			valid_room(char *data);
bool			is_comment(const char *data);
bool			is_link(char *data);
bool			is_start_command(const char *data);
bool			is_end_command(const char *data);


/*--------------------Algorithm--------------------*/

/*--------------------Algorithm--------------------*/


#endif
