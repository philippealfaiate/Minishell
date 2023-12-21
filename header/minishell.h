/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:38:33 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/13 19:11:06 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// header jm_
# include "../ms_jm/header/minishell_jm.h"

int	handle_execute_one_command(char *input, t_env *s_msenv, int status);

#endif