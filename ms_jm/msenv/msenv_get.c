/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msenv_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:03:08 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/14 18:13:42 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

char	*msenv_getkey(char *value, t_env **s_msenv)
{
	t_env	*node;

	if (!value || !s_msenv)
		return (NULL);
	node = *s_msenv;
	while (node)
	{
		if (node->value && ft_str_equal(node->value, value))
			return (node->key);
		node = node->next;
	}
	return (NULL);
}

char	*msenv_getvalue(char *key, t_env **s_msenv)
{
	t_env	*node;

	if (!key || !s_msenv)
		return (NULL);
	node = *s_msenv;
	while (node && !ft_str_equal(key, node->key))
		node = node->next;
	if (node && ft_str_equal(key, node->key))
		return (node->value);
	else
		return (NULL);
}

t_env	*msenv_getnode(char *key, t_env **s_msenv)
{
	t_env	*aux;

	if (!key || !s_msenv)
		return (NULL);
	aux = *s_msenv;
	while (aux && !ft_str_equal(key, aux->key))
		aux = aux->next;
	if (aux && ft_str_equal(key, aux->key))
		return (aux);
	else
		return (NULL);
}
