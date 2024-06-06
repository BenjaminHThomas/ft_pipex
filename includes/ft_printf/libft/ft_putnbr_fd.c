/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:09:27 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/14 17:14:28 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	n2;
	char		c;

	n2 = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		n2 *= -1;
	}
	if (n2 >= 10)
		ft_putnbr_fd(n2 / 10, fd);
	c = n2 % 10 + '0';
	write(fd, &c, 1);
}
/*
int	main(void)
{
	ft_putnbr_fd(-10000043, 1);
	return (0);
}*/
