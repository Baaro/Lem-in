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
# define TRUE 1
# define FALSE 0
# define START 1
# define END 0
# define X 0
# define Y 1

typedef struct			s_errors
{
	bool            	a;
	bool				b;
	bool				c;
}						t_errors;

/* This structure is a coordinator for controller */
typedef struct			s_signals 
{
	bool				ants;
	bool				commands[2]; /* start, end */
	bool				coord;
	bool				rooms;
	bool				links;
}						t_signals;

/* Brain of a programm */
typedef struct			s_controller
{
	char				*info;
	char				*data;
	struct s_signals	signals;
	struct s_errors		errors;
}						t_controller;

/* */
typedef struct			s_links
{
	char				*name;
	bool				checked;
	struct s_links		*next;
}						t_links;

/* */
typedef struct			s_vertex
{
	char				*name;
	struct s_vertex		*next;
	struct s_links		**links;
}						t_vertex;

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