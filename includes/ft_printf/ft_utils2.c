/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:35:44 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/13 09:25:59 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pad_out(t_data *data, char *out, int n, int is_prec)
{
	char	padchar;
	char	*padstr;
	char	spec;

	if (!data || !out || n <= 0)
		return ;
	spec = data->flags.specifier;
	if (is_prec && in("dipuxX", spec))
		padchar = '0';
	else
		padchar = get_padder(data);
	padstr = (char *)ft_calloc(n + 1, 1);
	if (!padstr)
		return ;
	while (n--)
		padstr[n] = padchar;
	append(data, out, padstr, 1);
	free(padstr);
}

int	get_padder(t_data *data)
{
	char	spec;
	int		prec;

	prec = data->flags.prec;
	spec = data->flags.specifier;
	if (in("dipuxX", spec))
	{
		if (prec >= 0)
			return (32);
		if (data->flags.b_zero && !data->flags.b_minus)
			return ('0');
	}
	return (32);
}

int	get_prefix(t_data *data)
{
	char	spec;

	spec = data->flags.specifier;
	if (!in("upxX", spec) && *data->strnum == '-')
		return ('-');
	if (spec != 'u' && data->flags.b_plus)
		return ('+');
	if (spec != 'u' && data->flags.b_space)
		return (32);
	else
		return (0);
}

int	num_digits(unsigned long int n, int base)
{
	int	numlen;

	if (base <= 0)
		return (-1);
	if (n == 0)
		return (1);
	numlen = 0;
	while (n)
	{
		n /= base;
		numlen++;
	}
	return (numlen);
}

int	min(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}
