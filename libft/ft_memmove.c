/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:15:53 by phialfai          #+#    #+#             */
/*   Updated: 2022/11/25 15:43:23 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	long long int	i;
	char			*cdst;
	char			*csrc;

	i = (long long int) n;
	cdst = (char *) dest;
	csrc = (char *) src;
	if (csrc > cdst)
		ft_memcpy(dest, src, n);
	if (cdst > csrc)
	{
		i--;
		while (i >= 0)
		{
			cdst[i] = csrc[i];
			i--;
		}
	}
	return (dest);
}
