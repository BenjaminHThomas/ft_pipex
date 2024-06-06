/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:44:39 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/13 08:54:56 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	append_hash(t_data *data)
{
	char	spec;

	spec = data->flags.specifier;
	if (!data->flags.b_hash)
		return ;
	if (spec == 'x')
		append(data, data->strnum, "0x", 0);
	else
		append(data, data->strnum, "0X", 0);
}

static int	get_xpadlen(t_data *data, unsigned int n, int is_prec)
{
	int	prec;
	int	width;

	prec = data->flags.prec;
	if (prec != 0 && prec < data->numlen)
		prec = -1;
	width = data->flags.width;
	if (is_prec)
		return (prec - data->numlen);
	if (data->flags.prec == 0 && n == 0)
	{
		data->flags.b_hash = 0;
		return (data->flags.width);
	}
	else if (data->flags.prec > data->numlen)
		return (width - prec - 2 * (data->flags.b_hash));
	else
		return (width - data->numlen - 2 * (data->flags.b_hash));
}

static int	x_string(t_data *data, unsigned int n, char *base)
{
	int	width_pad;
	int	prec_pad;

	width_pad = get_xpadlen(data, n, 0);
	prec_pad = get_xpadlen(data, n, 1);
	if (!data->flags.b_minus && !data->flags.b_zero)
		pad_out(data, data->strnum, width_pad, 0);
	append_hash(data);
	if (!data->flags.b_minus && data->flags.b_zero)
		pad_out(data, data->strnum, width_pad, 0);
	pad_out(data, data->strnum, prec_pad, 1);
	if (data->flags.prec < data->numlen && n != 0)
		data->flags.prec = -1;
	if (data->flags.prec != 0)
		ft_atoi_base(data, n, base);
	if (data->flags.b_minus)
		pad_out(data, data->strnum, width_pad, 0);
	return (str_out(data, data->strnum));
}

int	ft_printx(t_data *data)
{
	unsigned int	x;
	char			*base;
	int				ret;

	x = va_arg(data->ap, unsigned int);
	data->numlen = num_digits(x, 16);
	if (data->flags.specifier == 'X')
		base = HEX_UP;
	else
		base = HEX_BASE;
	data->varg_len = max(data->flags.prec, data->flags.width);
	data->varg_len = max(data->varg_len, data->numlen) + 2;
	data->strnum = (char *)ft_calloc(data->varg_len + 1, 1);
	if (x == 0)
		data->flags.b_hash = 0;
	ret = x_string(data, x, base);
	free(data->strnum);
	return (ret);
}
