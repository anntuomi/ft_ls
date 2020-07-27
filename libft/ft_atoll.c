/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:05:19 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/21 12:05:31 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_skip_whitespaces(const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || \
			str[i] == '\f' || str[i] == '\n' || str[i] == '\r')
		i++;
	return (i);
}

long long			ft_atoll(const char *str)
{
	int			i;
	long long	result;
	long long	sign;

	if (str == NULL)
		return (0);
	sign = 1;
	i = ft_skip_whitespaces(str);
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
