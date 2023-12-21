/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:50:01 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/11 19:09:08 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	str_equal(const char *s1, const char *s2)
{
	size_t	size;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen((char *)s1);
	if (size != (size_t)ft_strlen((char *)s2))
		return (0);
	return (ft_strncmp(s1, s2, size) == 0);
}

void	ft_memfw(char *str)
{
	ft_memmove(str, str + 1, ft_strlen(str + 1) + 1);
}
