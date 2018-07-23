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
# define VALID 1
# define INVALID 0
# define NEGATIVE -1
# define X 1
# define Y 0

typedef enum			e_errors
{
	/* Ants */
	wrong_value_ants = 1
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
	bool				ants;
	bool				commands[2]; /* start, end */
	bool				coord;
	bool				rooms;
	bool				links;
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

#endif
