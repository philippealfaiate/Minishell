/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:02:52 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/14 16:15:43 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static void	remove_from_msenv(char *varname, t_env **s_msenv);
static void	msenv_del_next_node(t_env **node);

int	ft_unset(char *cmd, char **args, t_env **s_msenv)
{
	char	*varname;
	int		exit_status;

	(void)cmd;
	args++;
	exit_status = EXIT_SUCCESS;
	if (!*args)
		return (0);
	while (*args)
	{
		varname = *args;
		if (!is_valid_varname(varname))
		{
			print_varname_error_msg("unset", varname);
			exit_status = EXIT_FAILURE;
		}
		else
			remove_from_msenv(varname, s_msenv);
		args++;
	}
	return (exit_status);
}

static void	remove_from_msenv(char *varname, t_env **s_msenv)
{
	t_env	*aux;

	aux = *s_msenv;
	while (aux && aux->next)
	{
		if (ft_strncmp((aux->next)->key_pair, varname, ft_strlen(varname)) == 0)
		{
			if ((aux->next)->key_pair[ft_strlen(varname)] == '=')
				return (msenv_del_next_node(&aux));
		}
		aux = aux->next;
	}
}

static void	msenv_del_next_node(t_env **node)
{
	t_env	*temp;

	temp = (*node)->next;
	(*node)->next = ((*node)->next)->next;
	free(temp->key);
	free(temp->value);
	free(temp->key_pair);
	free(temp);
}
