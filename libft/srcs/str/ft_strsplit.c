/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:22:09 by vsokolog          #+#    #+#             */
/*   Updated: 2017/12/04 13:43:46 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	**ft_strsplit(const char *s, char c)
// {
// 	char	**ret;
// 	size_t	i;
// 	size_t	j;
// 	size_t	len;

// 	if (!s || !c)
// 		return (0);
// 	ret = ft_memalloc(ft_strlen(s) + 1);
// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == c)
// 			i++;
// 		else
// 		{
// 			len = 0;
// 			while (s[i + len] && (s[i + len] != c))
// 				len++;
// 			ret[j++] = ft_strsub(s, i, len);
// 			i = i + len;
// 		}
// 	}
// 	ret[j] = 0;
// 	return (ret);
// }

static	int		cntwords(char const *s, char c)
{
	int word;
	int i;

	word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			word++;
		i++;
	}
	if (s[0] != c)
		word++;
	return (word);
}

static	char	*putword(char const *s, char c, int *last_pos)
{
	char	*word;
	int		d;
	int		i;


	d = 0;
	i = *last_pos;
	while (s[i] == c)
		i++;
	if (!(word = (char *)malloc(sizeof(char) * ft_strlen(s))))
		return (NULL);
	while (s[i] && s[i] != c)
	{
		word[d] = s[i];
		d++;
		i++;
	}
	word[d] = '\0';
	*last_pos = i;
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		last_pos;
	int		count;
	int		i;


	if (!s || !c)
		return (NULL);
	count = cntwords(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * count + 1)))
		return (NULL);
	i = 0;
	last_pos = 0;
	while (i < count)
	{
		arr[i] = putword(s, c, &last_pos);
		++i;
	}
	arr[i] = NULL;
	return (arr);
}
