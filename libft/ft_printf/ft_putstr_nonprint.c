/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_nonprint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 14:22:44 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/08 11:34:41 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nonprint_maxlen(char *str, int i, int maxlen, int len)
{
	if (str[0] == 0)
		len = len + ft_putchar_nonprint(str[0], maxlen);
	else
	{
		while (str[i] != '\0' && len < maxlen)
		{
			if (str[i] < 32 || str[i] == 127)
				len = len + (ft_putchar_nonprint(str[i], maxlen - len));
			else
			{
				ft_putchar(str[i]);
				len++;
			}
			i++;
			if (str[i] == 0)
				len = len + ft_putchar_nonprint(str[i], maxlen - len);
		}
	}
	return (len);
}

static int	nonprint(char *str, int i, int len)
{
	if (str[0] == '0')
		len = len + ft_putchar_nonprint(str[0], -1);
	else
	{
		while (str[i] != '\0')
		{
			if (str[i] < 32 || str[i] == 127)
				len = len + (ft_putchar_nonprint(str[i], -1));
			else
			{
				ft_putchar(str[i]);
				len++;
			}
			i++;
			if (str[i] == 0)
				len = len + ft_putchar_nonprint(str[i], -1);
		}
	}
	return (len);
}

int			ft_putstr_nonprint(char *str, int maxlen)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (maxlen != -1)
		len = nonprint_maxlen(str, i, maxlen, len);
	else
		len = nonprint(str, i, len);
	return (len);
}
