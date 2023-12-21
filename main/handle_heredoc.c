/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:00:11 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/13 20:44:25 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	*get_heredoc_position(char *str)
{
	while (*str && str[1])
	{
		if (*str == '\'')
		{
			str++;
			while (*str != '\'')
				str++;
		}
		if (*str == '"')
		{
			str++;
			while (*str != '"')
				str++;
		}
		if (*str == '<' && str[1] == '<')
			return (str);
		str++;
	}
	return (NULL);
}

static char	*tmp_filename(int heredoc_number)
{
	char	filename[30];
	char	*number_str;

	ft_bzero(filename, 30);
	number_str = ft_itoa(heredoc_number);
	ft_strlcat(filename, "/tmp/heredoc", 30);
	ft_strlcat(filename, number_str, 30);
	free(number_str);
	return (ft_strdup_jm(filename));
}

void	read_heredoc(int *exit_status, t_env *s_msenv, t_heredoc *s_hd,
		int heredoc_number)
{
	char	*filename;
	int		tmp_file_fd;

	filename = tmp_filename(heredoc_number);
	tmp_file_fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	free(filename);
	readline_heredoc(exit_status, tmp_file_fd, s_msenv, s_hd);
	close(tmp_file_fd);
	free(s_hd->delimiter);
	msenv_cleanup(&s_msenv);
	rl_clear_history();
	exit(EXIT_SUCCESS);
}

int	exec_heredoc(t_heredoc	*s_hd, int heredoc_number, int *exit_status,
		t_env *s_msenv)
{
	int	child_pid;

	child_pid = fork();
	define_heredoc_signals(child_pid);
	if (child_pid == -1)
		print_perror_msg("fork - heredoc_prompt", s_hd->delimiter);
	else if (child_pid == 0)
		read_heredoc(exit_status, s_msenv, s_hd, heredoc_number);
	else
	{
		*exit_status = wait_for_child(child_pid, TRUE);
		define_main_signals();
		if (*exit_status != EXIT_SUCCESS)
			return (FAILED);
	}
	return (SUCCESS);
}

int	handle_heredoc(char *input, int *exit_status, t_env *s_msenv)
{
	static int	heredoc_number;
	char		*heredoc_position;
	t_heredoc	s_hd;

	s_hd.quoted = 0;
	heredoc_number = -1;
	heredoc_position = get_heredoc_position(input);
	if (!heredoc_position)
		return (SUCCESS);
	delimiter_cleaner(&heredoc_position, &s_hd);
	heredoc_number--;
	*heredoc_position = heredoc_number;
	heredoc_position++;
	s_hd.delimiter = get_label_name(heredoc_position);
	if (!exec_heredoc(&s_hd, heredoc_number, exit_status, s_msenv))
	{
		free(s_hd.delimiter);
		return (FAILED);
	}
	free(s_hd.delimiter);
	return (handle_heredoc(input, exit_status, s_msenv));
}
