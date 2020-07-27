/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 09:42:30 by atuomine          #+#    #+#             */
/*   Updated: 2019/10/22 15:09:48 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	int		result;

	i = 0;
	result = 1;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			result = 0;
		i++;
	}
	return (result);
}
