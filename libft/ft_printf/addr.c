/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:14:04 by atuomine          #+#    #+#             */
/*   Updated: 2019/12/21 11:09:35 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*set_addr(unsigned long long c, int *param_len, t_var t)
{
	char *nbr;

	if (t.precision == 0 && c == 0)
	{
		*param_len = 2;
		nbr = NULL;
	}
	else
	{
		*param_len = ft_baselen(c, 16);
		nbr = ft_llutoa_base(c, 'x', 16, *param_len);
		*param_len = *param_len + 2;
	}
	return (nbr);
}

static int	check_addr_padlen(t_var t, int param_len, char type)
{
	int pad_len;
	int p;

	type = ft_tolower(type);
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
	pad_len = pad_len - param_len;
	if (pad_len > 0)
		return (pad_len);
	else
		return (0);
}

static int	print_w_padding(char *nbr, int param_len, char type, t_var t)
{
	char	p;
	int		len;
	int		pad_len;

	pad_len = check_addr_padlen(t, param_len, type);
	len = 0;
	p = (t.padding == ZERO ? '0' : ' ');
	if (t.padding < SPACE)
		len = len + ft_putstr_len("0x");
	if (t.padding > NONE && t.align == RIGHT)
		len = len + print_padding(pad_len, p, &t);
	if (t.padding == SPACE)
		len = len + ft_putstr_len("0x");
	if (t.precision != NONE && !(param_len == 0))
		len = len + ft_print_precision(&t, param_len - 2);
	len = len + ft_putstr_len(nbr);
	if (t.padding == SPACE && t.align == LEFT)
		len = len + print_padding(pad_len, p, &t);
	if (nbr != NULL)
		free(nbr);
	if (t.error == -1)
		len = -1;
	return (len);
}

int			print_addr(const char *str, va_list ap, int i, t_var t)
{
	unsigned long long	n;
	char				*addr;
	int					pad_len;
	int					param_len;

	param_len = 0;
	if (t.count_wild > 0)
		t = parse_wildcard(ap, t);
	if (t.error == -1)
		return (-1);
	pad_len = 0;
	n = va_arg(ap, unsigned long long);
	addr = set_addr(n, &param_len, t);
	if (addr == NULL && param_len != 2)
		return (-1);
	return (print_w_padding(addr, param_len, str[i + 1], t));
}
