/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msenv_updates.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:24:22 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/11 18:57:04 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	pwd_update(char *pwd, t_env **s_msenv)
{
	t_env	*aux;
	char	*pwd_cp;

	if (!s_msenv || !pwd)
		return ;
	if (pwd[0])
		pwd_cp = ft_strdup_jm(pwd);
	else
		pwd_cp = ft_strdup_jm("");
	aux = msenv_getnode("PWD", s_msenv);
	if (aux)
	{
		if (aux->value)
			free(aux->value);
		aux->value = pwd_cp;
		if (aux->key_pair)
			free(aux->key_pair);
		aux->key_pair = ft_strjoin_jm("PWD=", pwd_cp);
	}
	else
	{
		lst_load(ft_strjoin_jm("PWD=", pwd_cp), s_msenv);
		free(pwd_cp);
	}
}

void	oldpwd_update(char *oldpwd, t_env **s_msenv)
{
	t_env	*aux;
	char	*oldpwd_cp;

	if (!s_msenv || !oldpwd)
		return ;
	if (oldpwd[0])
		oldpwd_cp = ft_strdup_jm(oldpwd);
	else
		oldpwd_cp = ft_strdup_jm("");
	aux = msenv_getnode("OLDPWD", s_msenv);
	if (aux)
	{
		if (aux->value)
			free(aux->value);
		aux->value = oldpwd_cp;
		if (aux->key_pair)
			free(aux->key_pair);
		aux->key_pair = ft_strjoin_jm("OLDPWD=", oldpwd_cp);
	}
	else
	{
		lst_load(ft_strjoin_jm("OLDPWD=", oldpwd_cp), s_msenv);
		free(oldpwd_cp);
	}
}

void	msenv_update(char *key, char *value, t_env **s_msenv)
{
	t_env	*aux;

	if (!s_msenv)
		return ;
	aux = msenv_getnode(key, s_msenv);
	if (aux && aux->value)
		free(aux->value);
	aux->value = ft_strdup_jm(value);
	if (aux->key_pair)
		free (aux->key_pair);
	aux->key_pair = ft_strjoin_jm(key, value);
}
