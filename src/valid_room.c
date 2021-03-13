/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:58:11 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/10 15:58:12 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	valid_x(char **line)
{
	intmax_t	num;
	bool		neg;

	num = 0;
	neg = FALSE;
	if (**line == '-')
	{
		(*line)++;
		neg = TRUE;
	}
	if (!ft_isdigit(**line))
		errors_coordinates(WRONG_X);
	while (**line != ' ')
	{
		if (!ft_isdigit(**line))
			errors_coordinates(WRONG_X);
		num = (num * 10) + (**line - '0');
		if (num > INT_MAX)
			errors_coordinates(X_BIGGER_THAN_INTMAX);
		(*line)++;
	}
	if (neg)
		num *= -1;
	(*line)++;
}

static void	valid_y(char *line)
{
	intmax_t	num;
	bool		neg;

	num = 0;
	neg = FALSE;
	if (*line == '-')
	{
		line++;
		neg = TRUE;
	}
	if (!ft_isdigit(*line))
		errors_coordinates(WRONG_Y);
	while (*line)
	{
		if (!ft_isdigit(*line))
			errors_coordinates(WRONG_Y);
		num = (num * 10) + (*line - '0');
		if (num > INT_MAX)
			errors_coordinates(Y_BIGGER_THAN_INTMAX);
		line++;
	}
	if (neg)
		num *= -1;
}

static bool	valid_coord_of_room(char *line)
{
	valid_x(&line);
	valid_y(line);
	return (TRUE);
}

static bool	valid_name_of_room(char **line)
{
	if (**line == 'L')
		errors_rooms(L_CHAR_AT_ROOM_NAME);
	while (**line)
	{
		if (**line == '-')
			errors_rooms(DASH_AT_THE_NAME_OF_ROOM);
		if (!ft_isprint(**line))
			errors_rooms(UNPRINTBALE_NAME);
		if (**line == ' ')
			break ;
		(*line)++;
	}
	(*line)++;
	return (TRUE);
}

bool		valid_room(const char *line)
{
	char	*tmp;

	tmp = (char*)line;
	if (valid_name_of_room(&tmp))
		if (valid_coord_of_room(tmp))
			return (TRUE);
	return (FALSE);
}
