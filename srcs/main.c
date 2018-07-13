#include "lem_in.h"

static void init_controller(t_controller *controller)
{
	*controller = (t_controller){0, {0,0}, 0, 0, {0, 0, 0}};
}

static void	init_room(t_room *room)
{
	*room = (t_room){NULL, NULL, NULL, 0, 0};
}

static char	*read_data_from_input(char *data)
{
	free(data);

}

static bool	controller(t_controller signals)
{
	 
}

static bool validation(t_controller signals)
{
	char		*data;
	size_t		ants;

	ants = 0;
	data = NULL;
	while (controller(signals))
	{
		data = read_data_from_input(data);
		if (valid_of_data(controller, data) == -1)
		{
			usage(controller);
			break ;
		}
	}
}

int			main(void)
{
	t_controller	signals;
	t_room			*room;

	init_controller(&signals);
	init_room(&room);
	if (data_is_valid(signals))
		use_algorithm(room);
	free_room(room);
	return (0);
}