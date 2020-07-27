/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:40:09 by atuomine          #+#    #+#             */
/*   Updated: 2019/10/22 15:06:18 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char const *s, int fd)
{
	int		len;
	char	n;

	n = '\n';
	if (s)
	{
		len = ft_strlen(s);
		write(fd, s, len);
		write(fd, &n, 1);
	}
}
