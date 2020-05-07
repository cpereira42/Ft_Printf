/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 23:05:38 by cpereira          #+#    #+#             */
/*   Updated: 2020/03/28 01:35:22 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_str(char *ret)
{
	int	i;

	i = 0;
	while (ret[i] != '\0')
	{
		if (ret[i] != '-')
			write(1, &ret[i], 1);
		i++;
	}
	return (i);
}

static int	print_zero(int tamanho, char letra)
{
	int i;

	i = 0;
	while (i < tamanho)
	{
		write(1, &letra, 1);
		i++;
	}
	return (i);
}

static int	escreve(t_flags fl, int n_negativo, char *ret)
{
	int tamanho;

	tamanho = 0;
	if (fl.neg == 0)
		tamanho = print_zero(fl.width, fl.just);
	write(1, "0x", 2);
	tamanho = print_zero(fl.precision + n_negativo - (int)ft_strlen(ret),
			'0') + tamanho;
	tamanho = print_str(ret) + tamanho;
	if (fl.neg == 1)
		tamanho = print_zero(fl.width, fl.just) + tamanho;
	tamanho = tamanho + 2;
	return (tamanho);
}

int			ft_printf_p(t_flags fl, char *ret)
{
	int tamanho;
	int n_negativo;

	fl.width = fl.width - 2 - ft_strlen(ret);
	n_negativo = ret[0] == '-' && fl.dot == 1 ? 1 : 0;
	if (ret[0] == '0' && fl.dot == 1 && fl.precision == 0 && fl.width != 0)
	{
		fl.width++;
		ret[0] = '\0';
	}
	if (fl.dot == 0 && fl.just == '0')
		fl.precision = fl.width;
	else
		fl.just = ' ';
	tamanho = escreve(fl, n_negativo, ret);
	ret = NULL;
	return (tamanho);
}
