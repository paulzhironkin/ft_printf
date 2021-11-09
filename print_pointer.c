/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:16:10 by latahbah          #+#    #+#             */
/*   Updated: 2021/11/09 22:47:34 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(unsigned long ul, int *res)
{
	print_char('0', res);
	print_char('x', res);
	ft_putnbr_base(ul, "0123456789abcdef", res);
}
