/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:17:04 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/12 21:10:24 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	ft_strlen_null(char *str)
{
	int		len;

	if (!*str)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strnstr(const char *bg, const char *lt, size_t len)
{
	size_t	i;
	size_t	j;

	if (lt == NULL || *lt == '\0')
		return ((char *)bg);
	i = 0;
	while (bg[i] != '\0' && i < len)
	{
		j = 0;
		while (bg[i + j] == lt[j] && (i + j) < len)
			j++;
		if (lt[j] == '\0')
			return ((char *)&bg[i]);
		i++;
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	is_builtin(char *cmd)
{
	int			i;
	int			cmd_len;
	const char	*builtin_str[7] = {
		"echo",
		"cd",
		"pwd",
		"export",
		"unset",
		"env",
		"exit"
	};

	if (cmd && *cmd)
	{
		i = 0;
		cmd_len = ft_strlen_null(cmd);
		while (i < 7)
		{
			if (ft_strlen_null((char *)builtin_str[i]) == cmd_len \
				&& ft_strncmp(builtin_str[i], cmd, cmd_len) == 0)
				return (1);
			i++;
		}
	}
	return (0);
}

int	is_builtin2(char *cmd)
{
	if (!cmd)
		return (0);
	if (str_equal(cmd, "echo"))
		return (1);
	if (str_equal(cmd, "cd"))
		return (1);
	if (str_equal(cmd, "pwd"))
		return (1);
	if (str_equal(cmd, "export"))
		return (1);
	if (str_equal(cmd, "unset"))
		return (1);
	if (str_equal(cmd, "env"))
		return (1);
	if (str_equal(cmd, "exit"))
		return (1);
	return (0);
}
