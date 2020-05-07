/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:10:30 by cpereira          #+#    #+#             */
/*   Updated: 2020/03/28 13:17:55 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_t_flags
{
	int		just;
	int		pads;
	int		width;
	int		precision;
	int		dot;
	char	type;
	int		min;
	int		neg;
}				t_flags;

# define FLAGS		"-0.*0123456789"
# define CONVERSIONS	"cspdiuxX%"
# define ALL_FLAGS	"-0.*0123456789cspdiuxX%"

int				ft_strlen(const char *frase);
int				ft_printf(const char *format, ...);
char			*ft_dectohex(unsigned long int numero,
		char entrada, t_flags fl);
int				ft_putstr(char *ret, t_flags fl);
int				ft_printf_s(t_flags fl, char *ret);
int				ft_printf_i(t_flags fl, char *ret);
int				ft_printf_x(t_flags fl, char *ret);
int				ft_printf_p(t_flags fl, char *ret);
int				ft_printf_ch(t_flags flag, char c);
char			*ft_strdup(const char *s1);
char			*ft_itoa(int n);
char			*ft_uitoa(unsigned int n);
int				print_letra(char letra, int tamanho);
int				ft_putstr(char *frase, t_flags fl);
int				loc_tipo(char *termos, char letra);
t_flags			loc_wid_prec(char *flags, t_flags fl);
#endif
