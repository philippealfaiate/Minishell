/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:15:38 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/11/24 13:36:28 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static int	get_name_end(char *name)
{
	int	name_end;

	name_end = 0;
	while (name[name_end] && !ft_isnamelimiter(name[name_end]))
	{
		if (name[name_end] == '\'')
		{
			ft_memfw(&name[name_end]);
			while (name[name_end] && name[name_end] != '\'')
				name_end++;
			ft_memfw(&name[name_end]);
		}
		else if (name[name_end] == '"')
		{
			ft_memfw(&name[name_end]);
			while (name[name_end] && name[name_end] != '"')
				name_end++;
			ft_memfw(&name[name_end]);
		}
		else if (name[name_end] && !ft_isnamelimiter(name[name_end]))
			name_end++;
	}
	return (name_end);
}

char	*get_label_name(char *redirect_str)
{
	int		name_start;
	int		name_end;
	char	*name;
	char	*remaining_cmd;

	name_start = 0;
	ft_memfw(redirect_str);
	if (redirect_str[name_start] == '>')
		ft_memfw(&redirect_str[name_start]);
	while (redirect_str[name_start] == ' ' || redirect_str[name_start] == '\t')
		name_start++;
	name_end = get_name_end(&redirect_str[name_start]);
	name = ft_substr(&redirect_str[name_start], 0, name_end);
	remaining_cmd = &redirect_str[name_start + name_end];
	ft_memmove(redirect_str, remaining_cmd, ft_strlen(remaining_cmd) + 2);
	return (name);
}
