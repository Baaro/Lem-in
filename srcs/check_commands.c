
#include "lem_in.h"

void       check_start_command(const char *data, t_checks *checks)
{
	if (checks->comm_check[START] == UNCHECKED)
	{
		if (is_start_command(data))
			checks->comm_check[START] = CHECKED;
	}
}

void		check_end_command(const char *data, t_checks *checks)
{
	if (checks->comm_check[END] == UNCHECKED)
	{
		if (checks->comm_check[START] == CHECKED)
		{
			if (is_end_command(data))
				checks->comm_check[END] = CHECKED;
		}
		else
			errors_commands(no_start_command);
	}
}