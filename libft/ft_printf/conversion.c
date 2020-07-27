/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:45:06 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/08 10:48:13 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int		convert_int(t_var t, va_list ap, char type)
{
	long long int	c;
	int				a;

	c = 0;
	a = 0;
	if (t.len_l == NONE && t.len_h == NONE && type != 'D')
		c = va_arg(ap, int);
	else if (t.len_l == LL || type == 'D')
		c = va_arg(ap, long long);
	else if (t.len_l == LONG)
		c = va_arg(ap, long);
	else if (t.len_l == NONE)
	{
		if (t.len_h == CHAR)
		{
			a = va_arg(ap, int);
			c = (char)a;
		}
		else if (t.len_h == SHORT)
		{
			a = va_arg(ap, int);
			c = (short)a;
		}
	}
	return (c);
}

unsigned long long	convert_base(t_var t, va_list ap, char type)
{
	unsigned long long	nbr;
	unsigned int		a;

	nbr = 0;
	a = 0;
	if (t.len_l == NONE && t.len_h == NONE && type != 'O' && type != 'U')
		nbr = va_arg(ap, unsigned int);
	else if (t.len_l == LL || type == 'O' || type == 'U')
		nbr = va_arg(ap, unsigned long long);
	else if (t.len_l == LONG)
		nbr = va_arg(ap, unsigned long);
	else if (t.len_l == NONE)
	{
		if (t.len_h == CHAR)
		{
			a = va_arg(ap, unsigned int);
			nbr = (unsigned char)a;
		}
		else if (t.len_h == SHORT)
		{
			a = va_arg(ap, unsigned int);
			nbr = (unsigned short)a;
		}
	}
	return (nbr);
}
