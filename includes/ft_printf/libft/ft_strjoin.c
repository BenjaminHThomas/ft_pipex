/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:20:09 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/04 10:55:36 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	joined = ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, s1, ft_strlen(s1) + 1);
	ft_strlcat(joined, s2, ft_strlen(s2) + 1 + ft_strlen(s1));
	return (joined);
}
/*
#include <stdio.h>
int	main(void)
{
	char	s1[20] = "Awooga";
	char	s2[20] = " Gazoinga!";
	char	*s3;
	s3 = ft_strjoin(s1, s2);
	printf("%s", s3);
	return (0);
}
*/
