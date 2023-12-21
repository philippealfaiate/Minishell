/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:11:16 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/10 17:06:37 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static int	print_quote_err2(void)
{
	ft_putstr_fd("You forget some unclosed quotes. \n", STDERR_FILENO);
	return (1);
}

int	ft_check_uquotes2(char *str)
{
	char	opened;

	opened = 0;
	if (!str)
		return (0);
	while (*str && !opened)
	{
		if (*str == '\'' || *str == '"')
			opened = *str;
		str++;
	}
	while (*str && opened)
	{
		if (*str && *str == opened)
			opened = 0;
		str++;
	}
	if (*str)
		return (ft_check_uquotes2(str));
	else if (!opened)
		return (0);
	else
		return (print_quote_err2());
}

int	ft_skipquotes2(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\'')
	{
		i++;
		while (str[i] != '\'')
			i++;
	}
	if (str[i] == '"')
	{
		i++;
		while (str[i] != '"')
			i++;
	}
	return (i);
}
