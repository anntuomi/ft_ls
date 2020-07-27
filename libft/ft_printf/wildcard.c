/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:54:12 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/08 12:00:55 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	ft_abs(long long int n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}

static int		save_arguments(va_list ap, int *first, int *second, t_var t)
{
	int *star_args;
	int i;

	i = 0;
	star_args = (int *)malloc(sizeof(int) * (t.count_wild + 1));
	if (star_args == NULL)
		return (-1);
	while (i < t.count_wild)
	{
		star_args[i] = va_arg(ap, int);
		i++;
	}
	*second = star_args[i - 1];
	*first = star_args[i - 2];
	free(star_args);
	return (0);
}

static t_var	precision_first(t_var t, int first, int second)
{
	if (t.wild_width > 0)
	{
		t.wild_width = second;
		if (t.wild_width < 0)
		{
			t.wild_width = ft_abs(t.wild_width);
			t.align = LEFT;
		}
	}
	if (t.wild_prec > 0)
	{
		t.wild_prec = first;
		if (t.wild_prec < 0)
			t.wild_prec = -1;
	}
	return (t);
}

static t_var	width_first(t_var t, int first, int second)
{
	if (t.wild_width > 0)
	{
		t.wild_width = first;
		if (t.wild_width < 0)
		{
			t.wild_width = ft_abs(t.wild_width);
			t.align = LEFT;
		}
	}
	if (t.wild_prec > 0)
	{
		t.wild_prec = second;
		if (t.wild_prec < 0)
			t.wild_prec = -1;
	}
	return (t);
}

t_var			parse_wildcard(va_list ap, t_var t)
{
	int second;
	int first;

	if (save_arguments(ap, &first, &second, t) == -1)
	{
		t.error = -1;
		return (t);
	}
	if (t.wild_width > t.wild_prec)
		t = precision_first(t, first, second);
	else
		t = width_first(t, first, second);
	if (t.wild_prec > 0 || t.wild_prec == -1)
		t.precision = t.wild_prec;
	return (t);
}
