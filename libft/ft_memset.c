/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:10:12 by atuomine          #+#    #+#             */
/*   Updated: 2019/10/22 15:05:32 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*pb;
	unsigned char	pc;

	i = 0;
	pb = (unsigned char *)b;
	pc = (unsigned char)c;
	if (len)
	{
		while (i < len)
		{
			pb[i] = pc;
			i++;
		}
	}
	return (b);
}
