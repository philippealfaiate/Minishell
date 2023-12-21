/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 02:52:25 by jmoraes-          #+#    #+#             */
/*   Updated: 2023/11/09 11:38:14 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

void	ft_put_hex(unsigned int num, const char format);
void	ft_put_ptr(uintptr_t nb);
int		ft_len(int n);
int		hex_len(unsigned int num);
int		len_ptr(uintptr_t nb);
int		ft_unsigned_len(unsigned int nb);
int		ft_putchar2(char c);
int		ft_putstr2(char *str);
int		ft_putnbr(int n);
int		ft_puthex(unsigned int num, const char format);
int		ft_putptr(uintptr_t ptr);
int		ft_putunsigned(unsigned int nb);
int		ft_conversion(va_list vl, const char format);
int		ft_printf(const char *format, ...);
char	*ft_char(char *s, unsigned int number, int len);
char	*ft_iitoa(int n);
char	*ft_uitoa(unsigned int nb);

#endif
