/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:12:24 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/11 19:01:13 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	ft_print_error_msg(char *command, char *msg)
{
	char	*pid_str;

	pid_str = NULL;
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(command, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	if (pid_str)
		free (pid_str);
}

void	ft_exit_w_error(char *command, char *msg, int error)
{
	print_error_msg(command, msg);
	close_all_fds();
	rl_clear_history();
	exit(error);
}

void	ft_print_perror_msg(char *command, char *perror_msg)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(command, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	perror(perror_msg);
}

void	ft_exit_w_perror(char *command, char *perror_msg, int error)
{
	print_perror_msg(command, perror_msg);
	close_all_fds();
	rl_clear_history();
	exit(error);
}

void	ft_print_varname_err_msg(char *command, char *varname)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(command, STDERR_FILENO);
	ft_putstr_fd(": `", STDERR_FILENO);
	ft_putstr_fd(varname, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
}
