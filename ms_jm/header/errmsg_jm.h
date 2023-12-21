/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errmsg_jm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:01:44 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/14 13:41:39 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRMSG_JM_H
# define ERRMSG_JM_H

//jm_
# define FALSE 0
# define TRUE 1

# define INTERRUPT 128
# define CMD_NOT_FOUND 127
# define PERMISSION_DENIED 126
# define NOT_EXECUTABLE 126
# define OUT_OF_RANGE 255
# define BUILTIN_MISUSE 2
# define FORK_ERROR -1
# define CMD_NOT_FOUND_MSG	"command not found"
# define NOT_EXECUTABLE_MSG "Is a directory"
# define ERR_HDOC "warning: heredoc delimited by EOF. Wanted"

// # define NOT_EXECUTABLE_MSG "Is a directory"
// # define CMD_NOT_FOUND_MSG	"command not found"
// # define ARG_ERR "minishell can't take options or arguments." 
// # define GEN_ERR "Error"               // général
// # define FORK_ERROR -1
// # define OUT_OF_RANGE 255
// # define INTERRUPT 130                 // interruption (comme Ctrl-C)
// /* # define INTERRUPT 128 */
// # define CMD_NOT_FOUND 127             // commande n'est pas trouvée
// # define PERMISSION_DENIED 126         // problèmes de permission
// # define NOT_EXECUTABLE 126            // fichier n'est pas exécutable
// # define INVALID_PATH 125              // chemin non valide
// # define INVALID_FILE 124              // fichier non valide
// # define OUT_OF_MEMORY 123             // allocation mémoire échouée
// # define CMD_TIMEOUT 122               // délai d'exécution dépassé
// # define SIGNAL_RECEIVED 121           // signal est reçu
// # define SYNTAX_ERROR 120              // erreur de syntaxe
// # define IO_ERROR 119                  // erreur d'entrée/sortie
// # define CONFIG_ERROR 118              // problème de configuration du shell
// # define AUTH_FAILURE 117              // échec d'authentification
// # define NOT_FOUND 116                 // entité non trouvée
// # define RESOURCE_BUSY 115             // ressource est occupée
// # define OPERATION_NOT_PERMITTED 114   // opération non permise
// # define BUILTIN_MISUSE 2

#endif