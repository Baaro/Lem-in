/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:59:15 by vsokolog          #+#    #+#             */
/*   Updated: 2018/07/23 16:59:16 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		errors_ants(const t_errors error)
{
	if (error == too_few_ants)
		ft_printf("\x1b[31mERROR:\x1b[0m Value of ants is bigger than [100 000]!\n");
	else if (error == wrong_value_ants)
		ft_printf("\x1b[31mERROR:\x1b[0m Value of ants is not a number!\n");
	else if (error == ants_is_neg)
		ft_printf("\x1b[31mERROR:\x1b[0m Value of ants is [negative]!\n");
	else if (error == ants_is_zero)
		ft_printf("\x1b[31mERROR:\x1b[0m Value of ants is [zero]!\n");
	exit(FAILURE);
}

void		errors_rooms(const t_errors error)
{
	if (error == l_char_at_the_start_of_room_name)
		ft_printf("\x1b[31mERROR:\x1b[0m There is 'L' character at the start of a room name!\n");
	else if (error == name_of_room_is_unprintable)
		ft_printf("\x1b[31mERROR:\x1b[0m The name of room is unprintable!\n");
	exit(FAILURE);
}

void		errors_coordinates(const t_errors error)
{
	if (error == wrong_coordinates_x)
		ft_printf("\x1b[31mERROR:\x1b[0m There is wrong [X] coordinates!\n");
	else if (error == wrong_coordinates_y)
		ft_printf("\x1b[31mERROR:\x1b[0m There is wrong [Y] coordinates!\n");
	exit(FAILURE);
}

void		errors_commands(const t_errors error)
{
	if (error == no_start_command)
		ft_printf("\x1b[31mERROR:\x1b[0m There is no [##start] command!\n");
	else if (error == no_end_command)
		ft_printf("\x1b[31mERROR:\x1b[0m There is no [##end] command!\n");
	exit(FAILURE);
}