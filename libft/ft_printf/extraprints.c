/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extraprints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:46:15 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/08 10:54:25 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_prefix(char type, t_var t, int len, char *nbr)
{
	if (ft_tolower(type) == 'x')
	{
		if (type == 'x')
			len = len + ft_putstr_len("0x");
		else if (type == 'X')
			len = len + ft_putstr_len("0X");
	}
	else if (ft_tolower(type) == 'b')
	{
		if (type == 'b')
			len = len + ft_putstr_len("0b");
		else if (type == 'B')
			len = len + ft_putstr_len("0B");
	}
	else if (ft_tolower(type) == 'o' && ft_atollu(nbr) != 0)
	{
		ft_putchar('0');
		len++;
	}
	else if (ft_tolower(type) == 'o' && ft_atollu(nbr) == 0 && t.precision == 0)
	{
		ft_putchar('0');
		len++;
	}
	return (len);
}

int	prefix_len(char *nbr, char type, t_var t)
{
	int len;

	len = 0;
	if (ft_tolower(type) == 'x' || ft_tolower(type) == 'b')
		len = 2;
	if (ft_tolower(type) == 'o' && ft_atollu(nbr) != 0)
		len = 1;
	if (ft_tolower(type) == 'o' && (ft_atollu(nbr) == 0 && t.precision == 0))
		len = 1;
	return (len);
}

int	print_padding(int total_len, char p, t_var *t)
{
	char	*padstr;
	int		i;

	i = 0;
	if (total_len > 0)
	{
		padstr = (char *)malloc(sizeof(char) * (total_len + 1));
		if (padstr == NULL)
		{
			t->error = -1;
			return (-1);
		}
		while (i < total_len)
		{
			padstr[i] = p;
			i++;
		}
		padstr[i] = '\0';
		write(1, padstr, total_len);
		free(padstr);
	}
	return (total_len);
}

int	ft_print_precision(t_var *t, int param_len)
{
	int		i;
	int		len;
	char	*zeros;

	i = 0;
	len = t->precision - param_len;
	if (len > 0)
	{
		zeros = (char *)malloc(sizeof(char) * (len + 1));
		if (zeros == NULL)
		{
			t->error = -1;
			return (-1);
		}
		while (i < len)
		{
			zeros[i] = '0';
			i++;
		}
		zeros[i] = '\0';
		write(1, zeros, len);
		free(zeros);
	}
	return (i);
}
