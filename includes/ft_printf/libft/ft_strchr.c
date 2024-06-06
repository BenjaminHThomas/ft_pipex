/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:42:29 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/10 17:31:09 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c2;

	c2 = (unsigned char)c;
	while (*s != c2 && *s)
		s++;
	if (*s == c2)
		return ((char *)s);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str = "WowzeYrs  ppp";
	str = ft_strchr(str, 'Y');
	printf("%s", str);
	return (0);
}
*/
