/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:43:38 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/27 14:36:41 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_uitoa(t_data *data, long unsigned n, int numlen)
{
	char	*str;

	if (!data)
		return ;
	str = (char *)ft_calloc(numlen + 1, 1);
	if (!str)
		return ;
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[numlen - 1] = n % 10 + '0';
		n /= 10;
		numlen--;
	}
	append(data, data->strnum, str, 0);
	free(str);
}

static int	u_string(t_data *data, long unsigned n)
{
	int	width;
	int	prec;
	int	width_pad;
	int	prec_pad;

	width = data->flags.width;
	prec = data->flags.prec;
	if (prec == 0 && n == 0)
		width_pad = width;
	else if (prec > data->numlen)
		width_pad = width - prec;
	else
		width_pad = width - data->numlen;
	prec_pad = prec - data->numlen;
	if (!data->flags.b_minus)
		pad_out(data, data->strnum, width_pad, 0);
	pad_out(data, data->strnum, prec_pad, 1);
	if (n != 0 && data->flags.prec < data->numlen)
		data->flags.prec = -1;
	ft_uitoa(data, n, data->numlen);
	if (data->flags.b_minus)
		pad_out(data, data->strnum, width_pad, 0);
	return (str_out(data, data->strnum));
}

int	ft_printu(t_data *data)
{
	long unsigned	n;
	int				ret;

	n = va_arg(data->ap, unsigned int);
	data->numlen = num_digits(n, 10);
	data->varg_len = max(data->flags.prec, data->flags.width);
	data->varg_len = max(data->varg_len, data->numlen) + 1;
	data->strnum = (char *)ft_calloc(data->varg_len, 1);
	if (!data->strnum)
		return (1);
	ret = u_string(data, n);
	free(data->strnum);
	return (ret);
}
