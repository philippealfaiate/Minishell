/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:13:20 by phialfai          #+#    #+#             */
/*   Updated: 2023/12/13 21:09:39 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	delimiter_cleaner(char **heredoc_position, t_heredoc *s_hd)
{
	char	*tmp;

	if (ft_strchr(*heredoc_position, '\'') != NULL \
		|| ft_strchr(*heredoc_position, '\"') != NULL)
		s_hd->quoted = 1;
	if (s_hd->quoted == 1)
	{
		tmp = *heredoc_position;
		while (*tmp)
		{
			if (*tmp == '$' && (tmp[1] == '\'' || tmp[1] == '\"'))
				ft_memmove(tmp, tmp + 1, ft_strlen(tmp));
			tmp++;
		}
	}
}

void	readline_heredoc(int *exit_status, int tmp_file_fd, \
	t_env *s_msenv, t_heredoc *s_hd)
{
	char	*line_read;

	line_read = readline("> ");
	while (line_read && !str_equal(line_read, s_hd->delimiter))
	{
		expand_exit_status(&line_read, *exit_status);
		if (s_hd->quoted == 0)
			expand_variables(&line_read, s_msenv);
		ft_putstr_fd(line_read, tmp_file_fd);
		ft_putchar_fd('\n', tmp_file_fd);
		free(line_read);
		line_read = readline("> ");
	}
	if (!line_read)
		print_error_msg(ERR_HDOC, s_hd->delimiter);
	free(line_read);
}
