/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:58:12 by atuomine          #+#    #+#             */
/*   Updated: 2019/12/20 15:00:42 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_nbrlen(long long nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = nbr * -1;
		i++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

int		ft_baselen(unsigned long long nbr, int base)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / base;
		i++;
	}
	return (i);
}

char	ft_baseletter(unsigned long long int nbr, char id, int base)
{
	unsigned int result;

	result = nbr % base;
	if (result == 10)
		return ((id == 'X' ? 'A' : 'a'));
	if (result == 11)
		return ((id == 'X' ? 'B' : 'b'));
	if (result == 12)
		return ((id == 'X' ? 'C' : 'c'));
	if (result == 13)
		return ((id == 'X' ? 'D' : 'd'));
	if (result == 14)
		return ((id == 'X' ? 'E' : 'e'));
	if (result == 15)
		return ((id == 'X' ? 'F' : 'f'));
	else
		return (result + '0');
}
