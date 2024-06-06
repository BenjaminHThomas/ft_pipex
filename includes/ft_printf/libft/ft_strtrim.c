/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:45:21 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/12 12:33:25 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	istrimmed(unsigned char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		endpos;
	char	*dest;

	while (istrimmed(*s1, set) && *s1)
		s1++;
	if (!*s1)
		return (ft_strdup(""));
	endpos = ft_strlen(s1);
	while (istrimmed(s1[endpos - 1], set) && s1[endpos - 1])
		endpos--;
	dest = ft_calloc(endpos + 1, sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, endpos + 1);
	return (dest);
}
/*
int	main(void)
{
	char	str[20] = "haha";
	char	*ret;

	ret = ft_strtrim(str);
	printf("%s", ret);
	return (0);
}
*/
