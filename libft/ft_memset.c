/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:07:49 by phialfai          #+#    #+#             */
/*   Updated: 2022/11/25 14:13:11 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	char	*dest;
	size_t	i;

	dest = (char *) pointer;
	i = 0;
	while (i < count)
	{
		*(dest + i) = value;
		i++;
	}
	return (pointer);
}
