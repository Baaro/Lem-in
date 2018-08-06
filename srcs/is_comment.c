#include "lem_in.h"

bool				is_comment(const char *data)
{
	if (*data == '#' && !is_start_command(data) && !is_end_command(data))
		return (TRUE);
	return (FALSE);
}