/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:05:22 by latahbah          #+#    #+#             */
/*   Updated: 2021/11/09 22:46:52 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c, int *res)
{
	write(1, &c, 1);
	(*res)++;
}

static int	check_base2(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		while (base[j] != '\0')
		{
			if (base[i] == base[j] && i != j)
			{
				return (0);
			}
			if (base[j] == '+' || base[j] == '-')
			{
				return (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (i);
}

static int	check_base(char *base)
{
	if (base[1] == '\0')
	{
		return (0);
	}
	return (check_base2(base));
}

static void	convert_int_to_base(unsigned long nbr, char *base,
		int count_base, int *res)
{
	long long	tmp;

	if (nbr < 0)
	{
		convert_int_to_base(nbr *= -1, base, count_base, res);
	}
	else if (nbr < (unsigned long)count_base)
	{
		tmp = nbr % count_base;
		ft_putchar(base[tmp], res);
	}
	else
	{
		convert_int_to_base(nbr / count_base, base, count_base, res);
		tmp = nbr % count_base;
		ft_putchar(base[tmp], res);
	}
}

void	ft_putnbr_base(unsigned long nbr, char *base, int *res)
{
	int			n;

	n = check_base(base);
	if (n)
	{
		convert_int_to_base(nbr, base, n, res);
	}
}
