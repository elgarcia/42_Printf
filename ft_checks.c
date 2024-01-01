/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:51:19 by eliagarc          #+#    #+#             */
/*   Updated: 2023/11/29 15:37:30 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	typ_check2(const char var, va_list vl)
{
	if (var == 'p')
		return (ft_putnbrp((unsigned long)va_arg(vl, void *), 1));
	else if (var == 'x')
		return (ft_putnbr_hx(va_arg(vl, unsigned int), 1, 1));
	else if (var == 'X')
		return (ft_putnbr_hx(va_arg(vl, unsigned int), 1, 2));
	else if (var == '%')
		return (ft_putchar('%'));
	return (0);
}

static int	typ_check(const char var, va_list vl)
{
	if (var == 'c')
		return (ft_putchar((char)va_arg(vl, int)));
	else if (var == 's')
		return (ft_putstr(va_arg(vl, char *), 1));
	else if (var == 'i' || var == 'd')
		return (ft_putnbr(va_arg(vl, int), 1));
	else if (var == 'u')
		return (ft_putnbru(va_arg(vl, unsigned int), 1));
	return (0);
}

int	check_format(char arg, va_list vl)
{
	int	aux;

	aux = typ_check(arg, vl);
	if (aux == -1)
		return (-1);
	if (!aux)
	{
		return (typ_check2(arg, vl));
	}
	return (aux);
}
