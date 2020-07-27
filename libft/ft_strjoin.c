/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:13:07 by atuomine          #+#    #+#             */
/*   Updated: 2019/10/23 18:25:10 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_double_len(char const *s1, char const *s2)
{
	int length;

	length = 0;
	if (s1)
		length = length + ft_strlen(s1);
	if (s2)
		length = length + ft_strlen(s2);
	return (length);
}

static int	ft_joins1(char const *s1, char *new)
{
	int i;

	i = 0;
	if (s1 != NULL)
	{
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
	}
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	length;
	int		i;
	int		start;

	length = ft_double_len(s1, s2);
	if ((new = ft_strnew(length)) == NULL)
		return (NULL);
	start = 0;
	i = ft_joins1(s1, new);
	if (s2 != NULL)
	{
		while (s2[start])
		{
			new[i] = s2[start];
			i++;
			start++;
		}
	}
	new[i] = '\0';
	return (new);
}
