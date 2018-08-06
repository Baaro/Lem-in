#include "lem_in.h"

static intmax_t count_ants(const char *data)
{
	intmax_t	ants;

	ants = 0;
	if (*data == '-')
		errors_ants(ANTS_IS_NEG);
	else if (*data == 0)
		errors_ants(ANTS_IS_ZERO);
	while (*data && ants < MAX_ANTS)
	{
		if (ft_isdigit(*data))
			ants = (ants * 10) + (*data) - '0';
		else
			errors_ants(WRONG_VALUE_OF_ANTS);
		data++;
	}
	if (ants > MAX_ANTS)
		errors_ants(TOO_FEW_ANTS);
	else if (ants == 0)
		errors_ants(ANTS_IS_ZERO);
	return (ants);
}

bool		valid_ants(t_checks *checks, const char *data, intmax_t *ants)
{
	if (checks->ants_check == UNCHECKED)
	{
		*ants = count_ants(data);
		checks->ants_check = CHECKED;
		return (TRUE);
	}
	return (FALSE);
}