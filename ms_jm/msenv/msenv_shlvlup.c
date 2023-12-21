/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msenv_shlvlup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:17:02 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/10 14:38:26 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	shlvl_update(t_env **s_msenv)
{
	char	*shlvl_str;
	int		shlvl;
	t_env	*aux;

	if (!s_msenv)
		return ;
	aux = *s_msenv;
	while (aux && !str_equal("SHLVL", aux->key))
		aux = aux->next;
	if (aux && aux->value)
		shlvl = ft_atoi(aux->value);
	else
		shlvl = 1;
	shlvl++;
	shlvl_str = ft_itoa(shlvl);
	if (aux->value)
		free(aux->value);
	aux->value = shlvl_str;
	if (aux->key_pair)
		free(aux->key_pair);
	aux->key_pair = ft_strjoin_jm("SHLVL=", shlvl_str);
}
