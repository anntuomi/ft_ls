/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:22:37 by atuomine          #+#    #+#             */
/*   Updated: 2019/10/22 15:08:48 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(dst);
	while (dst[i] && i < dstsize)
		i++;
	if (len < dstsize)
	{
		while (src[j] && j < ((dstsize - len - 1)))
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	if (dstsize < len)
		return (len - (len - dstsize) + ft_strlen(src));
	return (len + ft_strlen(src));
}
