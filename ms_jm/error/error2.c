/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:07:44 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/13 18:04:48 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	launch_error(void)
{
	print_error_msg("MINISHELL", \
	"script or command line argument not supported.\n");
	return (EXIT_FAILURE);
}

int	msenv_error(void)
{
	print_error_msg("MINISHELL", \
	"failled to initialize environment.\n");
	return (EXIT_FAILURE);
}

int	cd_error(void)
{
	print_error_msg("cd", "too many arguments");
	return (EXIT_FAILURE);
}

int	input_error(char *input, int *status, t_env ms_env)
{
	int	ret;

	(void)ms_env;
	ret = *status;
	if (ft_isempty(input))
		ret = 1;
	else if (ft_check_uquotes(input))
		ret = 1;
	return (ret);
}

int	ft_error(const char *msg, int status)
{	
	if (msg != NULL)
	{
		ft_putstr_fd("Error: ", STDOUT_FILENO);
		ft_putstr_fd((char *)msg, STDOUT_FILENO);
	}
	if (status < 0 || status > 255)
		status = EXIT_FAILURE;
	exit(status);
}
