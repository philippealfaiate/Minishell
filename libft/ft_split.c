/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:50:06 by phialfai          #+#    #+#             */
/*   Updated: 2022/12/19 10:50:04 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nb_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*(s) != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*(s + count) != c && *(s + count) != '\0')
		count++;
	return (count);
}

static char	**ft_strings_alloc(size_t size)
{
	char	**dst;

	dst = malloc(sizeof(char *) * (size + 1));
	if (dst == NULL)
		return (NULL);
	return (dst);
}

static void	ft_free_split(char **split)
{
	free(split);
	split = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	nb_words;
	size_t	word_len;

	nb_words = ft_nb_words(s, c);
	split = ft_strings_alloc(nb_words);
	split[nb_words] = 0;
	if (split == NULL)
		ft_free_split(split);
	i = 0;
	while (*s)
	{
		if (*(s) != c)
		{
			word_len = ft_word_len((s), c);
			split[i] = ft_substr(s, 0, word_len);
			if (split[i++] == NULL)
				ft_free_split(split);
			s += word_len - 1;
		}
		s++;
	}
	return (split);
}
