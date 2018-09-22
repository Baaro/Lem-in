/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjtab_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 16:12:01 by vsokolog          #+#    #+#             */
/*   Updated: 2018/09/22 16:12:04 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	atab_init(t_atab *at, ssize_t size)
{
	at->size = size;
	if (!(at->lsts = (t_alst **)malloc(sizeof(t_alst *) * at->size + 1)))
		errors_memory(CANT_ALLOCATE_MEM, "at_init");
	alst_init(at->lsts, at->size + 1);
}
