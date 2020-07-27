/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_and_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:03:03 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/21 13:24:23 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putstr_maxlen(char *str, int maxlen)
{
	write(1, str, maxlen);
	return (maxlen);
}

static int	print_str_with_padding(char *s, t_var t, int maxlen, int padlen)
{
	char p;

	padlen = padlen - maxlen;
	if (padlen < 0)
		padlen = 0;
	p = (t.padding == 0 ? '0' : ' ');
	if (t.padding > NONE && t.align == RIGHT)
		print_padding(padlen, p, &t);
	if (s != NULL)
		ft_putstr_maxlen(s, maxlen);
	else
		ft_putstr_maxlen("(null)", maxlen);
	if (t.padding > NONE && t.align == LEFT)
		print_padding(padlen, p, &t);
	if (t.error == -1)
		return (-1);
	return (0);
}

int			print_string(va_list ap, t_var t)
{
	int		maxlen;
	char	*s;
	int		padlen;

	if (t.count_wild > 0)
		t = parse_wildcard(ap, t);
	if (t.error == -1)
		return (-1);
	if (t.wild_width >= 0)
		padlen = t.wild_width;
	else
		padlen = ft_atoi(t.width);
	s = va_arg(ap, char *);
	if (s != NULL)
		maxlen = ft_strleni(s);
	else
		maxlen = 6;
	if (t.precision > -1 && t.precision < maxlen)
		maxlen = t.precision;
	if (print_str_with_padding(s, t, maxlen, padlen) == -1)
		return (-1);
	if (maxlen > padlen)
		return (maxlen);
	return (padlen);
}

static int	print_char_with_padding(char c, t_var t, int pad_len, char p)
{
	if (t.padding > NONE && t.align == RIGHT)
		print_padding(pad_len - 1, p, &t);
	ft_putchar(c);
	if (t.padding == SPACE && t.align == LEFT)
		print_padding(pad_len - 1, p, &t);
	if (t.error == -1)
		return (-1);
	if (pad_len > 1)
		return (pad_len);
	else
		return (1);
}

int			print_char(const char *str, va_list ap, int i, t_var t)
{
	int		n;
	char	c;
	int		pad_len;
	int		param_len;
	char	p;

	p = (t.padding == 0 ? '0' : ' ');
	param_len = 1;
	if (t.count_wild > 0)
		t = parse_wildcard(ap, t);
	if (t.error == -1)
		return (-1);
	pad_len = 0;
	if (str[i + 1] == 'c')
	{
		n = va_arg(ap, int);
		c = (char)n;
	}
	else
		c = str[i + 1];
	if (t.wild_width > 0)
		pad_len = t.wild_width;
	else
		pad_len = ft_atoi(t.width);
	return (print_char_with_padding(c, t, pad_len, p));
}
