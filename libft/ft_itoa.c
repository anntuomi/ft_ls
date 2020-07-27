/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:15:13 by atuomine          #+#    #+#             */
/*   Updated: 2019/10/22 15:04:29 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_length(int n, int sign)
{
	int len;
	int j;

	if (n == 0)
		return (1);
	j = n;
	len = 0;
	while (j > 0)
	{
		j = j / 10;
		len++;
	}
	if (sign == -1 || sign == -2147483648)
		len++;
	return (len);
}

static int	ft_sign(int n)
{
	int sign;

	sign = 1;
	if (n < 0)
	{
		if (n == -2147483648)
			sign = -2147483648;
		else
			sign = -1;
	}
	return (sign);
}

static int	ft_n_negative(int n)
{
	if (n == -2147483648)
		n = (-2147483647);
	return (n * -1);
}

char		*ft_itoa(int n)
{
	char	*fresh;
	int		i;
	int		length;
	int		sign;

	sign = ft_sign(n);
	if (n < 0)
		n = ft_n_negative(n);
	length = ft_n_length(n, sign);
	fresh = ft_strnew(length);
	if (fresh == NULL)
		return (NULL);
	i = length - 1;
	while (i >= 0)
	{
		fresh[i] = (n % 10) + '0';
		n = n / 10;
		if (sign == -1 || sign == -2147483648)
			fresh[0] = '-';
		i--;
	}
	if (sign == -2147483648)
		fresh[10] = '8';
	return (fresh);
}
