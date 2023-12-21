/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:16:09 by phialfai          #+#    #+#             */
/*   Updated: 2022/11/25 16:16:59 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*cs;
	int		i;
	int		slen;

	cs = (char *) s;
	slen = ft_strlen(cs);
	if (c > 256)
		return (cs);
	if (c == 0)
		return (cs + slen);
	i = 0;
	while (cs[i] != '\0')
	{
		if (cs[i] == c)
			return (&cs[i]);
		i++;
	}
	return (NULL);
}
