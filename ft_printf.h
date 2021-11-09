/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:40:45 by latahbah          #+#    #+#             */
/*   Updated: 2021/11/09 13:58:03 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_itoa(long n);
int		ft_printf(const char *format, ...);
void	print_char(int i, int	*res);
void	print_pointer(unsigned long ul, int *res);
void	print_int(long i, int *res);
void	print_str(char *str, int *res);
void	ft_putnbr_base(unsigned long nbr, char *base, int *res);

#endif