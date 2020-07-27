/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:10:10 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/09 12:42:29 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*set_nbr_b(unsigned long long c, int *param_len, t_var t, char type)
{
	char	*nbr;
	int		base;

	if (type == 'x' || type == 'X')
		base = 16;
	else if (type == 'o' || type == 'O')
		base = 8;
	else if (type == 'b' || type == 'B')
		base = 2;
	else
		base = 10;
	if (t.precision == 0 && c == 0)
	{
		*param_len = 0;
		nbr = NULL;
	}
	else
	{
		*param_len = ft_baselen(c, base);
		nbr = ft_llutoa_base(c, type, base, *param_len);
	}
	return (nbr);
}

static int	check_unsigned_padlen(t_var t, int param_len, char type, char *nbr)
{
	int pad_len;
	int p;
	int orig_plen;

	type = ft_tolower(type);
	orig_plen = param_len;
	if (t.precision > -1)
	{
		p = t.precision - param_len;
		if (p < 0)
			p = 0;
		param_len = param_len + p;
	}
	if (t.wild_width > 0)
		pad_len = t.wild_width;
	else
		pad_len = ft_atoi(t.width);
	if (t.hashtag == YES)
	{
		if ((type == 'x' || type == 'b') && orig_plen != 0)
			param_len = param_len + 2;
		else if (type == 'o' && ft_atollu(nbr) != 0)
			param_len = param_len + 1;
	}
	return (pad_len - param_len > 0 ? pad_len - param_len : 0);
}

static int	print_base_precision(char *nbr, t_var t, char type, int param_len)
{
	int len;

	len = 0;
	if (!(ft_tolower(type) == 'x' && param_len == 0) && \
			!(ft_tolower(type) == 'b' && param_len == 0))
	{
		if (ft_tolower(type) == 'o' && ft_atollu(nbr) > 0 && t.hashtag == YES)
			len = len + ft_print_precision(&t, param_len + 1);
		else
			len = len + ft_print_precision(&t, param_len);
	}
	return (len);
}

static int	print_w_padding(char *nbr, int param_len, char type, t_var t)
{
	char	p;
	int		len;
	int		pad_len;

	pad_len = check_unsigned_padlen(t, param_len, type, nbr);
	len = 0;
	if (t.hashtag == YES)
		len = prefix_len(nbr, type, t);
	p = (t.padding == ZERO ? '0' : ' ');
	if (t.padding < SPACE && t.hashtag == YES)
		put_prefix(type, t, len, nbr);
	if (t.padding > NONE && t.align == RIGHT)
		len = len + print_padding(pad_len, p, &t);
	if (t.padding == SPACE && t.hashtag == YES)
		put_prefix(type, t, len, nbr);
	len = len + print_base_precision(nbr, t, type, param_len);
	len = len + ft_putstr_len(nbr);
	if (t.padding == SPACE && t.align == LEFT)
		len = len + print_padding(pad_len, p, &t);
	if (nbr != NULL)
		free(nbr);
	if (t.error == -1)
		len = -1;
	return (len);
}

int			print_base(const char *str, va_list ap, int i, t_var t)
{
	unsigned long long int	n;
	char					*nbr;
	int						param_len;

	param_len = 0;
	if (t.count_wild > 0)
		t = parse_wildcard(ap, t);
	if (t.error == -1)
		return (-1);
	n = convert_base(t, ap, str[i + 1]);
	if (n == 0 && (ft_tolower(str[i + 1]) == 'x' || \
				ft_tolower(str[i + 1]) == 'b') && t.hashtag == YES)
		t.hashtag = NONE;
	nbr = set_nbr_b(n, &param_len, t, str[i + 1]);
	if (nbr == NULL && param_len != 0)
		return (-1);
	return (print_w_padding(nbr, param_len, str[i + 1], t));
}
