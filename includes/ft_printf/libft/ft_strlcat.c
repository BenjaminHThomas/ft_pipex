/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:51:55 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/11 16:04:39 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dest[i] && i < size)
		i++;
	while (src[j] && (i + j) < size - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < size)
		dest[i + j] = '\0';
	return (ft_strlen(src) + i);
}
/*
int	main(void)
{
    char string[] = "look who it is.";
    char buffer[50] = "Well, well, well ";
	char buffcpy[50] = "Well, well, well ";
    int r;

    r = ft_strlcat(buffer, string, 3);

    printf("Mine: '%s', length %d\n",
            buffer,
            r
          );

    r = strlcat(buffcpy,string, 3);

    printf("Real: '%s', length %d\n",
            buffcpy,
            r
		  );
}
*/
