/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:31:47 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/14 16:08:52 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static int	ft_cderror(void)
{
	print_error_msg("cd", "too many arguments");
	return (EXIT_FAILURE);
}

char	*ft_getpath2(char *args, t_env **s_msenv)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	if (args[0] == '\0')
		path = msenv_getvalue("HOME", s_msenv);
	else if (args[0] == '~')
	{
		path = args + 1;
		if (path == NULL || *path == '\0')
			path = msenv_getvalue("HOME", s_msenv);
	}
	else if (ft_str_equal(args, "-"))
		path = msenv_getvalue("OLDPWD", s_msenv);
	else
		return (args);
	return (path);
}

int	ft_cd(char *cmd, char **args, t_env **s_msenv)
{
	char	*path;
	char	*oldpwd;
	char	cwd[PATH_MAX];
	char	*pwd;

	(void)cmd;
	args++;
	if (args[0] && args[1])
		return (ft_cderror());
	else if (args[0])
		path = ft_getpath2(args[0], s_msenv);
	else
		path = msenv_getvalue("HOME", s_msenv);
	oldpwd = ft_strdup(getcwd(cwd, PATH_MAX));
	if (chdir(path) != 0)
	{
		print_perror_msg("cd", args[0]);
		free (oldpwd);
		return (EXIT_FAILURE);
	}
	pwd = getcwd(cwd, PATH_MAX);
	oldpwd_update(oldpwd, s_msenv);
	free (oldpwd);
	pwd_update(pwd, s_msenv);
	return (EXIT_SUCCESS);
}
