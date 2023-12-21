/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variables_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:57:15 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/10 16:11:09 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

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

int	ft_is_varname(char c)
{
	return (ft_isalnum2(c) || c == '_');
}

int	ft_is_valid_varname(char *name)
{
	if (!ft_isalpha2(*name))
		return (0);
	while (*name)
	{
		if (!is_varname(*name))
			return (0);
		name++;
	}
	return (1);
}
