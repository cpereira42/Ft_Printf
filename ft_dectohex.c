/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:34:37 by cpereira          #+#    #+#             */
/*   Updated: 2020/03/28 01:51:36 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

static char	*print_str(char *aux)
{
	int		i;
	int		j;
	char	*saida;

	j = 0;
	i = ft_strlen(aux) - 1;
	saida = (char *)malloc((i + 2) * sizeof(char *));
	while (aux[i] == '0' && i != 0)
		i--;
	while (i >= 0)
	{
		saida[j] = aux[i];
		i--;
		j++;
	}
	saida[j] = '\0';
	aux = NULL;
	return (saida);
}

char		*ft_dectohex(unsigned long int numero, char entrada, t_flags fl)
{
	char	*ret;
	int		i;
	char	*base;
	int		tamanho;

	tamanho = fl.type == 'p' ? 12 : 7;
	if (!(ret = (char *)malloc((tamanho + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	if (entrada == 'X')
		base = ft_strdup("0123456789ABCDEF");
	else
		base = ft_strdup("0123456789abcdef");
	while (numero >= 0)
	{
		ret[i] = base[numero % 16];
		numero = numero / 16;
		if (i >= tamanho || numero == 0)
			break ;
		i++;
	}
	ret[i + 1] = '\0';
	return (print_str(ret));
}
