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

void		args_init(t_args *a)
{
	ft_memset(a, 0, sizeof(t_args));
}

bool		args_analyze(t_args *a, int argc, char **argv)
{
	int		arg;
	bool	exist;

	if (!argv)
		return (FALSE);
	arg = 0;
	exist = FALSE;
	while (++arg < argc)
	{
		if (is_a(argv[arg]))
		{
			a->a = TRUE;
			return (TRUE);
		}
		else if (!a->ht && is_ht(argv[arg]))
			a->ht = TRUE;
		else if (!a->at && is_at(argv[arg]))
			a->at = TRUE;
		else if (!a->p && is_p(argv[arg]))
			a->p = TRUE;
		if (a->ht || a->at || a->p)
			exist = TRUE;
	}
	return (exist ? TRUE : FALSE);
}

void		print_all(t_lp *lp, t_atab *at, t_htab *ht)
{
	htab_print_room(ht);
	htab_print_coord(ht);
	atab_print(at);
	lstpaths_print(lp);
}

void		args_print(t_args *a, t_lp *lp, t_atab *at, t_htab *ht)
{
	ft_printf("\x1b[32mSTART:\x1b[0m [%s]\n", ht->start);
	ft_printf("\x1b[34mFINISH:\x1b[0m [%s]\n", ht->end);
	if (!a->a)
	{
		if (a->ht)
		{
			htab_print_room(ht);
			htab_print_coord(ht);
		}
		if (a->at)
			atab_print(at);
		if (a->p)
			lstpaths_print(lp);
	}
	else
		print_all(lp, at, ht);
}
