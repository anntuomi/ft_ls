/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:03:09 by atuomine          #+#    #+#             */
/*   Updated: 2019/10/23 09:40:11 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nlen;
	size_t	i;
	size_t	j;

	nlen = ft_strlen(needle);
	if (nlen == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i <= len - nlen)
	{
		j = 0;
		while (haystack[i] && i <= len && needle[j] == haystack[i + j])
		{
			j++;
			if (j == nlen)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
