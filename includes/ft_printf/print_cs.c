/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:39:37 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/13 09:27:08 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	s_tobuff(t_data *data)
{
	char	*out;
	int		width;
	int		ret;

	width = data->flags.width;
	out = (char *)ft_calloc(max(width, data->numlen) + 1, 1);
	if (!out)
		return (1);
	if (data->flags.b_minus)
	{
		append(data, out, data->strnum, 0);
		pad_out(data, out, width - data->numlen, 0);
	}
	else
	{
		pad_out(data, out, width - data->numlen, 0);
		append(data, out, data->strnum, 0);
	}
	ret = str_out(data, out);
	free(out);
	return (ret);
}

int	ft_prints(t_data *data)
{
	int		ret;
	int		b_null;

	b_null = 0;
	if (data->flags.prec == 0 && !data->flags.width)
		return (0);
	data->strnum = va_arg(data->ap, char *);
	if (!data->strnum)
	{
		if (data->flags.prec < 6 && data->flags.prec != -1)
			data->flags.prec = 0;
		b_null = 1;
		data->strnum = (char *)ft_calloc(7, 1);
		if (!data->strnum)
			return (1);
		ft_strlcpy(data->strnum, "(null)", 7);
	}
	if (data->flags.prec == -1)
		data->flags.prec = ft_strlen(data->strnum);
	data->numlen = min(ft_strlen(data->strnum), data->flags.prec);
	ret = s_tobuff(data);
	if (b_null)
		free(data->strnum);
	return (ret);
}

int	ft_printc(t_data *data)
{
	unsigned char	c;
	int				width;

	c = va_arg(data->ap, int);
	width = data->flags.width;
	if (!width)
		return (char_out(data, c));
	if (!data->flags.b_minus)
		while (--width)
			char_out(data, ' ');
	char_out(data, c);
	if (data->flags.b_minus)
		while (--width)
			char_out(data, ' ');
	return (0);
}
