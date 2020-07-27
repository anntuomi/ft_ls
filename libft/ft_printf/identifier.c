/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:56:42 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/08 11:36:32 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_var	new_tvar(int i, const char *str)
{
	t_var t;

	t.padding = NONE;
	t.count_wild = 0;
	t.wild_width = NONE;
	t.wild_prec = NONE;
	t.align = RIGHT;
	t.hashtag = NONE;
	t.sign = NONE;
	t.len_h = NONE;
	t.len_l = NONE;
	t.j = i;
	t.width = str;
	t.error = 0;
	t.precision = NONE;
	return (t);
}

t_var	check_precision(const char *str, t_var t)
{
	if (str[t.j + 1] == '.')
	{
		t.precision = ft_atoi(&str[t.j + 2]);
		if (t.precision < 0)
			t.precision = 0;
	}
	return (t);
}

t_var	parse_identifier(const char *str, t_var t, char c)
{
	while (ft_isdigit(c) == 1 || c == '#' || c == '+' || c == ' ' || c == '-' \
			|| c == '.' || c == 'l' || c == 'L' || c == 'h' || c == '*')
	{
		t = check_precision(str, t);
		t = check_flags(str, t);
		t = check_conv_length_h(str, t);
		t = check_conv_length_l(str, t);
		t = check_conv_length_bigl(str, t);
		t = check_wildcard(str, t);
		t.j++;
		c = str[t.j + 1];
	}
	return (t);
}

t_var	check_identifier(const char *str, int i)
{
	t_var	t;
	char	c;

	t = new_tvar(i, &str[i + 1]);
	c = str[t.j + 1];
	if (c == '0')
		t.padding = ZERO;
	if (ft_isdigit(c) == 1 && ft_atollu(&str[t.j + 1]) > 0)
		t.width = &str[t.j + 1];
	t = parse_identifier(str, t, c);
	if ((t.precision != NONE || t.wild_prec > NONE) && t.padding == ZERO && \
			str[t.j + 1] != 's')
		t.padding = SPACE;
	return (t);
}
