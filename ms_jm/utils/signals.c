/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:16:15 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/13 21:38:40 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// static void	handle_sigint(int sig)
// Fonction appelée en cas de signal SIGINT (interruption par CTRL+C)
// Affiche un saut de ligne pour la clarté
// Remet en place le curseur au début de la ligne
// Remplace la ligne actuelle par une chaîne vide
// Redisplay pour mettre à jour l'affichage

// Fonction pour définir les signaux principaux du shell
// void	define_main_signals(void)
// sa_sigint.sa_handler = &handle_sigint; // Gestionnaire de SIGINT
// sigaction(SIGINT, &sa_sigint, NULL); // Associe SIGINT à la gestion de 
// handle_sigint
// sa_sigquit.sa_handler = SIG_IGN; // Ignore SIGQUIT (CTRL+\)
// sigaction(SIGQUIT, &sa_sigquit, NULL); // Associe SIGQUIT à l'ignorance

// Fonction pour définir les signaux pour l'exécution des commandes
// void	define_execute_signals(int child_pid)
// if (child_pid == 0)
//   sa.sa_handler = SIG_DFL; // Utilise le gestionnaire par défaut si 
// c'est un enfant
// else
//  sa.sa_handler = SIG_IGN; // Ignore le signal si c'est le parent
// sigaction(SIGINT, &sa, NULL); // Associe SIGINT au gestionnaire 
// défini dans 'sa'
// sigaction(SIGQUIT, &sa, NULL); // Associe SIGQUIT au gestionnaire 
// défini dans 'sa'

// Fonction pour définir les signaux pour les entrées en mode 'heredoc'
// void	define_heredoc_signals(int child_pid)
// if (child_pid == 0)
//  sa_sigint.sa_handler = SIG_DFL; // Utilise le gestionnaire par défaut 
// si c'est un enfant
// else
//  sa_sigint.sa_handler = SIG_IGN; // Ignore le signal si c'est le parent
// sigaction(SIGINT, &sa_sigint, NULL); // Associe SIGINT au gestionnaire 
// défini dans 'sa_sigint'
// sa_sigquit.sa_handler = SIG_IGN; // Ignore SIGQUIT (CTRL+\)
// sigaction(SIGQUIT, &sa_sigquit, NULL); // Associe SIGQUIT à l'ignorance

#include "../../header/minishell.h"

static void	handle_sigint(int sig)
{
	(void)sig;
	ft_putstr_fd("\n", STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	define_main_signals(void)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;
	struct sigaction	sa_sigtstp;

	sa_sigint.sa_handler = &handle_sigint;
	sa_sigint.sa_flags = 0;
	sigemptyset(&sa_sigint.sa_mask);
	sigaction(SIGINT, &sa_sigint, NULL);
	sa_sigquit.sa_handler = SIG_IGN;
	sa_sigquit.sa_flags = 0;
	sigemptyset(&sa_sigquit.sa_mask);
	sigaction(SIGQUIT, &sa_sigquit, NULL);
	sa_sigtstp.sa_handler = SIG_IGN;
	sa_sigtstp.sa_flags = 0;
	sigemptyset(&sa_sigtstp.sa_mask);
	sigaction(SIGTSTP, &sa_sigtstp, NULL);
}

void	define_execute_signals(int child_pid)
{
	struct sigaction	sa;

	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (child_pid == 0)
		sa.sa_handler = SIG_DFL;
	else
		sa.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}

void	define_heredoc_signals(int child_pid)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;

	sa_sigint.sa_flags = 0;
	sigemptyset(&sa_sigint.sa_mask);
	if (child_pid == 0)
		sa_sigint.sa_handler = SIG_DFL;
	else
		sa_sigint.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sa_sigint, NULL);
	sa_sigquit.sa_flags = 0;
	sigemptyset(&sa_sigquit.sa_mask);
	sa_sigquit.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa_sigquit, NULL);
}
