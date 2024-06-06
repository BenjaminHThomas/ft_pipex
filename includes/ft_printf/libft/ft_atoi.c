/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:55:00 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/12 10:17:06 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (ft_isdigit(s[i]))
	{
		res *= 10;
		res += s[i] - '0';
		i++;
	}
	return (res * sign);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	int res = ft_atoi(av[1]);
	printf("%d", res);
	return (0);
}
*/
