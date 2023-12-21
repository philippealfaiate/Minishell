/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:04:47 by phialfai          #+#    #+#             */
/*   Updated: 2022/11/22 15:08:30 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Écrit la chaîne de caractères ’s’ sur le descripteur de fichier donné.
 * 
 * @param char *s: La chaîne de caractères à écrire.
 * @param int fd: Le descripteur de fichier sur lequel écrire.
 * 
 * @return void
*/
void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
