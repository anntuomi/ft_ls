/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:39:50 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/09 12:39:53 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_lfloat(long double nb, unsigned long long nb_int, t_var t, \
		int n_len)
{
	long double	whole;
	int			ret;
	char		*whole_part;
	char		*dec_part;

	whole = (long double)nb_int;
	ret = 0;
	dec_part = ft_putdecimal_l(nb, whole, t.precision, &ret);
	if (ret != 0)
		nb_int++;
	ret = 0;
	whole_part = ft_llutoa(nb_int, n_len);
	if (whole_part == NULL || dec_part == NULL)
		return (-1);
	ret = ft_putstr_len(whole_part);
	if (t.precision > 0 || t.hashtag == YES)
	{
		ret = ret + ft_putchar_len('.');
		if (!(t.hashtag == YES && t.precision == 0))
			ret = ret + ft_putstr_len(dec_part);
	}
	free(dec_part);
	free(whole_part);
	return (ret);
}

static int	print_lfloat_with_padding(long double nb, int pad_len, \
		int param_len, t_var t)
{
	char	p;
	int		len;
	char	sign;

	sign = t.sign;
	len = 0;
	p = (t.padding == ZERO ? '0' : ' ');
	if (sign != NONE && t.padding < SPACE)
		len = len + ft_putchar_len(sign);
	if (t.padding > NONE && t.align == RIGHT)
		len = len + print_padding(pad_len, p, &t);
	if (sign != NONE && t.padding == SPACE)
		len = len + ft_putchar_len(sign);
	len = len + ft_lfloat(nb, (unsigned long long)nb, t, param_len);
	if (t.padding == SPACE && t.align == LEFT)
		len = len + print_padding(pad_len, p, &t);
	if (t.error == -1)
		len = -1;
	return (len);
}

int			print_lfloat(va_list ap, t_var t)
{
	long double	nbr;
	int			pad_len;
	int			param_len;
	int			n_len;

	if (t.count_wild > 0)
		t = parse_wildcard(ap, t);
	if (t.error == -1)
		return (-1);
	if (t.precision == NONE)
		t.precision = 6;
	nbr = va_arg(ap, long double);
	if (nbr < 0)
	{
		nbr = nbr * -1;
		t.sign = '-';
	}
	n_len = ft_baselen((unsigned long long int)nbr, 10);
	param_len = n_len + t.precision;
	if (t.precision != 0 || t.hashtag == YES)
		param_len++;
	pad_len = check_float_padlen(t, param_len);
	return (print_lfloat_with_padding(nbr, pad_len, n_len, t));
}
