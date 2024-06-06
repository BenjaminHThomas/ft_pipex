/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:12:01 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/31 11:43:41 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_data(t_data *data, const char *format)
{
	data->fmt = format;
	data->fmt_idx = 0;
	data->len_out = 0;
	data->varg_len = 0;
	reset_flags(data);
}

int	ft_printf(const char *format, ...)
{
	t_data	data;

	if (BUFF_SIZE <= 0 || !format)
		return (-1);
	va_start(data.ap, format);
	init_data(&data, format);
	if (parse_fmt(&data))
		return (-1);
	return (data.len_out);
}
