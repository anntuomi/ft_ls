/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:54:06 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/08 11:25:13 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_llutoa(unsigned long long n, int length)
{
	char	*fresh;
	int		i;

	fresh = ft_strnew(length);
	if (fresh == NULL)
		return (NULL);
	i = length - 1;
	while (i >= 0)
	{
		fresh[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (fresh);
}

char		*ft_llutoa_base(unsigned long long n, char id, int base, int length)
{
	char	*fresh;
	int		i;

	fresh = ft_strnew(length);
	if (fresh == NULL)
		return (NULL);
	i = length - 1;
	while (i >= 0)
	{
		fresh[i] = ft_baseletter(n, id, base);
		n = n / base;
		i--;
	}
	return (fresh);
}
