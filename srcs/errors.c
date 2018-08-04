/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:59:15 by vsokolog          #+#    #+#             */
/*   Updated: 2018/07/23 16:59:16 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		errors_ants(const t_errors error)
{
	if (error == too_few_ants)
		ft_printf("\x1b[31mERROR:\x1b[0m Value of ants is bigger than 100 000!\n");
	else if (error == wrong_value_ants)
		ft_printf("\x1b[31mERROR:\x1b[0m Value of ants is not a number!\n");
	else if (error == ants_is_neg)
		ft_printf("\x1b[31mERROR:\x1b[0m Value of ants is negative!\n");
	else if (error == ants_is_zero)
		ft_printf("\x1b[31mERROR:\x1b[0m Value of ants is zero!\n");
	exit(1);
}

void		errors_rooms(const t_errors error)
{
	if (error == wrong_name_of_rooms)
		ft_printf("\x1b[31mERROR:\x1b[0m Wrong name of rooms\n");
	exit(1);
}

void		errors_coordinates(const t_errors error)
{
	if (error == wrong_coordinates_x)
		ft_printf("\x1b[31mERROR:\x1b[0m Wrong X coordinates\n");
	else if (error == wrong_coordinates_y)
		ft_printf("\x1b[31mERROR:\x1b[0m Wrong Y coordinates\n");
	exit(1);
}

void		errors_commands(const t_errors error)
{
	if (error == no_start_command)
		ft_printf("\x1b[31mERROR:\x1b[0m No ##start command\n");
	else if (error == no_end_command)
		ft_printf("\x1b[31mERROR:\x1b[0m No ##end command\n");
	else if (error == unknown_command)
		ft_printf("\x1b[31mERROR:\x1b[0m The data has unknown command\n");
	exit(1);
}