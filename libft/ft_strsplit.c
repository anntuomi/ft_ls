/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:53:25 by atuomine          #+#    #+#             */
/*   Updated: 2019/11/06 11:58:35 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_words(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (s[i])
		count++;
	if (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (s[i + 1] == c)
				count++;
		}
		if (s[i + 1] == '\0' && s[i] == c)
			count--;
		i++;
	}
	return (count);
}

static int	ft_find_word(char const *s, char c, int start)
{
	int i;

	i = 0;
	if (start == 0)
	{
		while (s[i] == c)
			i++;
	}
	while (start > 0)
	{
		while (s[i] == c)
			i++;
		while (s[i] != c)
			i++;
		while (s[i] == c)
			i++;
		start--;
	}
	return (i);
}

static int	ft_word_len(char const *s, char c, int i)
{
	int len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static char	*ft_make_word(char const *s, char c, int start)
{
	char	*word;
	int		len;
	int		j;
	int		i;

	i = ft_find_word(s, c, start);
	len = ft_word_len(s, c, i);
	word = (char *)malloc(sizeof(word) * (len + 1));
	j = 0;
	while (j < len)
	{
		word[j] = s[i];
		i++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		i;

	array = (char **)malloc(sizeof(array) * (ft_count_words(s, c) + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < ft_count_words(s, c))
	{
		array[i] = ft_make_word(s, c, i);
		i++;
	}
	array[i] = NULL;
	return (array);
}
