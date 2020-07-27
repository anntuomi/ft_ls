/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:55:30 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/21 13:24:39 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr_len(char *s)
{
	int len;

	len = 0;
	if (s)
	{
		len = ft_strleni(s);
		write(1, s, len);
	}
	return (len);
}

int		ft_putchar_len(char a)
{
	char c;

	c = (unsigned char)a;
	write(1, &c, 1);
	return (1);
}
