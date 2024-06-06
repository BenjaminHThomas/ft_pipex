/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:37:16 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/12 17:00:52 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	res = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
/*
#include <stdio.h>
char	example(unsigned int i, char x)
{
	printf("index = %d\n", i);
	return (x - 1);
}

int	main(void)
{
	char	*str;
	str = ft_strmapi("Howdy", example);
	printf("\n%s\n", str);
	return (0);
}
*/
