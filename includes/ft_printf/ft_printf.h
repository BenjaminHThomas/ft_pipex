/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:20:12 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/01 12:33:22 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h> /* malloc & free*/
# include <stdarg.h> /* variadics */
# include <unistd.h> /* write */
# include "libft/libft.h"

# define INTMAX 2147483647 /* for testing */
# define INTMIN -2147483648 /* for testing */
# define SPECS "cspdiuxX%" /* ft_printf specifiers */
# define FLAGS "-+ #0"
# define ALL_VALID "-+ #0.*"
# define HEX_BASE "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"
# define BASE_10 "0123456789"
# define BUFF_SIZE 4096

/* **** Structs ****/

/* %[flags][width][.precision][length]specifier
 * specifier = cspdiuxX% */
typedef struct s_flags
{
	int		b_minus;
	int		b_plus;
	int		b_space;
	int		b_hash;
	int		b_zero;
	int		width;
	int		prec;
	char	specifier;
}	t_flags;

typedef struct s_data
{
	const char	*fmt;
	int			fmt_idx;
	va_list		ap;
	int			len_out;
	char		*strnum;
	int			numlen;
	int			varg_len;
	t_flags		flags;
}	t_data;

/* **** prototypes **** */
int		ft_printf(const char *format, ...)
		__attribute__((format(printf, 1, 2)));
void	reset_flags(t_data *data);
int		parse_fmt(t_data *data);
int		printf_atoi(t_data *data);
int		ft_printx(t_data *data);
int		ft_printc(t_data *data);
int		ft_prints(t_data *data);
int		ft_printp(t_data *data);
int		ft_printu(t_data *data);
int		ft_printdi(t_data *data);
int		in(char const *s, char c);
int		str_out(t_data *data, char *s);
int		max(int i1, int i2);
int		min(int n1, int n2);
int		append(t_data *data, char *body, char *att, int is_pad);
int		get_padder(t_data *data);
void	pad_out(t_data *data, char *out, int n, int is_prec);
int		get_prefix(t_data *data);
int		num_digits(long unsigned int n, int base);
int		out_d_prefix(t_data *data, char *out);
void	ft_atoi_base(t_data *data, long unsigned n, char *base);
int		char_out(t_data *data, char c);
int		buf_fmt_back(t_data *data);

#endif
