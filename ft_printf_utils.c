/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obraiki <obraiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:05:23 by obraiki           #+#    #+#             */
/*   Updated: 2021/12/08 11:46:55 by obraiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += ft_putstr("-2147483648");
		return (i);
	}
	if (n < 0)
	{
		i += ft_putchar('-');
		n = -1 * n;
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
	i += ft_putchar(n + 48);
	return (i);
}

int	ft_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_unsigned(n / 10);
		i += ft_unsigned(n % 10);
	}
	else
	i += ft_putchar(n + 48);
	return (i);
}

int	ft_conv_hex(unsigned long n, char c)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_conv_hex(n / 16, c);
	if ((n % 16) < 10)
		i += ft_putchar((n % 16) + '0');
	else
	{
		if (c == 'X')
			i += ft_putchar((n % 16) + 55);
		else
			i += ft_putchar((n % 16) + 87);
	}
	return (i);
}
