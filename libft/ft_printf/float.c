/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:14:58 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/09 12:39:08 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_float_padlen(t_var t, int param_len)
{
	int pad_len;

	if (t.wild_width > 0)
		pad_len = t.wild_width;
	else
		pad_len = ft_atoi(t.width);
	if (t.sign != NONE)
		param_len = param_len + 1;
	pad_len = pad_len - param_len;
	if (pad_len > 0)
		return (pad_len);
	else
		return (0);
}

int			ft_float(double nb, unsigned long long nb_int, t_var t, int n_len)
{
	double			whole;
	int				ret;
	char			*whole_part;
	char			*dec_part;

	whole = (double)nb_int;
	ret = 0;
	dec_part = ft_putdecimal(nb, whole, t.precision, &ret);
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

static int	print_float_with_padding(double nb, int pad_len, \
		int param_len, t_var t)
{
	char	p;
	int		len;
	char	sign;

	sign = t.sign;
	len = 0;
	p = (t.padding == ZERO ? '0' : ' ');
	if (sign != NONE && t.padding < 1)
		len = len + ft_putchar_len(sign);
	if (t.padding > NONE && t.align == RIGHT)
		len = len + print_padding(pad_len, p, &t);
	if (sign != NONE && t.padding == 1)
		len = len + ft_putchar_len(sign);
	len = len + ft_float(nb, (unsigned long long)nb, t, param_len);
	if (t.padding == SPACE && t.align == LEFT)
		len = len + print_padding(pad_len, p, &t);
	if (t.error == -1)
		len = -1;
	return (len);
}

int			print_float(va_list ap, t_var t)
{
	double	nbr;
	int		pad_len;
	int		param_len;
	int		n_len;

	if (t.count_wild > 0)
		t = parse_wildcard(ap, t);
	if (t.error == -1)
		return (-1);
	if (t.precision == -1)
		t.precision = 6;
	nbr = va_arg(ap, double);
	if (nbr < 0)
	{
		nbr = nbr * -1;
		t.sign = '-';
	}
	n_len = ft_baselen((unsigned long long)nbr, 10);
	param_len = n_len + t.precision;
	if (t.precision != 0 || t.hashtag == YES)
		param_len++;
	pad_len = check_float_padlen(t, param_len);
	return (print_float_with_padding(nbr, pad_len, n_len, t));
}
