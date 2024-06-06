/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:04:41 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/15 18:42:02 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out_d_prefix(t_data *data, char *out)
{
	if (!data || !out)
		return (0);
	if (*data->strnum == '-')
	{
		append(data, out, "-", 0);
		return (0);
	}
	else if (data->flags.b_plus)
	{
		append(data, out, "+", 0);
		return (1);
	}
	else if (data->flags.b_space)
	{
		append(data, out, " ", 0);
		return (1);
	}
	return (0);
}

static int	get_len_di(t_data *data)
{
	int		len;
	int		width;
	int		prec;
	char	*strnum;
	int		extra_char;

	strnum = data->strnum;
	len = data->numlen;
	width = data->flags.width;
	prec = data->flags.prec;
	if (*strnum == '-' || data->flags.b_space || data->flags.b_plus)
		extra_char = 1;
	else
		extra_char = 0;
	if (*strnum == '0' && prec == 0 && width == 0)
		return (0);
	if (width > prec)
		return (max(width, len) + extra_char);
	else
		return (max(prec, len) + extra_char);
}

static int	di_left(t_data *data)
{
	char	*out;
	int		res;
	int		width_pad;
	int		prec_pad;
	int		extra_char;

	out = (char *)ft_calloc(data->varg_len + 1, 1);
	if (!out)
		return (1);
	extra_char = out_d_prefix(data, out);
	width_pad = data->flags.width - max(data->numlen, data->flags.prec)
		- extra_char;
	prec_pad = data->flags.prec - data->numlen
		+ (*data->strnum == '-');
	pad_out(data, out, prec_pad, 1);
	append(data, out, data->strnum + (*data->strnum == '-'), 0);
	pad_out(data, out, width_pad, 0);
	res = str_out(data, out);
	free(out);
	return (res);
}

static int	di_right(t_data *data)
{
	char	*out;
	int		res;
	int		width_pad;
	int		prec_pad;
	int		extra_char;

	out = (char *)ft_calloc(data->varg_len + 1, 1);
	if (!out)
		return (1);
	extra_char = ((data->flags.b_space || data->flags.b_plus)
			&& !(*data->strnum == '-'));
	width_pad = data->flags.width - max(data->numlen, data->flags.prec)
		- extra_char;
	prec_pad = max(data->flags.prec - data->numlen
			+ (*data->strnum == '-'), 0);
	if (get_padder(data) == '0')
		out_d_prefix(data, out);
	pad_out(data, out, width_pad, 0);
	if (get_padder(data) == ' ')
		out_d_prefix(data, out);
	pad_out(data, out, prec_pad, 1);
	append(data, out, data->strnum + (*data->strnum == '-'), 0);
	res = str_out(data, out);
	free(out);
	return (res);
}

int	ft_printdi(t_data *data)
{
	int		d;
	int		res;

	res = 0;
	d = va_arg(data->ap, int);
	data->strnum = ft_itoa(d);
	if (!data->strnum)
		return (1);
	data->numlen = ft_strlen(data->strnum);
	if (d == 0 && data->flags.prec == 0)
	{
		data->numlen = 0;
		data->strnum[0] = 0;
	}
	data->varg_len = get_len_di(data);
	if (*data->strnum == '-' && data->flags.prec >= data->numlen)
		if (data->flags.width)
			data->flags.width--;
	if (data->varg_len && data->flags.b_minus)
		res = di_left(data);
	else if (data->varg_len)
		res = di_right(data);
	free(data->strnum);
	return (res);
}
