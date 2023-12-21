/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:57:15 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/11/22 13:57:18 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	is_varname(char c)
{
	return (ft_isalnum(c) || c == '_');
}

int	is_valid_varname(char *name)
{
	if (!ft_isalpha(*name))
		return (FALSE);
	while (*name)
	{
		if (!is_varname(*name))
			return (FALSE);
		name++;
	}
	return (TRUE);
}
