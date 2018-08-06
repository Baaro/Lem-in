#include "lem_in.h"

static char	*shift_space(char **data)
{
    return (++(*data));
}

static void	valid_x(char **data)
{
	intmax_t	num;

	num = 0;
	while (**data != ' ')
    {
		if (!ft_isdigit(**data))
			errors_coordinates(WRONG_X);
		num = (num * 10) + (**data - '0');
		if (num > INT_MAX)
			errors_coordinates(X_BIGGER_THAN_INTMAX);
        (*data)++;
    }
    *data = shift_space(data);
}

static void	valid_y(char *data)
{
	intmax_t	num;

	num = 0;
	while (*data)
	{
		if (!ft_isdigit(*data))
			errors_coordinates(WRONG_Y);
		num = (num * 10) + (*data - '0');
		if (num > INT_MAX)
			errors_coordinates(Y_BIGGER_THAN_INTMAX);
		data++;
	}
}

static bool	valid_coord_of_room(char *data)
{
	valid_x(&data);
	valid_y(data);
	return (TRUE);
}

static bool	valid_name_of_room(char **data)
{ 
    if (**data == 'L')
		errors_rooms(L_CHAR_AT_ROOM_NAME);
    while (**data)
    {
    	if (!ft_isprint(**data))
			errors_rooms(UNPRINTBALE_NAME);
		if (**data == ' ')
			break ;
		(*data)++;
    }
    *data = shift_space(data);
	return (TRUE);
}

bool		valid_room(char *data)
{
	if (valid_name_of_room(&data))
		if (valid_coord_of_room(data))
			return (TRUE);
	return (FALSE);
}
