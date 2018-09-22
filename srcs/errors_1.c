/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:14:02 by vsokolog          #+#    #+#             */
/*   Updated: 2018/09/22 13:14:03 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		errors_ants(const t_errors error)
{
	ft_printf("\x1b[31mERROR:\x1b[0m ");
	if (error == TOO_FEW_ANTS)
		ft_printf("The value of ants is bigger than MAX_INT!\n");
	else if (error == WRONG_VALUE_OF_ANTS)
		ft_printf("The value of ants is not a number!\n");
	else if (error == ANTS_IS_NEG)
		ft_printf("The value of ants is negative!\n");
	else if (error == ANTS_IS_ZERO)
		ft_printf("The value of ants is zero!\n");
	exit(EXIT_FAILURE);
}

void		errors_rooms(const t_errors error)
{
	ft_printf("\x1b[31mERROR:\x1b[0m ");
	if (error == L_CHAR_AT_ROOM_NAME)
		ft_printf("There is 'L' character at the beginning of name of room!\n");
	else if (error == UNPRINTBALE_NAME)
		ft_printf("The name of room is unprintable!\n");
	else if (error == NO_ROOMS)
		ft_printf("here are no rooms in the map!\n");
	else if (error == TWO_ROOMS_HAVE_THE_SAME_NAME)
		ft_printf("Two rooms have the same name!\n");
	else if (error == TWO_ROOMS_HAVE_THE_SAME_COORDS)
		ft_printf("Two rooms have the same coordinates!\n");
	else if (error == UNKNOWN_ROOM)
		ft_printf("Some room is linked to unknown room!\n");
	else if (error == THERE_ARE_NO_LINKS_WITH_START)
		ft_printf("There are no links with start!\n");
	else if (error == START_EQUAL_END)
		ft_printf("The start and the end have the same room!\n");
	exit(EXIT_FAILURE);
}

void		errors_links(const t_errors error)
{
	ft_printf("\x1b[31mERROR:\x1b[0m ");
	if (error == THERE_ARE_NO_LINKS)
		ft_printf("There are no links in map!\n");
	else if (error == WRONG_LINKS)
		ft_printf("There is some wrong link in map!\n");
	exit(EXIT_FAILURE);
}

void		errors_coordinates(const t_errors error)
{
	ft_printf("\x1b[31mERROR:\x1b[0m ");
	if (error == WRONG_X)
		ft_printf("There is wrong [X] coordinate!\n");
	else if (error == WRONG_Y)
		ft_printf("There is wrong [Y] coordinate!\n");
	else if (error == X_BIGGER_THAN_INTMAX)
		ft_printf("The [X] coordinate is bigger than INT_MAX!\n");
	else if (error == Y_BIGGER_THAN_INTMAX)
		ft_printf("The [Y] coordinate is bigger than INT_MAX!\n");
	exit(EXIT_FAILURE);
}
