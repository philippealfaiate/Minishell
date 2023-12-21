/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_expansions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:56:36 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/11/23 11:41:44 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	handle_expansions(char **input, t_env *s_msenv, int exit_status)
{
	expand_exit_status(input, exit_status);
	expand_variables(input, s_msenv);
}
