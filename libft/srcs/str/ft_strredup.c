/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strredup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:05:18 by vsokolog          #+#    #+#             */
/*   Updated: 2018/05/15 16:05:19 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_strredup(char *del, char *src)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(src);
	if (!(dst = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strdel(&del);
	dst = ft_strcpy(dst, src);
	return (dst);
}
