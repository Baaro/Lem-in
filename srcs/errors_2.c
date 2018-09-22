/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 16:13:05 by vsokolog          #+#    #+#             */
/*   Updated: 2018/09/22 16:13:08 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		errors_commands(const t_errors e)
{
	ft_printf("\x1b[31mERROR:\x1b[0m ");
	if (e == NO_START_COMMAND)
		ft_printf("There is no [##start] command!\n");
	else if (e == NO_END_COMMAND)
		ft_printf("There is no [##end] command!\n");
	else if (e == TWO_START_COMMANDS)
		ft_printf("There are two [##start] commands!\n");
	else if (e == TWO_END_COMMANDS)
		ft_printf("There are two [##end] commands!\n");
	exit(EXIT_FAILURE);
}

void		errors_input(const t_errors e)
{
	ft_printf("\x1b[31mERROR:\x1b[0m ");
	if (e == WRONG_INPUT)
		ft_printf("There is an invalid file on input!\n");
	exit(EXIT_FAILURE);
}

void		errors_memory(const t_errors e, const char *error_func)
{
	ft_printf("\x1b[31mERROR:\x1b[0m ");
	if (e == CANT_ALLOCATE_MEM)
		ft_printf("Cannot allocate memory! Func: [%s]!\n", error_func);
	else if (e == CANT_SETZERO)
		ft_printf("Cannot use memset! Func: [%s]!\n", error_func);
	exit(EXIT_FAILURE);
}

void		errors_algorithm(const t_errors e)
{
	ft_printf("\x1b[31mERROR:\x1b[0m ");
	if (e == THERE_ARE_NO_POSSIBLE_WAYS)
		ft_printf("There are no possible ways!\n");
	exit(EXIT_FAILURE);
}
