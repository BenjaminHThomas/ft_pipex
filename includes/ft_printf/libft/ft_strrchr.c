/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:09:14 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/14 19:01:42 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stddef.h>
#include <string.h>*/

char	*ft_strrchr(const char *s, int c)
{
	char			*ps;
	unsigned char	c2;

	c2 = (unsigned char)c;
	ps = (char *)s + ft_strlen(s);
	if (c2 == '\0')
		return (ps);
	while (ps >= s)
	{
		if (*ps == c2)
			return (ps);
		ps--;
	}
	ps = NULL;
	return (ps);
}
/*
#include <stdio.h>

int	main(void)
{
	char *str = ft_strrchr("teste", 'a');
	char *str2 = strrchr("teste", 'a');
	printf("mine: %s\nreal: %s", str, str2);
	return (0);
}*/
