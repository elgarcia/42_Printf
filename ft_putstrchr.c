/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:45:20 by eliagarc          #+#    #+#             */
/*   Updated: 2023/11/29 12:34:44 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (write(fd, &s[i], 1) == -1)
				return (-1);
			i++;
		}
	}
	else
		return (write(fd, "(null)", 6));
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
