/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:09:23 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/15 00:16:17 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

char	*ft_keyonly(char *key_pair)
{
	int	i;

	i = 0;
	while (key_pair[i] != '=' && key_pair[i])
		i++;
	return (ft_substr(key_pair, 0, i));
}

char	*ft_valueonly(char *key_pair)
{
	int	i;

	i = 0;
	while (key_pair[i] != '=' && key_pair[i])
		i++;
	if (!key_pair[i])
		return (NULL);
	return (&key_pair[i + 1]);
}

void	declarex(char *voidkeys)
{
	ft_putstr_fd("declare -x ", STDOUT_FILENO);
	ft_putstr_fd(voidkeys, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}
