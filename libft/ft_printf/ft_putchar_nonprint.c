/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_nonprint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 14:19:44 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/08 11:33:42 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nonprint_long1(char c, int maxlen)
{
	int len;

	len = (maxlen < 5 && maxlen != -1 ? maxlen : 5);
	if (c == 0)
		write(1, "[NUL]", len);
	else if (c == 1)
		write(1, "[SOH]", len);
	else if (c == 2)
		write(1, "[STX]", len);
	else if (c == 3)
		write(1, "[ETX]", len);
	else if (c == 4)
		write(1, "[EOT]", len);
	else if (c == 5)
		write(1, "[ENQ]", len);
	else if (c == 6)
		write(1, "[ACK]", len);
	else if (c == 7)
		write(1, "[BEL]", len);
	else if (c == 9)
		write(1, "[TAB]", len);
	else
		len = 0;
	return (len);
}

static int	ft_nonprint_long2(char c, int maxlen)
{
	int len;

	len = (maxlen < 5 && maxlen != -1 ? maxlen : 5);
	if (c == 16)
		write(1, "[DLE]", len);
	else if (c == 17)
		write(1, "[DC1]", len);
	else if (c == 18)
		write(1, "[DC2]", len);
	else if (c == 19)
		write(1, "[DC3]", len);
	else if (c == 20)
		write(1, "[DC4]", len);
	else if (c == 21)
		write(1, "[NAK]", len);
	else if (c == 22)
		write(1, "[SYN]", len);
	else if (c == 23)
		write(1, "[ETB]", len);
	else if (c == 24)
		write(1, "[CAN]", len);
	else
		len = 0;
	return (len);
}

static int	ft_nonprint_25up(char c, int maxlen)
{
	int len;

	if (c == 26 || c == 27 || c == 127)
		len = (maxlen < 5 && maxlen != -1 ? maxlen : 5);
	else
		len = (maxlen < 4 && maxlen != -1 ? maxlen : 4);
	if (c == 25)
		write(1, "[EM]", len);
	else if (c == 26)
		write(1, "[SUB]", len);
	else if (c == 27)
		write(1, "[ESC]", len);
	else if (c == 28)
		write(1, "[FS]", len);
	else if (c == 29)
		write(1, "[GS]", len);
	else if (c == 30)
		write(1, "[RS]", len);
	else if (c == 31)
		write(1, "[US]", len);
	else if (c == 127)
		write(1, "[DEL]", len);
	else
		len = 0;
	return (len);
}

static int	ft_nonprint_short(char c, int maxlen)
{
	int len;

	len = (maxlen < 4 && maxlen != -1 ? maxlen : 4);
	if (c == 8)
		write(1, "[BS]", len);
	else if (c == 10)
		write(1, "[LF]", len);
	else if (c == 11)
		write(1, "[VT]", len);
	else if (c == 12)
		write(1, "[FF]", len);
	else if (c == 13)
		write(1, "[CR]", len);
	else if (c == 14)
		write(1, "[SO]", len);
	else if (c == 15)
		write(1, "[SI]", len);
	else
		len = 0;
	return (len);
}

int			ft_putchar_nonprint(char c, int maxlen)
{
	int len;

	len = 0;
	len = ft_nonprint_long1(c, maxlen);
	if (len == 0)
		len = ft_nonprint_long2(c, maxlen);
	if (len == 0)
		len = ft_nonprint_short(c, maxlen);
	if (len == 0)
		len = ft_nonprint_25up(c, maxlen);
	return (len);
}
