/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obraiki <obraiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:24:34 by obraiki           #+#    #+#             */
/*   Updated: 2021/12/08 11:46:28 by obraiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<stdarg.h>

int		ft_dis_printf(const char *s, va_list para);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_unsigned(unsigned int n);
int		ft_conv_hex(unsigned long n, char c);
int		ft_printf(const char *form, ...);

#endif