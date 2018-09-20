#include "lem_in.h"

bool		is_a(char *argv)
{
	if (ft_strcmp(argv, "-a") == 0)
		return (TRUE);
	return (FALSE);
}

bool		is_ht(char *argv)
{
	if (ft_strcmp(argv, "-ht") == 0)
		return (TRUE);
	return (FALSE);
}

bool		is_at(char *argv)
{
	if (ft_strcmp(argv, "-at") == 0)
		return (TRUE);
	return (FALSE);
}

bool		is_p(char *argv)
{
	if (ft_strcmp(argv, "-p") == 0)
		return (TRUE);
	return (FALSE);
}

bool		is_u(char *argv)
{
	if (ft_strcmp(argv, "-u") == 0)
		return (TRUE);
	return (FALSE);
}
