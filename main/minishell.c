/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:06:55 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/13 15:44:01 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	ft_minishell(t_env *s_msenv)
{
	int		status;
	char	*input;
	char	**cmds;

	status = EXIT_SUCCESS;
	while (1)
	{
		define_main_signals();
		input = prompt_input(s_msenv);
		if (has_input_error(input, &status, s_msenv))
			continue ;
		if (!ft_haspipe(input))
			status = handle_execute_one_command(input, s_msenv, status);
		else
		{
			handle_expansions(&input, s_msenv, status);
			cmds = split_commands(input);
			free(input);
			status = execute_multiple_commands(cmds, &s_msenv);
			ft_freearray(cmds);
		}
	}
	return (status);
}
