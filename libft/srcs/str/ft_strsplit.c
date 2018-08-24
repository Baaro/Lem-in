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

static	size_t	count_words(const char *str, char delim)
{
	char	*tmp;
	size_t	count;

	tmp = str;
	count = 0;
	while (*tmp)
	{
		if (*tmp == delim && (*(tmp + 1) != delim && *(tmp + 1) != '\0'))
			word++;
		tmp++;
	}
	while ()
	// while (s[i])
	// {
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			word++;
		i++;
	// }
	// if (s[0] != c)
		// word++;
	return (word);
}

static	char	*ft_put_word(char const *s, char c, int *i)
{
	char	*word;
	int		d;

	d = 0;
	while (s[*i] == c)
		(*i)++;
	if (!(word = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[*i] && s[*i] != c)
		word[d++] = s[(*i)++];
	word[d] = '\0';
	return (word);
}

// char			**ft_strsplit(char const *s, char c)
// {
// 	int		count;
// 	char	**arr;
// 	int		i;
// 	int		last_pos;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	count = ft_count(s, c);
// 	if (!(arr = (char **)malloc(sizeof(char *) * count + 1)))
// 		return (NULL);
// 	if (*s == '\0')
// 	{
// 		arr[0] = NULL;
// 		return (arr);
// 	}
// 	last_pos = 0;
// 	while (i < count)
// 	{
// 		arr[i] = ft_put_word(s, c, &last_pos);
// 		i++;
// 	}
// 	arr[i] = NULL;
// 	return (arr);
// }

char		ft_strsplit(const char *str, char delim)
{
	char	**array;
	size_t	amount_words;
	size_t	i;

	if (!s)
		return (NULL);
	i = -1;
	amount_of_words = count_words(str, delim);
	array = (char **)malloc(sizeof(char *) * ft_strlen(amount_of_words) + 1);
	while (++i < amount_of_words)
		array[i] = put_word(str, delim);
	array[i] = NULL;
	return (array);
}
