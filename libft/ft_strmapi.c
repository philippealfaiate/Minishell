/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:24:53 by phialfai          #+#    #+#             */
/*   Updated: 2022/11/25 19:17:14 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				i;
	char			*cpy_s;
	char			*dest;
	unsigned int	len;

	cpy_s = (char *) s;
	len = ft_strlen(cpy_s);
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (cpy_s[i] != '\0')
	{
		dest[i] = (*f)(i, cpy_s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
