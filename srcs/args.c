/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_printer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:16:24 by vsokolog          #+#    #+#             */
/*   Updated: 2018/09/22 12:16:26 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		args_init(t_args *args)
{
	ft_memset(args, 0, sizeof(t_args));
}

bool		args_analyze(t_args *args, int argc, char **argv)
{
	size_t	arg;
	bool	exist;

	if (!argv)
		return (FALSE);
	arg = 0;
	exist = FALSE;
	while (++arg < argc)
	{
		if (is_a(argv[arg]))
		{
			args->a = TRUE;
			return (TRUE);
		}
		else if (!args->ht && is_ht(argv[arg]))
			args->ht = TRUE;
		else if (!args->at && is_at(argv[arg]))
			args->at = TRUE;
		else if (!args->p && is_p(argv[arg]))
			args->p = TRUE;
		if (args->ht || args->at || args->p)
			exist = TRUE;
	}
	return (exist ? TRUE : FALSE);
}

void		print_all(t_lstpaths *lp, t_adjtab *at, t_htab *ht)
{
	hashtable_print_room(ht);
	hashtable_print_coord(ht);
	adjtab_print(at);
	lstpaths_print(lp);
}

void		args_print(t_args *args, t_lstpaths *lp, t_adjtab *at, t_htab *ht)
{
	ft_printf("\x1b[32mSTART:\x1b[0m [%s]\n", ht->start);
	ft_printf("\x1b[34mFINISH:\x1b[0m [%s]\n", ht->end);
	if (!args->a)
	{
		if (args->ht)
		{
			hashtable_print_room(ht);
			hashtable_print_coord(ht);
		}
		if (args->at)
			adjtab_print(at);
		if (args->p)
			lstpaths_print(lp);
	}
	else
		print_all(lp, at, ht);
}
