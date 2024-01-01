/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:29:11 by eliagarc          #+#    #+#             */
/*   Updated: 2023/09/21 16:29:13 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	rec_nbr(int nbr, int fd, int *res)
{
	char	aux;

	if (nbr / 10 != 0)
	{
		aux = (nbr % 10) + 48;
		if (rec_nbr(nbr / 10, fd, res) == -1)
			return (-1);
		*res += 1;
	}
	else
	{
		aux = nbr + 48;
		*res += 1;
	}
	if (fd != 0)
		if (write(fd, &aux, 1) == -1)
			return (-1);
	return (*res);
}

int	ft_putnbr(int n, int fd)
{
	int	res;

	res = 0;
	if (n == -2147483648 && fd != 0)
	{
		if (write(fd, "-2", 2) == -1)
			return (-1);
		res += 2;
		n = 147483648;
	}
	if (n < 0 && fd != 0)
	{
		n = n * (-1);
		if (write(fd, "-", 1) == -1)
			return (-1);
		res += 1;
	}
	if (fd != 0)
		if (rec_nbr(n, fd, &res) == -1)
			return (-1);
	return (res);
}

static int	rec_nbru(unsigned int nbr, int fd, int *res)
{
	unsigned int	aux;

	if (nbr / 10 != 0)
	{
		aux = (nbr % 10) + 48;
		if (rec_nbru(nbr / 10, fd, res) == -1)
			return (-1);
		*res += 1;
	}
	else
	{
		aux = nbr + 48;
		*res += 1;
	}
	if (fd != 0)
	{
		if (write(fd, &aux, 1) == -1)
			return (-1);
	}
	return (*res);
}

int	ft_putnbru(unsigned int n, int fd)
{
	int	res;

	res = 0;
	if (fd > 0)
	{
		res = rec_nbru(n, fd, &res);
		if (res == -1)
			return (-1);
	}
	else
		return (-1);
	return (res);
}
