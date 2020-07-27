/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:58:52 by atuomine          #+#    #+#             */
/*   Updated: 2019/10/22 15:07:35 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	i = 0;
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	while (ps1[i] != '\0' || ps2[i] != '\0')
	{
		if (ps1[i] != ps2[i])
			return (ps1[i] - ps2[i]);
		i++;
	}
	return (0);
}
