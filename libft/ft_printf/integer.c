/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:08:50 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/08 11:52:52 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*set_nbr(long long c, int *param_len, char *sign, t_var t)
{
	char *nbr;

	if (t.precision == 0 && c == 0)
	{
		*param_len = 0;
		nbr = NULL;
	}
	else
	{
		*param_len = ft_nbrlen(c);
		if (c < 0)
		{
			if (c == -9223372036854775807 - 1)
			{
				nbr = ft_strsub("9223372036854775808", 0, 19);
				*param_len = 20;
			}
			else
				nbr = ft_llutoa(c * -1, *param_len - 1);
			*sign = '-';
		}
		else
			nbr = ft_llutoa(c, *param_len);
	}
	return (nbr);
}

static int	check_signed_padlen(t_var t, int param_len, char *sign)
{
	int pad_len;
	int p;

	if (t.precision > -1)
	{
		if (*sign == '-')
			p = t.precision - (param_len - 1);
		else
			p = t.precision - param_len;
		if (p < 0)
			p = 0;
		param_len = param_len + p;
	}
	if (t.wild_width > 0)
		pad_len = t.wild_width;
	else
		pad_len = ft_atoi(t.width);
	if (t.sign != NONE && *sign != '-')
	{
		*sign = t.sign;
		param_len = param_len + 1;
	}
	pad_len = pad_len - param_len;
	return (pad_len > 0 ? pad_len : 0);
}

static int	print_signed_with_padding(char *nbr, int pad_len, \
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
	if (sign != NONE && t.padding == 1)
		len = len + ft_putchar_len(sign);
	if (sign == '-')
		len = len + ft_print_precision(&t, param_len - 1);
	else
		len = len + ft_print_precision(&t, param_len);
	len = len + ft_putstr_len(nbr);
	if (t.padding == SPACE && t.align == LEFT)
		len = len + print_padding(pad_len, p, &t);
	if (nbr != NULL)
		free(nbr);
	return (len);
}

int			print_int(const char *str, va_list ap, int i, t_var t)
{
	long long int	n;
	char			*nbr;
	int				pad_len;
	int				param_len;
	char			sign;

	param_len = 0;
	if (t.count_wild > 0)
		t = parse_wildcard(ap, t);
	if (t.error == -1)
		return (-1);
	pad_len = 0;
	sign = 0;
	n = convert_int(t, ap, str[i + 1]);
	nbr = set_nbr(n, &param_len, &sign, t);
	if (nbr == NULL && param_len != 0)
		return (-1);
	if (sign == '-')
		t.sign = '-';
	pad_len = check_signed_padlen(t, param_len, &sign);
	return (print_signed_with_padding(nbr, pad_len, param_len, t));
}
