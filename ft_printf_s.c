/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 23:05:38 by cpereira          #+#    #+#             */
/*   Updated: 2020/03/28 01:22:43 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_just(t_flags fl)
{
	int tamanho;

	tamanho = 0;
	while (fl.width > fl.precision)
	{
		write(1, &fl.just, 1);
		fl.width--;
		tamanho++;
	}
	return (tamanho);
}

int	ft_printf_s(t_flags fl, char *ret)
{
	int tamanho;

	if (ret == NULL)
		ret = "(null)";
	if (fl.dot == 1)
	{
		if (fl.precision > (int)ft_strlen(ret))
			fl.precision = (int)ft_strlen(ret);
	}
	else
		fl.precision = (int)ft_strlen(ret);
	if (fl.neg == 1)
	{
		tamanho = ft_putstr(ret, fl);
		tamanho = print_just(fl) + tamanho;
	}
	else
	{
		tamanho = print_just(fl);
		tamanho = ft_putstr(ret, fl) + tamanho;
	}
	return (tamanho);
}
