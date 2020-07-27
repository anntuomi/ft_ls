/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 09:30:55 by atuomine          #+#    #+#             */
/*   Updated: 2019/10/22 15:10:45 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	nlen;
	int		i;

	nlen = ft_strlen(needle);
	if (nlen == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			if (ft_strncmp(&haystack[i], needle, nlen) == 0)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
