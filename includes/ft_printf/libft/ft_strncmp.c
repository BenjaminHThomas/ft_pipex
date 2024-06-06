/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:42:37 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/11 17:48:22 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stddef.h>*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n > 1 && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("mine: %d\n", ft_strncmp("abcdef", "abcdefghijklmnop", 6));
	printf("real: %d\n", strncmp("abcdef", "abcdefghijklmnop", 6));
	return (0);
}
*/
