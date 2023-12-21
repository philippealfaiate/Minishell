/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errmsg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:01:44 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/13 19:25:55 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRMSG_H
# define ERRMSG_H

//jm_
# define FALSE 0
# define TRUE 1
# define NOT_EXECUTABLE_MSG "Is a directory"
# define CMD_NOT_FOUND_MSG	"command not found"
# define ARG_ERR "minishell can't take options or arguments."
# define GEN_ERR "Error"               // général
# define INTERRUPT 128
# define CMD_NOT_FOUND 127
# define PERMISSION_DENIED 126
# define NOT_EXECUTABLE 126
# define OUT_OF_RANGE 255
# define BUILTIN_MISUSE 2
# define FORK_ERROR -1
# define ERR_HDOC "warning: heredoc delimited by EOF. Wanted"

#endif