/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:34:54 by phialfai          #+#    #+#             */
/*   Updated: 2022/12/20 17:03:01 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;

	len = ft_strlen((char *)s1) - 1;
	start = 0;
	while (s1[start] != '\0'
		&& ft_memchr(set, s1[start], ft_strlen((char *)set)) != NULL)
		start++;
	while (len > start
		&& ft_memchr(set, s1[len], ft_strlen((char *)set)) != NULL)
		len--;
	len = len - start + 1;
	return (ft_substr(s1, start, len));
}
