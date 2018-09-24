/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 16:13:37 by vsokolog          #+#    #+#             */
/*   Updated: 2018/09/22 16:13:39 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		errors_ants(const t_errors e)
{
	ft_printf("\x1b[31mERROR:\x1b[0m ");
	if (e == TOO_FEW_ANTS)
		ft_printf("The value of ants is bigger than MAX_INT!\n");
	else if (e == WRONG_VALUE_OF_ANTS)
		ft_printf("The value of ants is not a number!\n");
	else if (e == ANTS_IS_NEG)
		ft_printf("The value of ants is negative!\n");
	else if (e == ANTS_IS_ZERO)
		ft_printf("The value of ants is zero!\n");
	exit(EXIT_FAILURE);
}

void		errors_rooms(const t_errors e)
{
	ft_printf("\x1b[31mERROR:\x1b[0m ");
	if (e == L_CHAR_AT_ROOM_NAME)
		ft_printf("There is 'L' character at the beginning of name of room!\n");
	else if (e == UNPRINTBALE_NAME)
		ft_printf("The name of room is unprintable!\n");
	else if (e == NO_ROOMS)
		ft_printf("There are no rooms in the map!\n");
	else if (e == TWO_ROOMS_HAVE_THE_SAME_NAME)
		ft_printf("Two rooms have the same name!\n");
	else if (e == TWO_ROOMS_HAVE_THE_SAME_COORDS)
		ft_printf("Two rooms have the same coordinates!\n");
	else if (e == UNKNOWN_ROOM)
		ft_printf("Some room is linked to unknown room!\n");
	else if (e == THERE_ARE_NO_LINKS_WITH_START)
		ft_printf("There are no links with start!\n");
	else if (e == START_EQUAL_END)
		ft_printf("The start and the end have the same room!\n");
	else if (e == DASH_AT_THE_NAME_OF_ROOM)
		ft_printf("The name of room has \'-\'!\n");		
	exit(EXIT_FAILURE);
}

void		errors_links(const t_errors e)
{
	ft_printf("\x1b[31mERROR:\x1b[0m ");
	if (e == THERE_ARE_NO_LINKS)
		ft_printf("There are no links in map!\n");
	else if (e == WRONG_LINKS)
		ft_printf("There is some wrong link in map!\n");
	exit(EXIT_FAILURE);
}

void		errors_coordinates(const t_errors e)
{
	ft_printf("\x1b[31mERROR:\x1b[0m ");
	if (e == WRONG_X)
		ft_printf("There is wrong [X] coordinate!\n");
	else if (e == WRONG_Y)
		ft_printf("There is wrong [Y] coordinate!\n");
	else if (e == X_BIGGER_THAN_INTMAX)
		ft_printf("The [X] coordinate is bigger than INT_MAX!\n");
	else if (e == Y_BIGGER_THAN_INTMAX)
		ft_printf("The [Y] coordinate is bigger than INT_MAX!\n");
	exit(EXIT_FAILURE);
}
