/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_one_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:49:48 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/13 11:25:04 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static int	handle_redirects(char *command, int original_fds[2])
{
	char	redirect;

	original_fds[IN] = NO_REDIRECT;
	original_fds[OUT] = NO_REDIRECT;
	redirect = get_next_redirect(command);
	while (redirect)
	{
		if (redirect == '<')
		{
			if (!handle_input_redirect(command, original_fds))
				return (FAILED);
		}
		if (redirect == '>')
		{
			if (!handle_output_redirect(command, original_fds))
				return (FAILED);
		}
		if (redirect < 0)
		{
			save_original_fd_in(original_fds);
			redirect_heredoc(command, redirect);
		}
		redirect = get_next_redirect(command);
	}
	return (SUCCESS);
}

static void	restore_original_fds(int original_fds[2])
{
	if (original_fds[IN] != NO_REDIRECT)
		redirect_fd(original_fds[IN], STDIN_FILENO);
	if (original_fds[OUT] != NO_REDIRECT)
		redirect_fd(original_fds[OUT], STDOUT_FILENO);
}

int	execute_forked_external(char **args, t_env *s_msenv)
{
	int		child_pid;
	char	*command;

	command = args[0];
	child_pid = fork();
	define_execute_signals(child_pid);
	if (child_pid == -1)
		print_perror_msg("fork", command);
	else if (child_pid == 0)
		execute_external(args, s_msenv);
	else
		return (wait_for_child(child_pid, TRUE));
	exit(EXIT_FAILURE);
}

int	execute_one_command(char *command, t_env **s_msenv)
{
	char	**args;
	int		exit_status;
	int		original_fds[2];

	if (!handle_redirects(command, &original_fds[0]))
	{
		restore_original_fds(original_fds);
		free(command);
		return (EXIT_FAILURE);
	}
	args = split_args(command);
	free(command);
	if (is_builtin(args[0]))
		exit_status = execute_builtin(args, s_msenv);
	else
		exit_status = execute_forked_external(args, *s_msenv);
	ft_freearray(args);
	restore_original_fds(original_fds);
	return (exit_status);
}
