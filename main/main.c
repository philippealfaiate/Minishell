/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:05:53 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/15 00:05:48 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_env	*s_msenv;
	int		shell_status;
	int		fd;

	s_msenv = NULL;
	if (access("ms_void_export", F_OK) == 0)
		unlink("ms_void_export");
	fd = open("ms_void_export", O_CREAT | O_RDWR | O_APPEND, 0644);
	close(fd);
	if (argv && argc > 1)
		return (launch_error());
	s_msenv = msenv_ini(envp);
	if (!s_msenv)
		return (msenv_error());
	shell_status = ft_minishell(s_msenv);
	msenv_cleanup(&s_msenv);
	return (shell_status);
}
