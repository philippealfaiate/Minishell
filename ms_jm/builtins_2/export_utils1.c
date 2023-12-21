/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:09:23 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/15 00:15:42 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	void_in_env(char *key, t_env *s_msenv)
{
	t_env	*current;
	size_t	key_len;

	key_len = ft_strlen(key);
	current = s_msenv;
	while (current)
	{
		if (ft_strncmp(current->key, key, key_len) == 0 && \
			current->key[key_len] == '\0')
			return (1);
		current = current->next;
	}
	return (0);
}

static void	free_curr(char **curr)
{
	char	**temp;

	temp = curr;
	while (curr && *curr)
	{
		free(*curr);
		curr++;
	}
	free(temp);
}

void	ft_declare_void_env(char **voidkeys, t_env *s_msenv)
{
	int		fd;
	char	buffer[1024];
	char	**curr;
	int		len;

	fd = open("ms_void_export", O_RDONLY);
	if (fd == -1)
		return ;
	len = read(fd, buffer, 1024);
	if (len <= 0)
	{
		close(fd);
		return ;
	}
	buffer[len] = '\0';
	close(fd);
	voidkeys = ft_split(buffer, '\n');
	curr = voidkeys;
	while (voidkeys && *voidkeys)
	{
		if (!void_in_env(*voidkeys, s_msenv))
			declarex(*voidkeys);
		voidkeys++;
	}
	free_curr(curr);
}

int	ft_declare_env(t_env *s_msenv)
{
	t_env	*curr;
	char	**void_keys;

	if (!s_msenv)
		return (0);
	curr = s_msenv;
	while (curr)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(curr->key, STDOUT_FILENO);
		if (curr->value)
		{
			ft_putstr_fd("=", STDOUT_FILENO);
			ft_putstr_fd("\"", STDOUT_FILENO);
			ft_putstr_fd(curr->value, STDOUT_FILENO);
			ft_putstr_fd("\"", STDOUT_FILENO);
		}
		ft_putstr_fd("\n", STDOUT_FILENO);
		curr = curr->next;
	}
	void_keys = NULL;
	ft_declare_void_env(void_keys, s_msenv);
	return (0);
}
