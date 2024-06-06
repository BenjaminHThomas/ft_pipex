/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:29:03 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/23 15:02:09 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <string.h>
#include <stddef.h>*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!ft_strlen(little))
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		while (big[i] != *little && i < len)
			i++;
		if (len <= 0)
			break ;
		j = 0;
		while (big[i + j] && little[j] && big[i + j] == little[j]
			&& (i + j) < len)
			j++;
		if (j == ft_strlen(little))
			return ((char *)big + i);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*big = "lorem ipsum dolor sit amet";
	char	*little = "";
	char	*big_mine = ft_strnstr(big, little, 17);
	char	*real = strnstr(big, little, 17);
	printf("Mine: %s\nReal: %s", big_mine, real);
	return (0);
}*/
