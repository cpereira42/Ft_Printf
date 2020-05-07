/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 23:05:38 by cpereira          #+#    #+#             */
/*   Updated: 2020/03/28 01:44:00 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_str(char *ret)
{
	int i;

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

static int	escreve(t_flags fl, int t_ret, int n_negativo, char *ret)
{
	int tamanho;

	tamanho = 0;
	if (fl.neg == 0)
		tamanho = print_zero(fl.width - t_ret, fl.just);
	if (ret[0] == '-')
		tamanho = print_zero(1, '-') - 1 + tamanho;
	tamanho = print_zero(fl.precision + n_negativo - ft_strlen(ret), '0')
		+ tamanho;
	tamanho = print_str(ret) + tamanho;
	if (fl.neg == 1)
		tamanho = print_zero(fl.width - t_ret, fl.just) + tamanho;
	return (tamanho);
}

int			ft_printf_i(t_flags fl, char *ret)
{
	int tamanho;
	int t_ret;
	int n_negativo;

	n_negativo = ret[0] == '-' && fl.dot == 1 ? 1 : 0;
	if (ret[0] == '0' && fl.dot == 1 && fl.precision == 0 && fl.width != 0)
		ret[0] = ' ';
	if (ret[0] == '0' && fl.dot == 1 && fl.precision < 1)
	{
		if (fl.width >= 1)
			ret[0] = ' ';
		else
			return (0);
	}
	if (fl.dot == 0 && fl.just == '0')
		fl.precision = fl.width;
	else
		fl.just = ' ';
	t_ret = fl.precision < ft_strlen(ret) ? ft_strlen(ret) : fl.precision;
	if (fl.width > 0 && fl.precision > 0 && ret[0] == '-' &&
		fl.precision >= ft_strlen(ret))
		t_ret++;
	tamanho = escreve(fl, t_ret, n_negativo, ret);
	return (tamanho);
}
