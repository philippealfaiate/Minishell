/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msenv_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:42:12 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/11 19:00:03 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	msenv_cleanupnode(t_env *s_msenv)
{
	if (!s_msenv)
		return ;
	if (s_msenv->key)
	{
		free(s_msenv->key);
		s_msenv->key = NULL;
		free(s_msenv->value);
		s_msenv->value = NULL;
		free(s_msenv->key_pair);
		s_msenv->key_pair = NULL;
		s_msenv->next = NULL;
	}
}

void	msenv_cleanup(t_env **s_msenv)
{
	t_env	*curr;
	t_env	*next;

	if (!s_msenv)
		return ;
	curr = *s_msenv;
	while (curr)
	{
		next = curr->next;
		msenv_cleanupnode(curr);
		free (curr);
		curr = next;
	}
	*s_msenv = NULL;
}
