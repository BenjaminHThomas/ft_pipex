/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:11:53 by bthomas           #+#    #+#             */
/*   Updated: 2024/03/28 20:06:19 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
#include <stdio.h>
int	main(void)
{
	char str[20] = "wowowwowowow";
	ft_bzero(str + 5, 2);
	printf("%s", str);
	return (0);
}
*/
