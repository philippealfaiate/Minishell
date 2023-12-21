/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:03:01 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/12 20:43:38 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	has_input_error(char *input, int *exit_status, t_env *s_msenv)
{
	int	result;

	result = FALSE;
	if (ft_isempty(input))
		result = TRUE;
	else if (ft_check_uquotes(input))
		result = TRUE;
	else if (is_invalid_syntax(input))
	{
		*exit_status = 2;
		result = TRUE;
	}
	else if (handle_heredoc(input, exit_status, s_msenv) == FAILED)
		result = TRUE;
	if (result == TRUE)
		free(input);
	return (result);
}
