/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:25:08 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/13 17:44:44 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	close_extra_fds(void)
{
	int	last_fd;

	last_fd = open("./last_fd", O_RDWR | O_CREAT, 0666);
	if (last_fd == -1)
		last_fd = 1024;
	while (last_fd > STDERR_FILENO)
	{
		close(last_fd);
		last_fd--;
	}
}

void	close_all_fds(void)
{
	close_extra_fds();
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}
