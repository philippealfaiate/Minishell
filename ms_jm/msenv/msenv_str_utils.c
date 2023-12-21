/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msenv_str_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:59:36 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/08 13:33:20 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

char	*ft_getkey(char *key_pair)
{
	int	i;

	i = 0;
	while (key_pair[i] != '=' && key_pair[i])
		i++;
	return (ft_substr(key_pair, 0, i));
}

char	*ft_getvalue(char *key_pair)
{
	int	i;

	i = 0;
	while (key_pair[i] != '=' && key_pair[i])
		i++;
	if (!key_pair[i])
		return (NULL);
	return (&key_pair[i + 1]);
}

char	*ft_create_keypair(char *name, char *value)
{
	char	*key_pair;
	int		key_pair_size;
	int		i;

	key_pair_size = ft_strlen(name) + ft_strlen(value) + 2;
	key_pair = malloc(key_pair_size * sizeof(char));
	i = 0;
	while (*name)
		key_pair[i++] = *name++;
	key_pair[i++] = '=';
	while (*value)
		key_pair[i++] = *value++;
	key_pair[i] = '\0';
	return (key_pair);
}
