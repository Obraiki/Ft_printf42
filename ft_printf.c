/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obraiki <obraiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:24:15 by obraiki           #+#    #+#             */
/*   Updated: 2021/12/08 10:37:54 by obraiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dis_printf(const char *s, va_list para)
{
	int	i;

	i = 0;
	if (*s == '%')
		i += ft_putchar('%');
	else if (*s == 'i' || *s == 'd')
		i += ft_putnbr(va_arg(para, int));
	else if (*s == 'c')
		i += ft_putchar(va_arg(para, int));
	else if (*s == 's')
		i += ft_putstr(va_arg(para, char *));
	else if (*s == 'x')
		i += ft_conv_hex(va_arg(para, unsigned int), 'x');
	else if (*s == 'X')
		i += ft_conv_hex(va_arg(para, unsigned int), 'X');
	else if (*s == 'u')
		i += ft_unsigned(va_arg(para, unsigned int));
	else if (*s == 'p')
	{
		i += ft_putstr("0x");
		i += ft_conv_hex(va_arg(para, unsigned long), 'p');
	}
	return (i);
}

int	ft_printf(const char *form, ...)
{
	int		i;
	va_list	pr;

	i = 0;
	va_start(pr, form);
	while (*form)
	{
		if (*form == '%')
		{
			form++;
			i += ft_dis_printf(form, pr);
		}
		else
			i += ft_putchar(*form);
		form++;
	}
	va_end(pr);
	return (i);
}
