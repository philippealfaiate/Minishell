/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_multi_cmds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:31:37 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/07 12:50:18 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static void	save_original_fds(int original_fds[2])
{
	original_fds[0] = dup(STDIN_FILENO);
	original_fds[1] = dup(STDOUT_FILENO);
}

static void	handle_redirects(char *command, char **commands, t_env **s_msenv)
{
	char	redirect;

	redirect = get_next_redirect(command);
	while (redirect)
	{
		if (redirect == '<')
		{
			if (redirect_input(command) == FAILED)
				quit_child(commands, s_msenv);
		}
		if (redirect == '>')
		{
			if (redirect_output(command) == FAILED)
				quit_child(commands, s_msenv);
		}
		if (redirect < 0)
			redirect_heredoc(command, redirect);
		redirect = get_next_redirect(command);
	}
}

static void	execute_forked_command(char *command, char **commands,
		t_env **s_msenv)
{
	char	**args;

	close_extra_fds();
	args = split_args(command);
	ft_freearray(commands);
	if (is_builtin(args[0]))
		execute_forked_builtin(args, s_msenv);
	else
		execute_external(args, *s_msenv);
}

static void	restore_original_fds(int original_fds[2])
{
	redirect_fd(original_fds[IN], STDIN_FILENO);
	redirect_fd(original_fds[OUT], STDOUT_FILENO);
}

int	execute_multiple_commands(char **commands, t_env **s_msenv)
{
	int	original_fds[2];
	int	*children_pid;
	int	i;

	save_original_fds(original_fds);
	children_pid = init_children_pid(commands);
	i = 0;
	while (commands[i])
	{
		handle_pipe(original_fds[OUT], commands[i], commands);
		children_pid[i] = fork();
		define_execute_signals(children_pid[i]);
		if (children_pid[i] == -1)
			print_perror_msg("fork", commands[i]);
		else if (children_pid[i] == 0)
		{
			free(children_pid);
			handle_redirects(commands[i], commands, s_msenv);
			execute_forked_command(commands[i], commands, s_msenv);
		}
		i++;
	}
	restore_original_fds(original_fds);
	return (wait_for_children(children_pid));
}
