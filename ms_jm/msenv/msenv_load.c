/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msenv_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:35:35 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/14 16:13:36 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	lst_load(char *args, t_env **s_msenv)
{
	struct s_env	*new_node;
	struct s_env	*aux_node;

	if (!ft_strchr(args, '='))
		return (0);
	new_node = malloc(sizeof(struct s_env));
	if (!new_node)
		return (1);
	new_node->key = msenv_xkey(args);
	new_node->value = msenv_xvalue(args);
	new_node->key_pair = ft_strdup_jm(args);
	new_node->next = NULL;
	if (!*s_msenv)
	{
		*s_msenv = new_node;
		return (1);
	}
	aux_node = *s_msenv;
	while (aux_node->next)
		aux_node = aux_node->next;
	aux_node->next = new_node;
	return (0);
}

static char	*ft_getuid(char *cwd)
{
	if (*cwd)
	{
		if (ft_strrchr(cwd, '/') != NULL)
		{
			return (ft_strrchr(cwd, '/') + 1);
		}
		else
			return (cwd);
	}
	return (NULL);
}

void	msenv_load(char **envp, t_env **s_msenv)
{
	int		i;
	char	*value;
	char	*tmp;

	value = NULL;
	i = 0;
	if (!envp || !s_msenv)
		return ;
	while (envp[i])
	{
		lst_load(envp[i], s_msenv);
		i++;
	}
	value = msenv_getvalue("XDG_RUNTIME_DIR", s_msenv);
	tmp = ft_strjoin("UID=", ft_getuid(value));
	lst_load(tmp, s_msenv);
	free(tmp);
	shlvl_update(s_msenv);
}
