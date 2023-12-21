/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msenv_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:38:08 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/10 14:46:17 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	ft_strlen_jm(char *s)
{
	int	i;

	i = 0;
	if (s && *s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

char	*ft_strdup_jm(const char *s)
{
	char	*ptr;
	int		i;
	size_t	s_len;

	s_len = ft_strlen_jm((char *) s);
	ptr = malloc(sizeof(char) * (s_len + 1));
	if (ptr == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin_jm(char *s1, char *s2)
{
	char	*str;
	int		str_size;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str_size = ft_strlen_jm(s1) + ft_strlen_jm(s2) + 1;
	str = malloc(sizeof(char) * str_size);
	if (!str)
		return (NULL);
	while (*s1)
	{
		str[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
