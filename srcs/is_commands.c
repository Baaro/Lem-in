#include "lem_in.h"

bool	is_start_command(const char *data)
{
	if (ft_strcmp(data, "##start") == 0)
		return (TRUE);
	return (FALSE);
}

bool	is_end_command(const char *data)
{
	if (ft_strcmp(data, "##end") == 0)
		return (TRUE);
	return (FALSE);
}

bool		is_commands(const char *line)
{
	if (is_start_command(line) || is_end_command(line))
		return (TRUE);
	return (FALSE);
}