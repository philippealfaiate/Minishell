/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:07:32 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/14 17:19:02 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static char	*ft_getdirectory(char *cwd)
{
	if (*cwd)
	{
		if (ft_strrchr(cwd, '/') != NULL)
		{
			return (ft_strrchr(cwd, '/') + 1);
		}
		else
			return (cwd);
	}
	return (NULL);
}

char	*get_prompt_str(t_env *s_msenv)
{
	char		*user;
	char		*cwd;
	char		*directory;
	static char	prompt[PATH_MAX];

	user = msenv_getvalue("USER", &s_msenv);
	if (!user)
		user = "UNKNOWN";
	cwd = msenv_getvalue("PWD", &s_msenv);
	if (!cwd)
		cwd = "/UNKNOWN";
	directory = ft_getdirectory(cwd);
	if (ft_strncmp(cwd, "/", 2) == 0 || directory == NULL)
		directory = "ROOT";
	ft_bzero(prompt, sizeof(prompt));
	ft_strlcat(prompt, GRN, PATH_MAX);
	ft_strlcat(prompt, user, PATH_MAX);
	ft_strlcat(prompt, WHT, PATH_MAX);
	ft_strlcat(prompt, "@", PATH_MAX);
	ft_strlcat(prompt, MAG, PATH_MAX);
	ft_strlcat(prompt, directory, PATH_MAX);
	ft_strlcat(prompt, CRESET, PATH_MAX);
	ft_strlcat(prompt, "$ ", PATH_MAX);
	return (prompt);
}

char	*prompt_input(t_env *s_msenv)
{
	char	*input;

	input = readline(get_prompt_str(s_msenv));
	if (!input)
		ft_exit(NULL, NULL, &s_msenv);
	if (input && *input)
		add_history(input);
	return (input);
}
