/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:10:24 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/11 19:05:11 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	ft_printlst(t_env **list)
{
	t_env	*current;

	if (!list || !(*list))
	{
		ft_putstr_fd("list vide.\n", STDOUT_FILENO);
		return ;
	}	
	current = *list;
	while (current != NULL)
	{
		if (!current->value)
			printf("Key: %s, Value: NULL\n", current->key);
		else
			printf("Key: %s, Value: %s\n", current->key, current->value);
		current = current->next;
	}
	return ;
}
