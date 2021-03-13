/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:14:46 by vsokolog          #+#    #+#             */
/*   Updated: 2018/09/22 12:14:47 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
