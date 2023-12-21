/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:30:32 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/11 15:21:32 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

// int	ft_env(char **args, t_env **s_msenv)

int	ft_env(char *cmd, char **args, t_env **s_msenv)
{
	t_env	*curr;

	(void)cmd;
	(void)args;
	curr = *s_msenv;
	while (curr)
	{
		if (curr->key)
		{
			ft_putstr_fd(curr->key, STDOUT_FILENO);
			ft_putstr_fd("=", STDOUT_FILENO);
			ft_putstr_fd(curr->value, STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
		curr = curr->next;
	}
	return (0);
}
