/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:02:08 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/21 13:13:02 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_skip_whitespaces(const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || \
			str[i] == '\f' || str[i] == '\n' || str[i] == '\r')
		i++;
	return (i);
}

unsigned long long	ft_atollu(const char *str)
{
	int						i;
	unsigned long long int	result;

	if (str == NULL)
		return (0);
	i = ft_skip_whitespaces(str);
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		i++;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result);
}
