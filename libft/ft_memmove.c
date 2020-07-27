/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:03:55 by atuomine          #+#    #+#             */
/*   Updated: 2019/10/23 16:50:20 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	psrc_to_pdst_r(unsigned char *pdst, unsigned char *psrc, size_t i)
{
	while (i > 0)
	{
		pdst[i - 1] = psrc[i - 1];
		i--;
	}
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*pdst;
	unsigned char	*psrc;

	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	i = len;
	if (pdst == NULL && psrc == NULL)
		return (NULL);
	if (psrc < pdst)
		psrc_to_pdst_r(pdst, psrc, i);
	else
	{
		i = 0;
		while (i < len)
		{
			pdst[i] = psrc[i];
			i++;
		}
	}
	return (dst);
}
