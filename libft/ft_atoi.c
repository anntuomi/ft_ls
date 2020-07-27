/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:32:59 by atuomine          #+#    #+#             */
/*   Updated: 2019/10/22 14:59:52 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip_whitespaces(const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || \
			str[i] == '\f' || str[i] == '\n' || str[i] == '\r')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int i;
	int result;
	int sign;

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
