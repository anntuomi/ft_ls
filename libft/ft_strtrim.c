/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:32:42 by atuomine          #+#    #+#             */
/*   Updated: 2019/10/23 08:23:40 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_skip_whitespaces(char const *s)
{
	size_t	i;
	size_t	start;

	i = 0;
	start = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
	{
		if (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		{
			start++;
		}
		i++;
	}
	return (start);
}

static size_t	ft_skip_end_spaces(char const *s)
{
	size_t i;
	size_t len;

	len = 0;
	i = ft_strlen(s);
	while (s[i] == '\0')
		i--;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
	{
		i--;
		len++;
	}
	return (len);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*trim;

	i = ft_skip_whitespaces(s);
	if (i == ft_strlen(s))
		return (trim = ft_strnew(0));
	len = ft_strlen(s) - (ft_skip_end_spaces(s) + ft_skip_whitespaces(s));
	if ((trim = (char *)malloc(sizeof(trim) * (len + 1))) == NULL)
		return (NULL);
	i = ft_skip_whitespaces(s);
	j = 0;
	while (j < len)
	{
		trim[j] = s[i];
		i++;
		j++;
	}
	trim[j] = '\0';
	return (trim);
}
