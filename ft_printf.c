/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 12:36:37 by cpereira          #+#    #+#             */
/*   Updated: 2020/03/28 13:11:06 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

t_flags	loc_coringa(char *flags, va_list args, t_flags fl, int i)
{
	int entrada;

	while (flags[++i] != '\0')
	{
		if (flags[i] == '*')
		{
			entrada = va_arg(args, int);
			if (flags[i - 1] == '.')
			{
				if (entrada >= 0)
					fl.precision = entrada;
				else
					fl.dot = 0;
			}
			else
			{
				fl.width = entrada < 0 ? entrada * -1 : entrada;
				fl.neg = entrada < 0 ? 1 : fl.neg;
				fl.just = entrada < 0 ? ' ' : fl.just;
			}
		}
	}
	return (fl);
}

t_flags	trata_flags(char *flags, va_list args)
{
	int		i;
	t_flags	fl;

	i = 0;
	fl.dot = loc_tipo(flags, '.');
	fl.precision = 0;
	fl.neg = loc_tipo(flags, '-') == 1 ? 1 : 0;
	fl.width = 0;
	fl.just = ' ';
	while (flags[i] == '0' && flags[i] != '\0')
	{
		if ((flags[i - 1] >= '1' && flags[i - 1] <= '9') || flags[i - 1] == '.')
			fl.just = ' ';
		else
			fl.just = '0';
		i++;
	}
	fl = loc_wid_prec(flags, fl);
	return (loc_coringa(flags, args, fl, -1));
}

int		trata_tipo(char *tipo, va_list args)
{
	int		tamanho;
	int		i;
	t_flags fl;

	i = 0;
	fl = trata_flags(tipo, args);
	if (fl.type == 'c')
		tamanho = ft_printf_ch(fl, va_arg(args, int));
	if (fl.type == 'p')
		tamanho = ft_printf_p(fl, ft_dectohex(va_arg(args, unsigned long int),
	'x', fl));
	if (fl.type == 's')
		tamanho = ft_printf_s(fl, va_arg(args, char *));
	if (fl.type == '%')
		tamanho = ft_printf_s(fl, "%");
	if (fl.type == 'd' || fl.type == 'i')
		tamanho = ft_printf_i(fl, ft_itoa(va_arg(args, int)));
	if (fl.type == 'u')
		tamanho = ft_printf_i(fl, ft_uitoa(va_arg(args, int)));
	if (fl.type == 'x' || fl.type == 'X')
		tamanho = ft_printf_i(fl, ft_dectohex(va_arg(args,
	unsigned long int), fl.type, fl));
	return (tamanho);
}

int		gera_flags(const char *format, int *i, int tamanho, va_list args)
{
	int		j;
	char	tipo[5555];

	j = 0;
	if (format[*i] != '%')
	{
		while (loc_tipo(ALL_FLAGS, format[*i]))
		{
			if (loc_tipo(CONVERSIONS, format[*i]))
			{
				tipo[j++] = format[*i];
				break ;
			}
			tipo[j++] = format[*i];
			*i = *i + 1;
		}
		tipo[j] = '\0';
		if (loc_tipo(CONVERSIONS, tipo[j - 1]))
			tamanho = trata_tipo(tipo, args) + tamanho;
		else
			return (-1);
	}
	else
		tamanho = print_letra('%', tamanho);
	return (tamanho);
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	int		i;
	int		tamanho;

	tamanho = 0;
	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			tamanho = print_letra(format[i++], tamanho);
		else
		{
			i++;
			tamanho = gera_flags(format, &i, tamanho, args);
			if (tamanho == -1)
				return (0);
			i++;
		}
	}
	va_end(args);
	return (tamanho);
}
