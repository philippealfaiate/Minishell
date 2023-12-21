/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:54:52 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/11 19:05:50 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	ft_printarray(char **arr)
{
	int	i;

	i = 0;
	if (!arr || !arr[i])
		return (-1);
	while (arr[i])
	{
		ft_putnbr_fd(i, STDOUT_FILENO);
		ft_putstr_fd(arr[i], STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		i++;
	}
	return (0);
}

int	ft_arraylen(char **arr)
{
	int	i;

	i = 0;
	if (!arr || !arr[i])
		return (-1);
	while (arr[i])
	{
		i++;
	}
	return (i);
}

void	ft_freearray(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	if (arr)
		free(arr);
}
