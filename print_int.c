/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:17:22 by latahbah          #+#    #+#             */
/*   Updated: 2021/11/09 18:03:29 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(long i, int *res)
{
	char	*str;

	str = ft_itoa(i);
	print_str(str, res);
	free(str);
}
