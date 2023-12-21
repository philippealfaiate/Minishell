/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:26:20 by phialfai          #+#    #+#             */
/*   Updated: 2022/12/20 17:01:17 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*dest;

	i = 0;
	slen = ft_strlen((char *) s);
	dest = NULL;
	if (!s)
		return (NULL);
	if ((slen - start) < len)
		len = slen - start;
	else if (start > slen)
		len = 0;
	dest = malloc(sizeof(char) * (len + 1));
	if (dest != NULL)
	{
		while (s[i] != '\0' && i < len)
		{
			dest[i] = (char) s[i + start];
			i++;
		}
		dest[len] = '\0';
	}
	return (dest);
}
