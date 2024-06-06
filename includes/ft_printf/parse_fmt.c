/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:57:02 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/28 13:42:56 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printvarg(t_data *data)
{
	char	spec;
	int		res;

	res = -1;
	spec = data->fmt[data->fmt_idx];
	data->flags.specifier = spec;
	if (spec == 'c')
		res = ft_printc(data);
	else if (spec == 's')
		res = ft_prints(data);
	else if (spec == 'p')
		res = ft_printp(data);
	else if (in("di", spec))
		res = ft_printdi(data);
	else if (spec == 'u')
		res = ft_printu(data);
	else if (in("xX", spec))
		res = ft_printx(data);
	else if (spec == '%')
		res = str_out(data, "%");
	return (res);
}

static void	parse_numflag(t_data *data, int is_prec)
{
	char	*fmt;
	int		*target;

	fmt = (char *)data->fmt;
	if (!ft_isdigit(fmt[data->fmt_idx]) && !in("*.", fmt[data->fmt_idx]))
		return ;
	if (data->fmt[data->fmt_idx] == '.' && !is_prec)
		return ;
	else
		data->fmt_idx += data->fmt[data->fmt_idx] == '.';
	if (is_prec)
		target = &(data->flags.prec);
	else
		target = &(data->flags.width);
	if (fmt[data->fmt_idx] == '*')
	{
		*target = va_arg(data->ap, int);
		data->fmt_idx++;
	}
	else if (ft_isdigit(fmt[data->fmt_idx]))
		*target = printf_atoi(data);
	else
		*target = 0;
}

static int	parse_flags(t_data *data)
{
	char	*fmt;

	data->fmt_idx++;
	fmt = (char *)data->fmt;
	while (in(FLAGS, fmt[data->fmt_idx]))
	{
		if (fmt[data->fmt_idx] == '-')
			data->flags.b_minus = 1;
		if (fmt[data->fmt_idx] == '+')
			data->flags.b_plus = 1;
		if (fmt[data->fmt_idx] == '0')
			data->flags.b_zero = 1;
		if (fmt[data->fmt_idx] == 32)
			data->flags.b_space = 1;
		if (fmt[data->fmt_idx] == '#')
			data->flags.b_hash = 1;
		data->fmt_idx++;
	}
	parse_numflag(data, 0);
	parse_numflag(data, 1);
	if (in(FLAGS, fmt[data->fmt_idx]))
		return (buf_fmt_back(data));
	return (ft_printvarg(data));
}

int	parse_fmt(t_data *data)
{
	int		ret;
	char	*fmt;

	fmt = (char *)data->fmt;
	while (fmt[data->fmt_idx])
	{
		while (fmt[data->fmt_idx] && fmt[data->fmt_idx] != '%')
		{
			char_out(data, fmt[data->fmt_idx]);
			data->fmt_idx++;
		}
		if (fmt[data->fmt_idx] == '%')
		{
			reset_flags(data);
			ret = parse_flags(data);
			if (ret != 0)
				return (ret);
			data->fmt_idx++;
		}
	}
	return (0);
}
