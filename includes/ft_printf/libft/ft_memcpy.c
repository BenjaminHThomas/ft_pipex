/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:18:37 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/11 15:44:41 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;

	if (!dest && !src && n)
		return (dest);
	pd = (unsigned char *)dest;
	ps = (const unsigned char *)src;
	while (n)
	{
		*pd++ = *ps++;
		n--;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main () {
   const char src[50] = "https://www.tutorialspoint.com";
   char dest[50];
   strcpy(dest,"Heloooo!!");
   printf("Before memcpy dest = %s\n", dest);
   ft_memcpy(dest, src, strlen(src)+1);
   printf("After memcpy dest = %s\n", dest);
   
   return(0);
}
*/
