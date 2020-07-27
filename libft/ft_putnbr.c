/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:39:55 by atuomine          #+#    #+#             */
/*   Updated: 2019/10/22 15:06:32 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		nb = (nb + 1) * -1;
		ft_putchar('-');
		ft_putnbr(nb / 10);
		ft_putchar('8');
	}
	else
	{
		if (nb > 2147483647 || nb < -2147483648)
			return ;
		if (nb < 0)
		{
			nb = nb * -1;
			ft_putchar('-');
		}
		if (nb < 10)
		{
			ft_putchar(nb + '0');
			return ;
		}
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
		return ;
	}
}
