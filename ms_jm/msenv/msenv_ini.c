/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msenv_ini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:26:07 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/12 19:12:16 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_env	*msenv_ini(char **envp)
{
	t_env	*s_msenv;

	s_msenv = NULL;
	if (!envp || !envp[0])
		msenv_minload(&s_msenv);
	else
		msenv_load(envp, &s_msenv);
	return (s_msenv);
}
