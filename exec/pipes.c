/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:33:09 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/11/22 13:33:12 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	handle_pipe(int original_fd_out, char *current_command, char **commands)
{
	int			is_first_command;
	int			has_next_command;
	char		*last_command;
	static int	pipe_fds[2];

	last_command = commands[ft_arraylen(commands) - 1];
	is_first_command = (current_command == commands[0]);
	has_next_command = (current_command != last_command);
	if (!is_first_command)
		redirect_fd(pipe_fds[IN], STDIN_FILENO);
	if (has_next_command)
	{
		if (pipe(pipe_fds) == -1)
			print_perror_msg("pipe", current_command);
		redirect_fd(pipe_fds[OUT], STDOUT_FILENO);
	}
	else
		redirect_fd(original_fd_out, STDOUT_FILENO);
}
