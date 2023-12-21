/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:25:02 by phialfai          #+#    #+#             */
/*   Updated: 2023/10/18 12:51:40 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The strstr() function locates the first occurrence of the null-terminated
 * string little in the null-terminated string big.
 * The strnstr() function locates the	first occurrence of the	null-terminated
 * string little in the	string big, where not more than	len characters
 * are searched.  Characters that appear after a `\0' character are not searched.
 * Since the strnstr() function is	a FreeBSD specific API,	it should only
 * be used when portability is not a concern.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little == NULL || *little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
