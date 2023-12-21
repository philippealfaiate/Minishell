/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:57:47 by phialfai          #+#    #+#             */
/*   Updated: 2022/11/24 15:53:21 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	lendst;
	unsigned int	lensrc;
	int				len;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen((char *)src);
	len = size - 1 - lendst;
	if (size <= lendst)
		return (size + lensrc);
	while (*dst != '\0')
		dst++;
	while (*src && len)
	{
		*dst++ = *src++;
		len--;
	}
	*dst = '\0';
	return (lendst + lensrc);
}
