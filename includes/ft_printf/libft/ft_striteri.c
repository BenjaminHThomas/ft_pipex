/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 08:38:05 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/12 12:24:33 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
/*
#include <stdio.h>
void	example(unsigned int i, char *x)
{
	x[i] = i + '0';
}

int	main(void)
{
	char	str[] = "abcde12345";
	ft_striteri(str, example);
	printf("\n%s\n", str);
	return (0);
}
*/
