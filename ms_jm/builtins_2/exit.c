/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:26:36 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/11 18:47:17 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	test_all(char *str)
{
	long long	out;
	int			c;

	if (ft_strlen(str) > 20)
		return (0);
	if (ft_strncmp(str, "-9223372036854775808", 21) == 0)
		return (1);
	out = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		c = *str - '0';
		if (out > (LLONG_MAX - c) / 10)
			return (0);
		out = out * 10 + c;
		str++;
	}
	return (1);
}

static void	check_args_error(char **args)
{
	char	*exit_status;

	if (!args || !args[1])
	{
		if (args)
			ft_freearray(args);
		close_all_fds();
		exit(EXIT_SUCCESS);
	}
	exit_status = args[1];
	if (!test_all(exit_status))
	{
		ft_freearray(args);
		exit_with_error("exit", "numeric argument required", BUILTIN_MISUSE);
	}
	if (args[2] != NULL)
	{
		ft_freearray(args);
		exit_with_error("exit", "too many arguments", EXIT_FAILURE);
	}
}

int	ft_exit(char *cmd, char **args, t_env **s_msenv)
{
	int	exit_status;

	(void)cmd;
	rl_clear_history();
	if (s_msenv)
		msenv_cleanup(s_msenv);
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	check_args_error(args);
	close_all_fds();
	exit_status = ft_atoll(args[1]);
	ft_freearray(args--);
	exit(exit_status);
}
