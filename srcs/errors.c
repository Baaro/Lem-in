/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:59:15 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/28 09:30:18 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		errors_ants(const t_errors error)
{
	if (error == TOO_FEW_ANTS)
		ft_printf("\x1b[31mERROR:\x1b[0m The value of ants is bigger than MAX_INT!\n");
	else if (error == WRONG_VALUE_OF_ANTS)
		ft_printf("\x1b[31mERROR:\x1b[0m The value of ants is not a number!\n");
	else if (error == ANTS_IS_NEG)
		ft_printf("\x1b[31mERROR:\x1b[0m The value of ants is negative!\n");
	else if (error == ANTS_IS_ZERO)
		ft_printf("\x1b[31mERROR:\x1b[0m The value of ants is zero!\n");
	exit(EXIT_FAILURE);
}

void		errors_rooms(const t_errors error)
{
	if (error == L_CHAR_AT_ROOM_NAME)
		ft_printf("\x1b[31mERROR:\x1b[0m There is 'L' character at the beginning of name of room!\n");
	else if (error == UNPRINTBALE_NAME)
		ft_printf("\x1b[31mERROR:\x1b[0m The name of room is unprintable!\n");
	else if (error == NO_ROOMS)
		ft_printf("\x1b[31mERROR:\x1b[0m There are no rooms in the map!\n");
	else if (error == TWO_ROOMS_HAVE_THE_SAME_NAME)
		ft_printf("\x1b[31mERROR:\x1b[0m Two rooms have the same name!\n");
	else if (error == TWO_ROOMS_HAVE_THE_SAME_COORDS)
		ft_printf("\x1b[31mERROR:\x1b[0m Two rooms have the same coordinates!\n");
	else if (error == UNKNOWN_ROOM)
		ft_printf("\x1b[31mERROR:\x1b[0m Some room is linked to unknown room!\n");
	else if (error == THERE_ARE_NO_LINKS_WITH_START)
		ft_printf("\x1b[31mERROR:\x1b[0m There are no links with start!\n");
	else if (error == START_EQUAL_END)
		ft_printf("\x1b[31mERROR:\x1b[0m The start and the end have the same room!\n");
	exit(EXIT_FAILURE);
}

void		errors_links(const t_errors error)
{
	if (error == THERE_ARE_NO_LINKS)
		ft_printf("\x1b[31mERROR:\x1b[0m There are no links in map!\n");
	else if (error == WRONG_LINKS)
		ft_printf("\x1b[31mERROR:\x1b[0m There is some wrong link in map!\n");		
	exit(EXIT_FAILURE);
}

void		errors_coordinates(const t_errors error)
{
	if (error == WRONG_X)
		ft_printf("\x1b[31mERROR:\x1b[0m There is wrong [X] coordinate!\n");
	else if (error == WRONG_Y)
		ft_printf("\x1b[31mERROR:\x1b[0m There is wrong [Y] coordinate!\n");
	else if (error == X_BIGGER_THAN_INTMAX)
		ft_printf("\x1b[31mERROR:\x1b[0m The [X] coordinate is bigger than INT_MAX!\n");
	else if (error == Y_BIGGER_THAN_INTMAX)
		ft_printf("\x1b[31mERROR:\x1b[0m The [Y] coordinate is bigger than INT_MAX!\n");
	exit(EXIT_FAILURE);
}

void		errors_commands(const t_errors error)
{
	if (error == NO_START_COMMAND)
		ft_printf("\x1b[31mERROR:\x1b[0m There is no [##start] command!\n");
	else if (error == NO_END_COMMAND)
		ft_printf("\x1b[31mERROR:\x1b[0m There is no [##end] command!\n");
	else if (error == TWO_START_COMMANDS)
		ft_printf("\x1b[31mERROR:\x1b[0m There are two [##start] commands!\n");
	else if (error == TWO_END_COMMANDS)
		ft_printf("\x1b[31mERROR:\x1b[0m There are two [##end] commands!\n");
	else if (error == UNKNOWN_COMMAND)
		ft_printf("\x1b[31mERROR:\x1b[0m There is an [##unknown] commands!\n");
	exit(EXIT_FAILURE);
}

void		errors_input(const t_errors error)
{
	if (error == WRONG_INPUT)
		ft_printf("\x1b[31mERROR:\x1b[0m There is an invalid file on input!\n");
	exit(EXIT_FAILURE);
}

void		errors_memory(const t_errors error, const char *error_func)
{
	if (error == CANT_ALLOCATE_MEM)
		ft_printf("\x1b[31mERROR:\x1b[0m Cannot allocate memory! The Problem is in func: [%s]!\n", error_func);
	else if (error == CANT_SETZERO)
		ft_printf("\x1b[31mERROR:\x1b[0m Cannot use memset! The Problem is in func: [%s]!\n", error_func);
	exit(EXIT_FAILURE);
}

void		errors_algorithm(const t_errors error)
{
	if (error == THERE_ARE_NO_POSSIBLE_WAYS)
		ft_printf("\x1b[31mERROR:\x1b[0m There are no possible ways!\n");
	exit(EXIT_FAILURE);
}

