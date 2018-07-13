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

typedef struct      s_errors
{
	bool            a;
	bool			b;
	bool			c;
}                   t_errors;

typedef struct		s_controller
{
	bool			ants;
	bool			commands[2];
	bool			rooms;
	bool			links;
	struct s_errors	errors;
}					t_controller;

typedef struct      s_room
{
	struct s_node   *next;
	struct s_node   *prev;
	char            *name;
	bool            start;
	bool            end;
}                   t_room;

#endif