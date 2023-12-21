/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:48:45 by phialfai          #+#    #+#             */
/*   Updated: 2022/11/25 14:14:46 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Écrire des octets de valeur zéro dans un bloc d'octets
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset((char *)s, 0, n);
}
