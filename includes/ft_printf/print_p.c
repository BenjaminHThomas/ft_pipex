/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:42:23 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/15 22:18:37 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_atoi_base(t_data *data, long unsigned n, char *base)
{
	char	*str;
	int		numlen;

	if (!data)
		return ;
	numlen = data->numlen;
	str = (char *)ft_calloc(numlen + 2, 1);
	if (!str)
		return ;
	while (n >= 16 && numlen > 1)
	{
		str[numlen - 1] = base[n % 16];
		n /= 16;
		numlen--;
	}
	str[numlen - 1] = base[n % 16];
	append(data, data->strnum, str, 0);
	free(str);
}

static int	create_pstr(t_data *data, long unsigned n)
{
	int	prec;
	int	width;
	int	width_pad;
	int	prec_pad;
	int	numlen;

	prec = data->flags.prec;
	width = data->flags.width;
	numlen = data->numlen;
	width_pad = width - (max(numlen, prec) + 2) - (get_prefix(data) != 0);
	prec_pad = prec - numlen;
	data->flags.prec = -1;
	if (!data->flags.b_zero && !data->flags.b_minus)
		pad_out(data, data->strnum, width_pad, 0);
	out_d_prefix(data, data->strnum);
	append(data, data->strnum, "0x", 0);
	if (data->flags.b_zero && !data->flags.b_minus)
		pad_out(data, data->strnum, width_pad, 0);
	pad_out(data, data->strnum, prec_pad, 1);
	ft_atoi_base(data, n, HEX_BASE);
	if (data->flags.b_minus)
		pad_out(data, data->strnum, width_pad, 0);
	return (str_out(data, data->strnum));
}

int	ft_printp(t_data *data)
{
	long unsigned	n;
	int				ret;

	n = (long unsigned int)va_arg(data->ap, void *);
	data->varg_len = max(max(sizeof(void *) * 2, data->flags.width),
			data->flags.prec + 2 + (get_prefix(data) != 0));
	data->strnum = (char *)ft_calloc(data->varg_len + 1, 1);
	if (!data->strnum)
		return (1);
	data->numlen = num_digits(n, 16);
	if (!n)
	{
		data->flags.b_zero = 0;
		if (!data->flags.b_minus)
			pad_out(data, data->strnum, data->flags.width - 5, 0);
		append(data, data->strnum, "(nil)", 1);
		if (data->flags.b_minus)
			pad_out(data, data->strnum, data->flags.width - 5, 0);
		ret = str_out(data, data->strnum);
	}
	else
		ret = create_pstr(data, n);
	free(data->strnum);
	return (ret);
}
