/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:03:42 by atuomine          #+#    #+#             */
/*   Updated: 2020/01/23 16:11:43 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define RIGHT '0'
# define LEFT '-'
# define NONE -1
# define SPACE 1
# define ZERO 0
# define YES '#'
# define CHAR 'H'
# define SHORT 'h'
# define LONG 'l'
# define LL 'L'
# define FL 'I'

typedef struct		s_var
{
	int				padding;
	int				precision;
	int				count_wild;
	int				wild_width;
	int				wild_prec;
	char			len_h;
	char			len_l;
	char			sign;
	char			hashtag;
	char			align;
	const char		*width;
	int				j;
	int				error;
}					t_var;

t_var				check_identifier(const char *str, int i);
t_var				parse_identifier(const char *str, t_var t, char c);
t_var				check_precision(const char *str, t_var t);
t_var				new_tvar(int i, const char *str);
t_var				check_wildcard(const char *str, t_var t);
t_var				check_conv_length_bigl(const char *str, t_var t);
t_var				check_conv_length_l(const char *str, t_var t);
t_var				check_conv_length_h(const char *str, t_var t);
t_var				check_flags(const char *str, t_var t);
t_var				parse_wildcard(va_list ap, t_var t);

int					ft_putstr_maxlen(char *str, int maxlen);
int					print_by_type(const char *str, va_list ap, int i, t_var t);
int					print_parameters(const char *str, va_list ap, int i, \
		int *read_len);
int					write_format(const char *format, int j, int *read_len);
int					ft_printf(const char *format, ...);
int					print_int(const char *str, va_list ap, int i, t_var t);
int					print_base(const char *str, va_list ap, int i, t_var t);
int					print_addr(const char *str, va_list ap, int i, t_var t);
int					print_char(const char *str, va_list ap, int i, t_var t);
int					print_string(va_list ap, t_var t);
int					print_float(va_list ap, t_var t);
int					ft_float(double nb, unsigned long long nb_int, t_var t, \
		int n_len);
int					ft_lfloat(long double nb, unsigned long long nb_int, \
		t_var t, int n_len);
int					check_float_padlen(t_var t, int param_len);
int					print_lfloat(va_list ap, t_var t);
int					ft_nbrlen(long long nbr);
int					ft_baselen(unsigned long long nbr, int base);
int					put_prefix(char type, t_var t, int len, char *nbr);
int					prefix_len(char *nbr, char type, t_var t);
int					print_padding(int total_len, char p, t_var *t);
int					ft_print_precision(t_var *t, int param_len);
int					ft_putstr_len(char *s);
int					ft_putchar_len(char a);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_tolower(int c);
int					ft_strleni(const char *s);
int					print_unprintable(va_list ap, t_var t);
int					ft_putchar_nonprint(char c, int maxlen);
int					ft_putstr_nonprint(char *str, int maxlen);

char				ft_baseletter(unsigned long long int nbr, char id, \
		int base);
char				*ft_putdecimal(double nb, double whole, int precision, \
		int *ret);
char				*ft_putdecimal_l(long double nb, long double whole, \
		int precision, int *ret);
char				*ft_itoa(int n);
char				*ft_llutoa(unsigned long long n, int length);
char				*ft_llutoa_base(unsigned long long n, char id, int base, \
		int length);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);

long long int		convert_int(t_var t, va_list ap, char type);
long long int		ft_abs(long long int n);

unsigned long long	convert_base(t_var t, va_list ap, char type);
unsigned long long	ft_atollu(const char *str);

void				ft_putstr(char const *s);
void				ft_putchar(unsigned char c);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);

#endif
