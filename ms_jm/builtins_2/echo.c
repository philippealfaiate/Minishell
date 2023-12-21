/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:08:15 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/14 11:28:43 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static int	ft_checkoption(char *str)
{
	int	quote;

	quote = 0;
	if (*str == '"')
	{
		quote = !quote;
		str++;
	}
	if (*str != '-')
		return (0);
	str++;
	if (*str == 'n')
	{
		while (*str == 'n')
			str++;
		if (*str == '"' || *str == '\0')
			return (1);
	}
	return (0);
}

int	ft_echo(char *cmd, char **args, t_env **s_msenv)
{
	int	i;
	int	n;

	(void)cmd;
	(void)s_msenv;
	i = 0;
	n = 0;
	if (str_equal(args[i], "echo"))
		i++;
	while (args[i] && ft_checkoption(args[i]))
	{
		n = 1;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (!n)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
