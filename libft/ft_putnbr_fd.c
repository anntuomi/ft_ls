/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:46:05 by atuomine          #+#    #+#             */
/*   Updated: 2019/10/22 15:06:43 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		nb = (nb + 1) * -1;
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd('8', fd);
	}
	else
	{
		if (nb > 2147483647 || nb < -2147483648)
			return ;
		if (nb < 0)
		{
			nb = nb * -1;
			ft_putchar_fd('-', fd);
		}
		if (nb < 10)
		{
			ft_putchar_fd(nb + '0', fd);
			return ;
		}
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd((nb % 10) + '0', fd);
		return ;
	}
}
