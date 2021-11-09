/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:55:41 by latahbah          #+#    #+#             */
/*   Updated: 2021/11/09 22:39:13 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_conversions(int *res, char format, va_list ap)
{
	if (format == 'c')
		print_char(va_arg(ap, int), res);
	else if (format == 's')
		print_str(va_arg(ap, char *), res);
	else if (format == 'p')
		print_pointer(va_arg(ap, unsigned long), res);
	else if (format == 'd' || format == 'i')
		print_int(va_arg(ap, int), res);
	else if (format == 'u')
		print_int((long)va_arg(ap, unsigned int), res);
	else if (format == 'x')
		ft_putnbr_base((long long)va_arg(ap, unsigned int),
			"0123456789abcdef", res);
	else if (format == 'X')
		ft_putnbr_base((long long)va_arg(ap, unsigned int),
			"0123456789ABCDEF", res);
	else
		print_char(format, res);
}

int	ft_printf(const char *format, ...)
{
	int		res;
	va_list	ap;
	char	f;

	va_start(ap, format);
	res = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			f = *format;
			print_conversions(&res, f, ap);
		}
		else
		{
			write(1, format, 1);
			res++;
		}
		format++;
	}
	va_end(ap);
	return (res);
}
