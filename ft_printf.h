/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:20:55 by eliagarc          #+#    #+#             */
/*   Updated: 2023/11/29 12:34:36 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEXA_MAY "0123456789ABCDEF"
# define HEXA_MIN "0123456789abcdef"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_putnbru(unsigned int n, int fd);
int		ft_putnbr(int n, int fd);
int		ft_putchar(char c);
int		ft_putstr(const char *s, int fd);
int		ft_putnbrp(unsigned long n, int fd);
int		ft_putnbr_hx(unsigned int n, int fd, int minmax);
int		check_format(char arg, va_list vl);
int		ft_printf(char const *arg, ...);

#endif
