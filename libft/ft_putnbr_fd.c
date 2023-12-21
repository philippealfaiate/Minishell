/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:40:54 by phialfai          #+#    #+#             */
/*   Updated: 2022/11/29 11:47:58 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fb)
{
	long int	ln;

	ln = n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fb);
		ln = -ln;
	}
	if (ln > 9)
	{
		ft_putnbr_fd(ln / 10, fb);
		ft_putnbr_fd(ln % 10, fb);
	}
	else
		ft_putchar_fd((char)(ln + '0'), fb);
}
