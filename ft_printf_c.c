/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 23:05:38 by cpereira          #+#    #+#             */
/*   Updated: 2020/03/28 01:45:19 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_just(t_flags fl)
{
	int tamanho;

	tamanho = 0;
	while (fl.width - 1 > fl.precision)
	{
		write(1, " ", 1);
		fl.width--;
		tamanho++;
	}
	return (tamanho);
}

int			ft_printf_ch(t_flags fl, char letra)
{
	int tamanho;

	if (fl.neg == 1)
	{
		write(1, &letra, 1);
		tamanho = 1;
		tamanho = print_just(fl) + tamanho;
	}
	else
	{
		tamanho = print_just(fl);
		write(1, &letra, 1);
		tamanho = tamanho + 1;
	}
	return (tamanho);
}
