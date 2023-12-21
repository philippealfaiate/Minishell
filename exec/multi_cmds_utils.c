/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_cmds_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:30 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/13 18:56:28 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	*init_children_pid(char **cmd)
{
	int		*pid;
	size_t	size;

	size = sizeof(int) * (ft_arraylen(cmd) + 1);
	pid = malloc(size);
	if (!pid)
		return (NULL);
	ft_bzero(pid, size);
	return (pid);
}

void	clean_after_execute(int *pid)
{
	close_extra_fds();
	free(pid);
}

void	quit_child(char **cmd, t_env **s_msenv)
{
	rl_clear_history();
	if (s_msenv)
		msenv_cleanup(s_msenv);
	ft_freearray(cmd);
	close_all_fds();
	exit(EXIT_FAILURE);
}
