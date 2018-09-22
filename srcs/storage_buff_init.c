/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:59:09 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/29 17:59:10 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	buff_init(t_buff **buff)
{
	if (!(*buff = (t_buff *)malloc(sizeof(t_buff))))
		errors_memory(CANT_ALLOCATE_MEM, "buff_init");
	(*buff)->line = NULL;
	(*buff)->data = ft_strnew(0);
}

void	storage_init(t_storage *strg)
{
	ft_memset(strg, 0, sizeof(t_storage));
	buff_init(&strg->buff);
	info_init(&strg->info);
}
