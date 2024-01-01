/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:40:03 by eliagarc          #+#    #+#             */
/*   Updated: 2023/09/22 16:40:07 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	rec_nbrhx(unsigned int nbr, int fd, int *res, int ca)
{
	int	aux;

	if (nbr / 16 != 0)
	{
		aux = (nbr % 16);
		if (rec_nbrhx(nbr / 16, fd, res, ca) == -1)
			return (-1);
	}
	else
		aux = nbr;
	if (fd != 0)
	{
		*res += 1;
		if (ca == 1)
		{
			if (write(fd, &HEXA_MIN[aux], 1) == -1)
				return (-1);
		}
		else
			if (write(fd, &HEXA_MAY[aux], 1) == -1)
				return (-1);
	}
	return (*res);
}

int	ft_putnbr_hx(unsigned int n, int fd, int minmax)
{
	int	res;

	res = 0;
	if (fd > 0)
	{
		res = rec_nbrhx(n, fd, &res, minmax);
		if (res == -1)
			return (-1);
	}
	else
		return (-1);
	return (res);
}
