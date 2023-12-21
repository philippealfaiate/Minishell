/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:22:14 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/14 15:57:27 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	execute_forked_builtin(char **args, t_env **s_msenv)
{
	int	exit_status;

	exit_status = execute_builtin(args, s_msenv);
	if (args)
		ft_freearray(args);
	if (s_msenv)
		msenv_cleanup(s_msenv);
	rl_clear_history();
	exit(exit_status);
}

int	execute_nbuiltin(char *cmd, char **args, t_env **s_msenv)
{
	char	**new_args;

	new_args = args;
	if (str_equal(cmd, "echo"))
		return (ft_echo(cmd, new_args, s_msenv));
	if (str_equal(cmd, "pwd"))
		return (ft_pwd(cmd, new_args, s_msenv));
	if (str_equal(cmd, "env"))
		return (ft_env(cmd, new_args, s_msenv));
	if (str_equal(cmd, "export"))
		return (ft_export(cmd, new_args, s_msenv));
	if (str_equal(cmd, "unset"))
		return (ft_unset(cmd, new_args, s_msenv));
	if (str_equal(cmd, "cd"))
		return (ft_cd(cmd, new_args, s_msenv));
	if (str_equal(cmd, "exit"))
		return (ft_exit(cmd, new_args, s_msenv));
	else
		return (EXIT_FAILURE);
	return (EXIT_FAILURE);
}

int	execute_builtin(char **args, t_env **s_msenv)
{
	return (execute_nbuiltin(args[0], args, s_msenv));
}
