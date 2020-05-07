/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 12:39:04 by cpereira          #+#    #+#             */
/*   Updated: 2020/03/28 13:14:14 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_letra(char letra, int tamanho)
{
	write(1, &letra, 1);
	return (1 + tamanho);
}

int		ft_putstr(char *frase, t_flags fl)
{
	int i;
	int tamanho;

	i = 0;
	if (!fl.dot)
		tamanho = ft_strlen(frase);
	else
		tamanho = fl.precision;
	while (frase[i] != '\0' && i < tamanho)
	{
		write(1, &frase[i], 1);
		i++;
	}
	return (i);
}

int		loc_tipo(char *termos, char letra)
{
	int i;

	i = 0;
	while (termos[i] != '\0')
	{
		if (termos[i] == letra)
			return (1);
		i++;
	}
	return (0);
}

t_flags	loc_wid_prec(char *flags, t_flags fl)
{
	int i;

	i = 0;
	while (loc_tipo("-+#0", flags[i]))
		i++;
	i--;
	while (flags[++i] >= '0' && flags[i] <= '9')
		fl.width = fl.width * 10 + flags[i] - 48;
	while (flags[i] != '.' && flags[i] != '\0')
		i++;
	while (flags[++i] >= '0' && flags[i] <= '9')
		fl.precision = fl.precision * 10 + flags[i] - 48;
	fl.type = flags[ft_strlen(flags) - 1];
	return (fl);
}
