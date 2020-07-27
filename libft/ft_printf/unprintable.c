/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_and_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:03:03 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/09 12:55:07 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_nonprintlen(char *s, int maxlen)
{
	int i;
	int len;

	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] < 8 || s[i] == 9 || (s[i] >= 16 && s[i] <= 24) || \
				s[i] == 26 || s[i] == 27 || s[i] == 127)
			len = len + 5;
		else if (s[i] < 32)
			len = len + 4;
		else
			len++;
		i++;
	}
	len = len + 5;
	if (len > maxlen && maxlen != -1)
		return (maxlen);
	else
		return (len);
}

static int	print_str_with_padding(char *s, t_var t, int maxlen, int padlen)
{
	char	p;
	int		len;
	int		param_len;

	len = 0;
	param_len = ft_nonprintlen(s, maxlen);
	padlen = padlen - param_len;
	if (padlen < 0)
		padlen = 0;
	p = (t.padding == 0 ? '0' : ' ');
	if (t.padding > NONE && t.align == RIGHT)
		print_padding(padlen, p, &t);
	if (s != NULL)
		len = ft_putstr_nonprint(s, maxlen);
	else
		ft_putstr_maxlen("(null)", maxlen);
	if (t.padding > NONE && t.align == LEFT)
		print_padding(padlen, p, &t);
	if (t.error == -1)
		return (-1);
	return (len + padlen);
}

int			print_unprintable(va_list ap, t_var t)
{
	int		maxlen;
	char	*s;
	int		padlen;
	int		len;

	len = 0;
	if (t.count_wild > 0)
		t = parse_wildcard(ap, t);
	if (t.error == -1)
		return (-1);
	if (t.wild_width >= 0)
		padlen = t.wild_width;
	else
		padlen = ft_atoi(t.width);
	s = va_arg(ap, char *);
	maxlen = t.precision;
	if ((len = print_str_with_padding(s, t, maxlen, padlen)) == -1)
		return (-1);
	if (len > padlen)
		return (len);
	return (padlen);
}
