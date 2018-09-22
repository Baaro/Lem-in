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

void		print_data(const char *data)
{
	if (data)
		ft_printf("\x1b[36mINFO:\x1b[0m\n%s\n", data);
}

int			main(int argc, char **argv)
{
	t_storage		strg;
	t_htab			ht;
	t_adjtab		at;
	t_lstpaths		lp;
	t_args			args;

	storage_init(&strg);
	valid_data(&strg);
	hashtab_init(&ht, &strg);
	hashtab_create(&ht, strg.buff, strg.info);
	adjtab_init(&at, ht.size);
	adjtab_create(&at, &ht, strg.buff, strg.info);
	lstpaths_init(&lp);
	lstpaths_create(&lp, &at, &ht);
	print_data(strg.buff->data);
	args_init(&args);
	if (argc > 1 && args_analyze(&args, argc, argv))
		args_print(&args, &lp, &at, &ht);
	else
		usage_print();
	send_ants(&lp, strg.info->ants, ht.end);
	return (0);
}
