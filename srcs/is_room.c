#include "lem_in.h"

bool		is_room(const char *line)
{
	if (!is_comment(line) && !is_commands(line))
	 	return (TRUE);
	return (FALSE);
}