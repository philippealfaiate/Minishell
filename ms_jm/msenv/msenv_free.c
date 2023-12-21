/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msenv_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:58:48 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/13 20:13:03 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	ft_cleanup_msenvnode(t_env **s_msenv, const char *key)
{
	t_env	*prev;
	t_env	*current;

	prev = NULL;
	current = *s_msenv;
	if (s_msenv == NULL || *s_msenv == NULL || key == NULL)
		return ;
	while (current != NULL && strcmp(current->key, key) != 0)
	{
		prev = current;
		current = current->next;
	}
	if (current == NULL)
		return ;
	if (prev != NULL)
		prev->next = current->next;
	else
		*s_msenv = current->next;
	free(current->key);
	free(current->value);
	free(current->key_pair);
	free(current);
}

void	ft_cleanup_msenv(t_env **s_msenv)
{
	t_env	*current;
	t_env	*next;

	if (s_msenv == NULL)
		return ;
	current = *s_msenv;
	while (current != NULL)
	{
		next = current->next;
		free(current->key);
		free(current->value);
		free(current->key_pair);
		free(current);
		current = next;
	}
	*s_msenv = NULL;
}
