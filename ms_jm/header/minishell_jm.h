/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_jm.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:38:33 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/13 18:17:46 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_JM_H
# define MINISHELL_JM_H

// header jm_
# include "clib_jm.h"
# include "structure_jm.h"
# include "errmsg_jm.h"
# include "prototyping_jm.h"
# include <signal.h>
# include "../../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

# define GRN	"\001\e[0;32m\002"
# define MAG	"\001\e[0;35m\002"
# define WHT	"\001\e[0;37m\002"
# define CRESET	"\001\e[0m\002"

# ifndef PATH_MAX
#  define PATH_MAX 1024
# endif

# ifndef LLONG_MAX
#  define LLONG_MAX 9223372036854775807
# endif

# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define FAILED 0
# define NO_REDIRECT -1
# define BUILTINS "echo,cd,pwd,export,unset,env,exit"

# define IN 0
# define OUT 1

#endif