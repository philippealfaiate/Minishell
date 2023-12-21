/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:34:14 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/13 22:14:46 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// `WEXITSTATUS(status)` est une macro en C qui est utilisée pour obtenir le 
// code de sortie d'un processus enfant qui a terminé normalement. 
// - Lorsqu'un processus se termine, il peut renvoyer à son processus parent
//  une petite quantité d'informations sur la cause de la terminaison, en 
// utilisant le code de sortie³. Ce code de sortie est une valeur 
// entre 0 et 255
//  que le processus sortant passe en argument à `exit`.
// - `WEXITSTATUS(status)` évalue à la valeur des 8 bits de poids faible de 
// l'argument de statut que le processus enfant a passé à `_exit()` ou 
// `exit()`, 
// ou la valeur que le processus enfant a renvoyée de `main()`¹.
// - Cette macro ne doit être utilisée que si `WIFEXITED(status)` a renvoyé 
// vrai.
//  `WIFEXITED(status)` renvoie vrai si le processus enfant s'est terminé 
// normalement.
// Par exemple, si le processus 12345 appelle `exit(7)` et que vous appelez
//  `waitpid(12345, &status, 0)`, alors `WEXITSTATUS(status)` donnera 7.
// J'espère que cela vous aide à comprendre `WEXITSTATUS(status)` ! 
// Function to check if the termination signal is SIGINT (Control-C)
// static int	is_control_c(int status)
// Function to check if the termination signal is SIGQUIT (Control-\)
// static int	is_control_slash(int status)
// Function to handle signal interrupts
// static int	handle_signal_interrupt(int status, int is_last_child)
// If Control-C was pressed, print a newline
//	  if (is_control_c(status))
//		 ft_putstr_fd("\n", STDOUT_FILENO);
// If Control-\ was pressed and it's the last child, print "Quit\n"
//	  if (is_control_slash(status) && is_last_child)
//		 ft_putstr_fd("Quit\n", STDOUT_FILENO);
// Return the interrupt signal
//	  return (INTERRUPT + WTERMSIG(status));
// #define INTERRUPT ou const int INTERRUPT dans votre code.
// errmsg.h
// # define INTERRUPT 130                 // interruption (comme Ctrl-C)
// Dans l’expression return (INTERRUPT + WTERMSIG(status));, INTERRUPT 
// est probablement une valeur constante qui est ajoutée à la valeur 
// du signal de terminaison du processus (obtenue par WTERMSIG(status)). 
// Cela pourrait être utilisé pour distinguer les interruptions normales 
// des interruptions spéciales dans votre code.
// Function to wait for a child process to finish
//    int	wait_for_child(int child_pid, int is_last_child)
// If there was an error in fork, return failure
//    if (child_pid == FORK_ERROR)
//		return (EXIT_FAILURE);
// Wait for the child process to finish
//    if (waitpid(child_pid, &status, 0) == -1)
// 	    print_perror_msg("waitpid", ft_itoa(child_pid));
// If the child was terminated by a signal, handle the interrupt
//    if (WIFSIGNALED(status))
// 	    return (handle_signal_interrupt(status, is_last_child));
// If the child exited normally, return its exit status
//    if (WIFEXITED(status))
// 	    return (WEXITSTATUS(status));
// If none of the above, return failure
//      return (EXIT_FAILURE);
// Function to wait for all children processes to finish
// 		int	wait_for_children(int children_pid[1024])
// Loop through all child PIDs
// 		while (children_pid[i] != 0)
// Check if it's the last child
// 		is_last_child = children_pid[i + 1] == 0;
// Wait for the child to finish and get its exit status
// 		exit_status = wait_for_child(children_pid[i], is_last_child);
// Clean up after execution
// 		clean_after_execute(children_pid);
// Return the exit status
// 		return (exit_status);

#include "../header/minishell.h"

static int	is_control_c(int status)
{
	return (WTERMSIG(status) == SIGINT);
}

static int	is_control_slash(int status)
{
	return (WTERMSIG(status) == SIGQUIT);
}

static int	handle_signal_interrupt(int status, int is_last_child)
{
	if (is_control_c(status))
		ft_putstr_fd("", STDOUT_FILENO);
	if (is_control_slash(status) && is_last_child)
		ft_putstr_fd("Quit (core dumped)\n", STDOUT_FILENO);
	return (INTERRUPT + WTERMSIG(status));
}

int	wait_for_child(int child_pid, int is_last_child)
{
	int	status;

	if (child_pid == FORK_ERROR)
		return (EXIT_FAILURE);
	if (waitpid(child_pid, &status, 0) == -1)
		print_perror_msg("waitpid", ft_itoa(child_pid));
	if (WIFSIGNALED(status))
	{
		if (is_last_child)
			ft_putstr_fd("\n", STDOUT_FILENO);
		return (handle_signal_interrupt(status, is_last_child));
	}
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}

int	wait_for_children(int children_pid[1024])
{
	int	i;
	int	exit_status;
	int	is_last_child;

	i = 0;
	exit_status = 0;
	while (children_pid[i] != 0)
	{
		is_last_child = children_pid[i + 1] == 0;
		exit_status = wait_for_child(children_pid[i], is_last_child);
		if (is_last_child)
			ft_putstr_fd("\n", STDOUT_FILENO);
		i++;
	}
	clean_after_execute(children_pid);
	return (exit_status);
}
