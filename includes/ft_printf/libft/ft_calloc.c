/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:26:22 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/14 19:10:02 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stddef.h>
#include <stdlib.h>
#include <string.h>*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}
/*
#include <stdio.h>
int	main(void)
{
	int size = 8539;
	void *d1 = ft_calloc(size, sizeof(int));
	void *d2 = calloc(size, sizeof(int));
	printf("%d\n", memcmp(d1, d2, size * sizeof(int)));
	free(d1);
	free(d2);
	void *d1 = ft_calloc(10, 8);
	void *d2 = calloc(10, 8);
	printf("%d\n", memcmp(d1, d2, 10 * 8));
	free(d1);
	free(d2);
	return (0);
}*/
