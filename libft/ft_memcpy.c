/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:07:30 by phialfai          #+#    #+#             */
/*   Updated: 2022/11/24 16:19:24 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;
	size_t	i;

	cdest = (char *) dest;
	csrc = (char *) src;
	i = 0;
	while (i < n)
	{
		*(cdest + i) = *(csrc + i);
		i++;
	}
	return (dest);
}
