/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:05:40 by phialfai          #+#    #+#             */
/*   Updated: 2022/11/15 18:26:29 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Applique la fonction ’f’ à chaque caractère de la chaîne de caractères
 * transmise comme argument, et en passant son index comme premier argument.
 * Chaque caractère est transmis par adresse à ’f’ afin d’être modifié
 * si nécessaire.
 * 
 * @param s	La chaîne de caractères sur laquelle itérer.
 * @param f	La fonction à appliquer à chaque caractère.
 * 
 * @return	void
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}
