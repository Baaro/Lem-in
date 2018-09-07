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

static char	*shift_space(char **line)
{
    return (++(*line));
}

static void	valid_x(char **line)
{
	intmax_t	num;

	num = 0;
	if (**line == '-')
		line++;
	while (**line != ' ')
    {		
		if (!ft_isdigit(**line))
			errors_coordinates(WRONG_X);
		num = (num * 10) + (**line - '0');
		if (num > INT_MAX)
			errors_coordinates(X_BIGGER_THAN_INTMAX);
        (*line)++;
    }
    *line = shift_space(line);
}

static void	valid_y(char *line)
{
	intmax_t	num;

	num = 0;
	if (*line == '-')
		line++;
	while (*line)
	{
		if (!ft_isdigit(*line))
			errors_coordinates(WRONG_Y);
		num = (num * 10) + (*line - '0');
		if (num > INT_MAX)
			errors_coordinates(Y_BIGGER_THAN_INTMAX);
		line++;
	}
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
    	if (!ft_isprint(**line))
			errors_rooms(UNPRINTBALE_NAME);
		if (**line == ' ')
			break ;
		(*line)++;
    }
    *line = shift_space(line);
	return (TRUE);
}

bool		valid_room(const char *line)
{
	char *tmp;

	tmp = (char*)line;
	if (valid_name_of_room(&tmp))
		if (valid_coord_of_room(tmp))
			return (TRUE);
	return (FALSE);
}
