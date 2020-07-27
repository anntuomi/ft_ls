/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:43:24 by atuomine          #+#    #+#             */
/*   Updated: 2019/10/23 16:39:45 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*pdst;
	unsigned char	*psrc;

	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	i = 0;
	if ((pdst && psrc) || pdst || psrc)
	{
		while (i < n)
		{
			pdst[i] = psrc[i];
			i++;
		}
	}
	return (dst);
}
