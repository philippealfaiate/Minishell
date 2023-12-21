/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:50:40 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/14 16:20:07 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static void	create_path(char base[], char *part1, char *part2, char *part3)
{
	*base = 0;
	ft_strlcat(base, part1, PATH_MAX);
	ft_strlcat(base, part2, PATH_MAX);
	ft_strlcat(base, part3, PATH_MAX);
}

static int	is_path(char *command)
{
	if (*command == '.')
		command++;
	if (*command == '.')
		command++;
	if (*command == '/')
		return (TRUE);
	return (FALSE);
}

static char	*local_path(char *command, t_env *s_msenv)
{
	char	full_path[PATH_MAX];

	if (*command == '/')
		return (ft_strdup_jm(command));
	full_path[0] = 0;
	create_path(full_path, msenv_getvalue("PWD", &s_msenv), "/", command);
	return (ft_strdup_jm(full_path));
}

char	*get_path(char *command, t_env *s_msenv)
{
	char	*path_env;
	char	**paths;
	char	current_path[PATH_MAX];
	char	**paths_start;

	if (is_path(command))
		return (local_path(command, s_msenv));
	path_env = msenv_getvalue("PATH", &s_msenv);
	if (path_env == NULL)
		return (NULL);
	paths = ft_split(path_env, ':');
	paths_start = paths;
	while (paths && *paths)
	{
		create_path(current_path, *paths, "/", command);
		if (access(current_path, F_OK) == 0)
		{
			ft_freearray(paths_start);
			return (ft_strdup_jm(current_path));
		}
		paths++;
	}
	ft_freearray(paths_start);
	return (NULL);
}
