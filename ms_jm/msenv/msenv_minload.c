/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msenv_minload.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:40:19 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/14 11:23:43 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	lst_minload(char *envp, t_env **s_msenv)
{
	struct s_env	*new_node;
	struct s_env	*aux_node;

	new_node = malloc(sizeof(struct s_env));
	if (!new_node)
		return ;
	new_node->key = msenv_xkey(envp);
	new_node->value = msenv_xvalue(envp);
	new_node->key_pair = ft_strdup_jm(envp);
	new_node->next = NULL;
	if (!*s_msenv)
	{
		*s_msenv = new_node;
		return ;
	}
	aux_node = *s_msenv;
	while (aux_node->next)
		aux_node = aux_node->next;
	aux_node->next = new_node;
}

void	msenv_minload(t_env **s_msenv)
{
	char	*pwd;
	char	cwd[PATH_MAX];

	if (!s_msenv)
		return ;
	getcwd(cwd, PATH_MAX);
	pwd = ft_strjoin_jm("PWD=", cwd);
	lst_minload("SHLVL=2", s_msenv);
	lst_minload("OLDPWD=", s_msenv);
	lst_minload("UID=1000", s_msenv);
	if (pwd)
		lst_minload(pwd, s_msenv);
}
