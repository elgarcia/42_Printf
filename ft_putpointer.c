/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:27:39 by eliagarc          #+#    #+#             */
/*   Updated: 2023/09/22 15:27:43 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	rec_nbrp(unsigned long nbr, int fd, int *res)
{
	unsigned long	aux;

	if (nbr / 16 != 0)
	{
		aux = (nbr % 16);
		if (rec_nbrp(nbr / 16, fd, res) == -1)
			return (-1);
		*res += 1;
	}
	else
	{
		aux = nbr;
		*res += 1;
	}
	if (fd != 0)
	{
		if (write(fd, &HEXA_MIN[aux], 1) == -1)
			return (-1);
	}
	return (*res);
}

int	ft_putnbrp(unsigned long n, int fd)
{
	int	res;

	res = 0;
	if (fd > 0 && n >= 0)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		res = 2;
		res = rec_nbrp(n, fd, &res);
		if (res == -1)
			return (-1);
	}
	else
		return (-1);
	return (res);
}
