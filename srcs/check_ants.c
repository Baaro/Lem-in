#include "lem_in.h"

static intmax_t count_ants(const char *data)
{
	intmax_t	ants;

	ants = 0;
	if (*data == '-')
		errors_ants(ants_is_neg);
	else if (*data == 0)
		errors_ants(ants_is_zero);
	while (*data && ants < MAX_ANTS)
	{
		if (ft_isdigit(*data))
			ants = (ants * 10) + (*data) - '0';
		else
			errors_ants(wrong_value_ants);
		data++;
	}
	if (ants > MAX_ANTS)
		errors_ants(too_few_ants);
	else if (ants == 0)
		errors_ants(ants_is_zero);
	return (ants);
}

bool		check_ants(t_checks *checks, const char *data, intmax_t *ants)
{
	if (checks->ants_check == UNCHECKED)
	{
		*ants = count_ants(data);
		checks->ants_check = CHECKED;
		return (TRUE);
	}
	return (FALSE);
}