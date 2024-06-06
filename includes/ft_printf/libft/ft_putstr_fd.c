/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:31:39 by bthomas           #+#    #+#             */
/*   Updated: 2024/04/08 10:43:48 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	while (*s)
	{
		write(fd, &(*s), 1);
		s++;
	}
}
/*
int	main(void)
{
	ft_putstr_fd("Wowzers", 1);
	return (0);
}
*/
