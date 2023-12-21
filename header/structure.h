/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:02:34 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/12/13 19:16:05 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_env
{
	char			*key;
	char			*value;
	char			*key_pair;
	int				flag;
	struct s_env	*next;
}					t_env;

typedef struct s_list2
{
	int				index;
	void			*content;
	struct s_list2	*next;
}					t_list2;

typedef struct s_cmd
{
	char	**args;
	char	*fullpath;
	int		is_last;
}	t_cmd;

/**
 * 
*/
typedef struct s_parsing
{
	int		s_quote;
	int		d_quote;
	int		pools_count;
	char	*pools_offset;

}	t_parsing;

/**
 * 
*/
typedef struct s_lexer
{
	int		type;
	char	*content;
	void	*next;
}	t_lexer;

/**
 * 
*/

#endif