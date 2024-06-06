/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:43:11 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/04 17:25:51 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_digits(long int n)
{
	int	num;

	if (n == 0)
		return (1);
	num = 0;
	while (n > 0)
	{
		num++;
		n /= 10;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char			*str;
	long int		n2;
	int				num_len;

	n2 = n;
	if (n < 0)
		n2 *= -1;
	num_len = num_digits(n2) + (n < 0);
	str = ft_calloc(num_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (num_len > 0 + (n < 0))
	{
		str[num_len - 1] = n2 % 10 + '0';
		n2 /= 10;
		num_len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	int	n = 2147483647;
	char *str = ft_itoa(n);
	printf("%s", str);
	return (0);
}
*/
