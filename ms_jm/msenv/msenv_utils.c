/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msenv_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:50:42 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/10 13:56:13 by jmoraes-         ###   ########.fr       */
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

char	*msenv_xkey(char *keypair)
{
	int		i;
	int		j;
	char	*key;

	i = 0;
	j = 0;
	if (!keypair || !*keypair)
		return (NULL);
	while (keypair[i] && keypair[i] != '=')
		i++;
	key = malloc (sizeof(char) * (i + 1));
	while (j < i)
	{
		key[j] = keypair[j];
		j++;
	}
	key[j] = '\0';
	return (key);
}

char	*msenv_xvalue(char *keypair)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	j = 0;
	if (!keypair || !*keypair)
		return (NULL);
	while (keypair && *keypair != '=')
		keypair++;
	keypair++;
	while (keypair && keypair[i] != '\0')
		i++;
	value = malloc (sizeof(char) * (i + 1));
	while (j < i)
	{
		value[j] = keypair[j];
		j++;
	}
	value[j] = '\0';
	return (value);
}
