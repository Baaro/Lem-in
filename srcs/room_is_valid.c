#include "lem_in.h"

static char	*shift_space(char **data)
{
    return (++(*data));
}

static void	valid_x(char **data)
{ 
	while (**data != ' ')
    {
		if (!ft_isdigit(**data))
			errors_coordinates(wrong_coordinates_x);
        (*data)++;
    }
    *data = shift_space(data);
}

static void	valid_y(char *data)
{
	while (*data)
	{
		if (!ft_isdigit(*data))
			errors_coordinates(wrong_coordinates_y);
		data++;
	}
}

static void	valid_coord_of_room(char *data)
{
	valid_x(&data);
	valid_y(data);
}

static void	valid_name_of_room(char **data)
{ 
	if (!ft_isprint(**data))
		errors_rooms(name_of_room_is_unprintable);
	else if (**data == 'L')
		errors_rooms(l_char_at_the_start_of_room_name);
	while (ft_isalnum(**data))
		(*data)++;
    *data = shift_space(data);
}

bool		room_is_valid(char *data)
{
	valid_name_of_room(&data);
	valid_coord_of_room(data);
	return (TRUE);
}