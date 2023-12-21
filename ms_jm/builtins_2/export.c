/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:01:20 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/15 00:07:02 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	void_can_export(char *key)
{
	int		fdr;
	char	buffer[1024];
	int		len;

	buffer[0] = '\n';
	buffer[1] = '\0';
	fdr = open("ms_void_export", O_RDONLY, 0644);
	len = read(fdr, buffer, 1024);
	if (!buffer[0])
	{
		close(fdr);
		return (1);
	}
	if (*buffer && ft_strnstr(buffer, key, ft_strlen(key)) == NULL)
		return (1);
	close(fdr);
	return (0);
}

void	void_export(char *key)
{
	int		fdw;
	char	buffer[1024];

	buffer[0] = '\n';
	buffer[1] = '\0';
	fdw = open("ms_void_export", O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fdw == -1)
		return ;
	if (*buffer && ft_strnstr(buffer, key, ft_strlen(key)) == NULL)
	{
		ft_putstr_fd(key, fdw);
		ft_putstr_fd("\n", fdw);
	}
	close(fdw);
}

int	export_check_key(char *key, char **args, t_env **s_msenv)
{
	int		exit_status;

	exit_status = EXIT_SUCCESS;
	if (!ft_valkey(key) || ft_str_equal(*args, "="))
	{
		ft_print_varname_err_msg("export", *args);
		exit_status = 1;
	}
	else if (ft_valkey(key) && ft_strchr(*args, '=') == NULL)
	{
		if (void_can_export(key))
			void_export(key);
	}
	else if (msenv_getnode(key, s_msenv) && ft_strchr(*args, '='))
		msenv_update(key, ft_valueonly(*args), s_msenv);
	else
		exit_status = lst_load(*args, s_msenv);
	return (exit_status);
}

int	ft_export(char *cmd, char **args, t_env **s_msenv)
{
	char	*key;
	int		exit_status;

	(void)cmd;
	args++;
	exit_status = EXIT_SUCCESS;
	if (!*args)
		return (ft_declare_env(*s_msenv));
	while (*args)
	{
		key = ft_keyonly(*args);
		exit_status = export_check_key(key, args, s_msenv);
		free(key);
		args++;
	}
	return (exit_status);
}
