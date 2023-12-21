/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:20:02 by phialfai          #+#    #+#             */
/*   Updated: 2022/11/22 15:08:42 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Écrit le caractère ’c’ sur le descripteur de fichier donné.
 * 
 * @param char c
 * @param int fd
 * 
 * @return void
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
