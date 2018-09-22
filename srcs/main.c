/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:58:42 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/29 12:39:34 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		print_data(const char *data)
{
	if (data)
		ft_printf("\x1b[36mINFO:\x1b[0m\n%s\n", data);
}

int			main(int argc, char **argv)
{
	t_storage		s;
	t_htab			ht;
	t_atab			at;
	t_lp			lp;
	t_args			a;

	storage_init(&s);
	valid_data(&s);
	htab_init(&ht, &s);
	htab_create(&ht, s.buff, s.info);
	atab_init(&at, ht.size);
	atab_crte(&at, &ht, s.buff, s.info);
	lstpaths_init(&lp);
	lstpaths_create(&lp, &at, &ht);
	// print_data(s.buff->data);
	args_init(&a);
	if (argc > 1 && args_analyze(&a, argc, argv))
		args_print(&a, &lp, &at, &ht);
	else
		usage_print();
	// send_ants(&lp, s.info->ants, ht.end);
	// system("leaks lem-in");
	return (0);
}
