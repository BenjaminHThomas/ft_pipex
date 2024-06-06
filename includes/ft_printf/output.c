/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_mgmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:44:54 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/15 22:02:39 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Functions for managing the buffer */
#include "ft_printf.h"

int	char_out(t_data *data, char c)
{
	ft_putchar_fd(c, 1);
	data->len_out++;
	return (0);
}

int	str_out(t_data *data, char *s)
{
	int	len;

	if (!s)
		return (1);
	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	data->len_out += len;
	return (0);
}

/* print backwards all chars between & including index and most recent % */
int	buf_fmt_back(t_data *data)
{
	int		i;

	if (!data)
		return (1);
	i = data->fmt_idx;
	while (data->fmt[i] && data->fmt[i] != '%')
		i--;
	while (i <= data->fmt_idx)
	{
		char_out(data, data->fmt[i]);
		i++;
	}
	return (0);
}
