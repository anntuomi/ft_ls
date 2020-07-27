/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:59:14 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/08 11:37:41 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_var	check_flags(const char *str, t_var t)
{
	if (str[t.j + 1] == '-')
	{
		t.align = LEFT;
		if (ft_isdigit(str[t.j + 2]) == 1 && ft_atollu(&str[t.j + 2]) > 0)
			t.width = &str[t.j + 2];
	}
	else if (str[t.j + 1] == '#')
	{
		t.hashtag = YES;
		if (ft_isdigit(str[t.j + 2]) == 1 && ft_atollu(&str[t.j + 2]) > 0)
			t.width = &str[t.j + 2];
		if (str[t.j + 2] == '0')
			t.padding = ZERO;
	}
	else if (str[t.j + 1] == '+' || str[t.j + 1] == ' ')
	{
		if (t.sign != '+')
			t.sign = str[t.j + 1];
		if (ft_isdigit(str[t.j + 2]) == 1 && ft_atollu(&str[t.j + 2]) > 0)
			t.width = &str[t.j + 2];
		if (str[t.j + 2] == '0')
			t.padding = ZERO;
	}
	return (t);
}

t_var	check_conv_length_h(const char *str, t_var t)
{
	if (str[t.j + 1] == 'h')
	{
		if (str[t.j + 2] == 'h')
		{
			t.len_h = CHAR;
			if (ft_isdigit(str[t.j + 3]) == 1 && ft_atollu(&str[t.j + 3]) > 0)
				t.width = &str[t.j + 3];
			if (str[t.j + 3] == '0')
				t.padding = ZERO;
			t.j++;
		}
		else
		{
			t.len_h = SHORT;
			if (ft_isdigit(str[t.j + 2]) == 1 && ft_atollu(&str[t.j + 2]) > 0)
				t.width = &str[t.j + 2];
			if (str[t.j + 2] == '0')
				t.padding = ZERO;
		}
	}
	return (t);
}

t_var	check_conv_length_l(const char *str, t_var t)
{
	if (str[t.j + 1] == 'l')
	{
		if (str[t.j + 2] == 'l')
		{
			t.len_l = LL;
			if (ft_isdigit(str[t.j + 3]) == 1 && ft_atollu(&str[t.j + 3]) > 0)
				t.width = &str[t.j + 3];
			if (str[t.j + 3] == '0')
				t.padding = 0;
			t.j++;
		}
		else
		{
			t.len_l = LONG;
			if (ft_isdigit(str[t.j + 2]) == 1 && ft_atollu(&str[t.j + 2]) > 0)
				t.width = &str[t.j + 2];
			if (str[t.j + 2] == '0')
				t.padding = ZERO;
		}
	}
	return (t);
}

t_var	check_conv_length_bigl(const char *str, t_var t)
{
	if (str[t.j + 1] == 'L')
	{
		t.len_l = FL;
		if (ft_isdigit(str[t.j + 2]) == 1 && ft_atollu(&str[t.j + 2]) > 0)
			t.width = &str[t.j + 2];
		if (str[t.j + 2] == '0')
			t.padding = ZERO;
	}
	return (t);
}

t_var	check_wildcard(const char *str, t_var t)
{
	if (str[t.j + 1] == '*')
	{
		t.count_wild = t.count_wild + 1;
		if (str[t.j] == '.')
			t.wild_prec = t.j + 1;
		else
			t.wild_width = t.j + 1;
		if (str[t.j + 2] == 0 && t.wild_prec == -1)
			t.padding = ZERO;
	}
	if ((ft_isdigit(str[t.j + 1]) == 1 || str[t.j + 1] == '*') && \
			(t.padding == -1 || t.align == LEFT))
		t.padding = SPACE;
	if (str[t.j + 1] == '*' && str[t.j + 2] == '0' && t.align != LEFT)
		t.padding = ZERO;
	return (t);
}
