/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_execute_one_command.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:13:53 by phialfai          #+#    #+#             */
/*   Updated: 2023/12/14 15:16:09 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	handle_execute_one_command(char *input, t_env *s_msenv, int status)
{
	handle_expansions(&input, s_msenv, status);
	status = execute_one_command(input, &s_msenv);
	return (status);
}
