/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:53:55 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/09 12:55:54 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_by_type_float(va_list ap, t_var t)
{
	int len;

	len = 0;
	if (t.len_l == FL)
		len = print_lfloat(ap, t);
	else
		len = print_float(ap, t);
	return (len);
}

int			print_by_type(const char *str, va_list ap, int i, t_var t)
{
	int		len;
	char	type;

	type = str[i + 1];
	len = 0;
	if (type == 'd' || type == 'D' || type == 'i')
		len = print_int(str, ap, i, t);
	else if (type == 's')
		len = print_string(ap, t);
	else if (ft_tolower(type) == 'x' || ft_tolower(type) == 'o' || \
			ft_tolower(type) == 'u' || ft_tolower(type) == 'b')
		len = print_base(str, ap, i, t);
	else if (type == 'p')
		len = print_addr(str, ap, i, t);
	else if (type == 'f')
		len = print_by_type_float(ap, t);
	else if (type == 'r')
		len = print_unprintable(ap, t);
	else if (type != '\0')
		len = print_char(str, ap, i, t);
	return (len);
}

int			print_parameters(const char *str, va_list ap, int i, int *read_len)
{
	t_var	t;
	int		len;

	len = 0;
	t = check_identifier(str, i);
	i = t.j;
	len = print_by_type(str, ap, i, t);
	va_end(ap);
	if (len == -1)
		return (-1);
	*read_len = *read_len + len;
	return (i + 1);
}

int			write_format(const char *format, int j, int *read_len)
{
	int i;
	int counter;

	i = j;
	counter = 0;
	while (format[i] != '%' && format[i] != '\0')
	{
		i++;
		counter++;
	}
	write(1, &format[j], counter);
	*read_len = *read_len + counter;
	return (i);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		j;
	int		read_len;

	j = 0;
	read_len = 0;
	va_start(ap, format);
	while (format[j])
	{
		if (format[j] == '%')
		{
			j = print_parameters(format, ap, j, &read_len);
			if (j == -1 || format[j] == '\0')
				break ;
			j++;
		}
		if (format[j] == '\0')
			break ;
		if (format[j] == '%')
			continue ;
		j = write_format(format, j, &read_len);
	}
	va_end(ap);
	read_len = (j == -1 ? -1 : read_len);
	return (read_len);
}
