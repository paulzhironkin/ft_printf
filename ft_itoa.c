/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:30:05 by latahbah          #+#    #+#             */
/*   Updated: 2021/11/09 18:11:45 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*fill_str(char *str, int size, int pol, long n)
{
	str[size - 1] = '\0';
	size--;
	while (size--)
	{
		if (size == 0 && pol == 1)
		{
			str[size] = '-';
		}
		else
		{	
			str[size] = n % 10 + '0';
			n /= 10;
		}
	}
	return (str);
}

static void	check_pol(long *n, int *size, int *pol)
{
	long		nn;

	if (*n < 0)
	{
		*pol = 1;
		*n *= -1;
		*size = *size + 1;
	}
	else
		*pol = 0;
	nn = *n;
	while (nn > 0)
	{
		*size = *size + 1;
		nn /= 10;
	}
}

char	*ft_itoa(long n)
{
	char	*str;
	int		size;
	int		pol;

	size = 1;
	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	check_pol(&n, &size, &pol);
	str = (char *)malloc(sizeof(char) * (size));
	if (str == NULL)
		return (NULL);
	return (fill_str(str, size, pol, n));
}
