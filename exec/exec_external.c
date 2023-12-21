/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:46:16 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/14 12:57:08 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static int	is_folder(char *command)
{
	struct stat	statbuf;

	if (stat(command, &statbuf) != 0)
		return (0);
	if (S_ISDIR(statbuf.st_mode))
	{
		if (*command == '.')
			command++;
		if (*command == '.')
			command++;
		if (*command == '/')
			return (TRUE);
	}
	return (FALSE);
}

static void	handle_execve_errors(char **args, char *path, char **envp)
{
	int	error;

	error = EXIT_FAILURE;
	print_perror_msg("execve", args[0]);
	if (access(path, F_OK) != 0)
		error = CMD_NOT_FOUND;
	else if (access(path, X_OK) != 0)
		error = NOT_EXECUTABLE;
	ft_freearray(args);
	ft_freearray(envp);
	free(path);
	exit(error);
}

void	external_exit(char **args, t_env *s_msenv, int exit_status)
{
	if (exit_status == NOT_EXECUTABLE)
		print_error_msg(args[0], NOT_EXECUTABLE_MSG);
	if (exit_status == CMD_NOT_FOUND)
	{
		if (str_equal(args[0], "!") || str_equal(args[0], ":"))
			ft_putstr_fd("\n", STDOUT_FILENO);
		else
			print_error_msg(args[0], CMD_NOT_FOUND_MSG);
	}
	rl_clear_history();
	msenv_cleanup(&s_msenv);
	ft_freearray(args);
	close_all_fds();
	exit(exit_status);
}

static int	msenv_has_path(t_env *s_msenv)
{
	return (msenv_getvalue("PATH", &s_msenv) != NULL);
}

int	execute_external(char **args, t_env *s_msenv)
{
	char	*path;
	char	*command;
	char	**envp;

	command = args[0];
	if (ft_isempty(command))
		external_exit(args, s_msenv, EXIT_SUCCESS);
	if (is_folder(command))
		external_exit(args, s_msenv, NOT_EXECUTABLE);
	path = get_path(command, s_msenv);
	if (path == NULL && msenv_has_path(s_msenv))
		external_exit(args, s_msenv, CMD_NOT_FOUND);
	else if (path == NULL)
		path = ft_strdup_jm(command);
	rl_clear_history();
	close_extra_fds();
	envp = msenv_to_envp(s_msenv);
	msenv_cleanup(&s_msenv);
	if (execve(path, args, envp) == -1)
		handle_execve_errors(args, path, envp);
	exit(EXIT_SUCCESS);
}
