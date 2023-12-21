/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_equal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:22:55 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/09 20:02:59 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	ft_str_equal(const char *s1, const char *s2)
{
	size_t	size;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen((char *)s1);
	if (size != (size_t)ft_strlen((char *)s2))
		return (0);
	return (ft_strncmp(s1, s2, size) == 0);
}
