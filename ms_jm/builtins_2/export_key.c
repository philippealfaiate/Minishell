/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:57:12 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/11 18:44:34 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static int	ft_isdigit2(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_isalpha2(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

static int	ft_isalnum2(int c)
{
	return (ft_isdigit2(c) || ft_isalpha2(c));
}

int	ft_valkey(char *name)
{
	if (!ft_isalpha2(*name))
		return (0);
	while (*name)
	{
		if (!(ft_isalnum2(*name) || *name == '_'))
			return (0);
		name++;
	}
	return (1);
}
