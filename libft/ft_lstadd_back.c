/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:38:15 by phialfai          #+#    #+#             */
/*   Updated: 2022/11/29 09:41:03 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastel;

	if (lst)
	{
		if (*lst)
		{
			lastel = ft_lstlast(*lst);
			lastel->next = new;
		}
		else
		{
			*lst = new;
		}
	}
}
