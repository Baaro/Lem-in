/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjtab_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:14:30 by vsokolog          #+#    #+#             */
/*   Updated: 2018/09/22 12:14:31 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	adjtab_init(t_adjtab *adjtab, size_t size)
{
	adjtab->size = size;
	if (!(adjtab->lsts = (t_adjlst **)malloc(sizeof(t_adjlst *)
				* adjtab->size + 1)))
		errors_memory(CANT_ALLOCATE_MEM, "adjtab_init");
	adjlst_init(adjtab->lsts, adjtab->size + 1);
}
