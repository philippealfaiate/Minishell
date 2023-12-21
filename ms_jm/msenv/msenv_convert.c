/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msenv_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:55:28 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/11 18:58:24 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

size_t	msenv_size(t_env *s_msenv)
{
	size_t	size;
	t_env	*aux;

	size = 0;
	if (!s_msenv)
		return (0);
	aux = s_msenv;
	while (aux)
	{
		size++;
		aux = aux->next;
	}
	return (size);
}

char	**msenv_to_envp(t_env *s_msenv)
{
	char	**envp;
	t_env	*aux;
	int		i;

	if (!s_msenv)
		return (NULL);
	envp = malloc(sizeof(char *) * (msenv_size(s_msenv) + 1));
	aux = s_msenv;
	i = 0;
	while (aux)
	{
		envp[i] = ft_strdup_jm(aux->key_pair);
		i++;
		aux = aux->next;
	}
	envp[i] = NULL;
	return (envp);
}
