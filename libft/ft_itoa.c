/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:39:35 by phialfai          #+#    #+#             */
/*   Updated: 2022/12/19 10:50:39 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intsize(int i)
{
	int	size;

	size = 0;
	if (i == 0)
		size++;
	if (i < 0)
		size = -size + 1;
	while (i)
	{
		size++;
		i /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char			*dest;
	size_t			dest_len;
	long int		ln;

	ln = n;
	dest_len = ft_intsize(n);
	dest = malloc(sizeof(char) * (dest_len + 1));
	if (dest == NULL)
		return (NULL);
	dest[dest_len] = '\0';
	if (ln == 0)
		dest[0] = '0';
	if (ln < 0)
	{
		dest[0] = '-';
		ln *= -1;
	}
	while (ln)
	{
		dest[--dest_len] = ln % 10 + 48;
		ln /= 10;
	}
	return (dest);
}
