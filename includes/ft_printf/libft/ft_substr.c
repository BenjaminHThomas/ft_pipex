/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 15:14:37 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/01 21:22:22 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*ps;

	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	ps = (char *)s + start;
	if (len > ft_strlen(ps))
		len = ft_strlen(ps);
	substr = ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, ps, len + 1);
	return (substr);
}
/*
#include <stdio.h>
int	main(void)
{
	char	big[30] = "find the WOW in this";
	char	*small; 
	
	small = ft_substr(big, 9, 3);
	printf("%s", small);
	return (0);
}
*/
