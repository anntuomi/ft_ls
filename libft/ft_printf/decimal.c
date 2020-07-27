/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:33:38 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/08 10:50:18 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*save_decimal(double nb, double whole, int precision, int *p)
{
	int			i;
	long int	nb_int;
	char		*dec_part;

	dec_part = (char *)malloc(sizeof(char) * precision + 2);
	if (dec_part == NULL)
		return (NULL);
	i = 0;
	while (i <= precision)
	{
		nb = nb - whole;
		nb = nb * 10;
		nb_int = (unsigned long long int)nb;
		whole = (double)nb_int;
		dec_part[i] = nb_int + '0';
		i++;
	}
	dec_part[i] = '\0';
	*p = i;
	return (dec_part);
}

static char	*round_precision_zero(char *dec_part, int precision, int *ret)
{
	if (precision == 0 && dec_part[0] >= '5')
	{
		dec_part[0] = '0';
		*ret = 1;
		dec_part[1] = '\0';
	}
	return (dec_part);
}

static char	*round_decimal(char *dec_part, int i, int *ret)
{
	i--;
	dec_part[i] = dec_part[i] + 1;
	while (i >= -1)
	{
		if (dec_part[i + 1] == '9' + 1)
		{
			dec_part[i + 1] = '0';
			if (i > -1)
				dec_part[i] = dec_part[i] + 1;
			if (i == 0 && dec_part[i] == '9' + 1)
			{
				dec_part[i] = '0';
				*ret = 1;
			}
		}
		i--;
	}
	return (dec_part);
}

char		*ft_putdecimal(double nb, double whole, int precision, int *ret)
{
	int		i;
	int		last_dec;
	char	*dec_part;

	dec_part = save_decimal(nb, whole, precision, &i);
	dec_part = round_precision_zero(dec_part, precision, ret);
	i--;
	last_dec = i;
	if (dec_part[i] >= '5')
		dec_part = round_decimal(dec_part, i, ret);
	dec_part[last_dec] = '\0';
	return (dec_part);
}
