/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:57:17 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/11 15:57:35 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;

	if (!dest && !src && n)
		return (dest);
	pd = (unsigned char *)dest;
	ps = (const unsigned char *)src;
	if (pd < ps)
		while (n--)
			*pd++ = *ps++;
	else
	{
		pd += n;
		ps += n;
		while (n--)
			*--pd = *--ps;
	}
	return (dest);
}
/*
// The if block is executed when src is located 
// before the destination in memory.
// The function starts copying from the end of the 
// source and moves towards the beginning to ensure
// that data is copied in the reverse order.
//
// The else block is executed when src is located 
// after dest in memory (or at same position). 
// The function starts copying towards the end as 
// there is no risk of overwriting the source data before
// it has been copied.
//
// This approach safely handles memory overlapping scenarios. 
// It is safer than memcpy for cases where the dest
// and src might overlap

#include <stdio.h>
#include <string.h>

int main () {
   const char src[50] = "https://www.tutorialspoint.com";
   char dest[50];
   char destcpy[50] = "Helo";
   strcpy(dest,"Helo");
   printf("Before memcpy dest = %s\n", dest);
   ft_memmove(dest, src, strlen(src)+1);
   printf("After memcpy dest = %s\n", dest);
   memmove(destcpy, src, strlen(src)+1);
   printf("real memmove = %s\n", destcpy);
   return(0);
}
*/
