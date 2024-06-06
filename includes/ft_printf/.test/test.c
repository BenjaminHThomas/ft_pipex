/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:40:48 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/28 13:43:36 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
/* "cspdiuxX%" 
	"-+ #0"
*/

int	mine;
int	real;

void	compare_result(void)
{
	printf("Mine: %d, Real: %d\n", mine, real);
	if (mine == real)
		printf("Same int return.\n");
	else
		printf("Incorrect int return.\n");
}

void	test_c(void)
{	
	printf("/// Commencing test of c... ///\n");
	
	printf("\nbasic:\n");
	mine = ft_printf("%c\n", 'a');
	real = printf("%c\n", 'a');
	compare_result();
	
	printf("\nnull:\n");
	mine = ft_printf("%c\n", 0);
	real = printf("%c\n", 0);
	compare_result();
	
	printf("\nwidth:\n");
	mine = ft_printf("%10c\n", 'a');
	real = printf("%10c\n", 'a');
	compare_result();
	
	printf("\nmultiple:\n");
	mine = ft_printf("%c %5c %1c %10c\n", 'a', 'a', 'a', 'a');
	real = printf("%c %5c %1c %10c\n", 'a', 'a', 'a', 'a');
	compare_result();
}

void	test_s(void)
{
	char *s = NULL;

	printf("/// Commencing test of s... ///\n");
	
	printf("\nbasic:\n");
	mine = ft_printf("%s\n", "42");
	real = printf("%s\n", "42");
	compare_result();
	
	printf("\nnull\n");
	mine = ft_printf("%s\n", s);
	real = printf("%s\n", s);
	compare_result();
	
	printf("\nwidth:\n");
	mine = ft_printf("%10s\n", "howdy partner");
	real = printf("%10s\n", "howdy partner");
	compare_result();
	
	printf("\nprecision:\n");
	mine = ft_printf("%.10s\n", "42");
	real = ft_printf("%.10s\n", "42");
	compare_result();
	mine = ft_printf("%.0s\n", "42");
	real = ft_printf("%.0s\n", "42");
	compare_result();
	
	printf("\nprec & width:\n");
	mine = ft_printf("%10.10s\n", "42");
	real = ft_printf("%10.10s\n", "42");
	compare_result();
	
	printf("\nmultiple:\n");
	mine = ft_printf("%10.10s %4s %30.171s\n", "42", "wow", "pls");
	real = ft_printf("%10.10s %4s %30.171s\n", "42", "wow", "pls");
	compare_result();
}

void	test_p(void)
{
	int				i = 0;
	unsigned int	j = -1;

	printf("/// Commencing test of p... ///\n");
	
	printf("\nbasic:\n");
	mine = ft_printf("%p\n", &i);
	real = printf("%p\n", &i);
	compare_result();
	
	printf("\nwidth:\n");
	mine = ft_printf("%20p\n", &j);
	real = printf("%20p\n", &j);
	compare_result();
	mine = ft_printf("%2p\n", &j);
	real = printf("%2p\n", &j);
	compare_result();

	printf("\nflags:\n");
	mine = ft_printf("%-30p %20p\n", &i, &j);
	real = printf("%-30p %20p\n", &i, &j);
	compare_result();

	printf("\nmultiple:\n");
	mine = ft_printf("%p %10p %20p\n", &i, &i, &j);
	real = printf("%p %10p %20p\n", &i, &i, &j);
	compare_result();
}

void	test_di(void)
{
	int	d0 = 0;
	int d1 = 42;
	int dmax = 2147483647;
	int dmin = -2147483648;

	printf("/// Commencing test of d & i... ///\n");
	printf("\nbasic:\n");
	mine = ft_printf("%d %d %d %d\n", d0, d1, dmax, dmin);
	real = printf("%d %d %d %d\n", d0, d1, dmax, dmin);
	compare_result();

	printf("\nwidth:\n");
	mine = ft_printf("%0d %1d %20d\n", d0, d1, dmax);
	real = printf("%0d %1d %20d\n", d0, d1, dmax);
	compare_result();

	printf("\nprec:\n");
	mine = ft_printf("%.d %.1d %.42d\n", d1, dmax, dmin);
	real = printf("%.d %.1d %.42d\n", d1, dmax, dmin);
	compare_result();

	printf("\nflags:\n");
	mine = ft_printf("%-+20.15i\n", dmax);
	real = printf("%-+20.15i\n", dmax);
	compare_result();
	mine = ft_printf("% 0.12i\n", dmax);
	real = printf("% 0.12i\n", dmax);
	compare_result();
}

void	test_u(void)
{
	unsigned int	u1 = -1;
	unsigned int	u2 = 65535;
	unsigned int	u3 = 0;
	printf("/// Commencing test of u... ///\n");
	printf("\nbasic:\n");
	mine = ft_printf("%u %u %u\n", u1, u2, u3);
	real = printf("%u %u %u\n", u1, u2, u3);
	compare_result();

	printf("\nwidth:\n");
	mine = ft_printf("%*u %1u %20u\n", 0, u1, u2, u3);
	real = printf("%*u %1u %20u\n", 0, u1, u2, u3);
	compare_result();

	printf("\nprec:\n");
	mine = ft_printf("%.*u %.2u %.20u\n", 0, u1, u2, u3);
	real = printf("%.*u %.2u %.20u\n", 0, u1, u2, u3);
	compare_result();

	printf("\nflags:\n");
	mine = ft_printf("%020u %0168.128u\n", u2, u3);
	real = printf("%020u %0168.128u\n", u2, u3);
	compare_result();
}

void	test_x(void)
{
	int	x0 = 0;
	int	x1 = 42;
	int	x2 = 2147483647;
	printf("/// Commencing test of x... ///\n");
	printf("\nbasic:\n");
	mine = ft_printf("%x %x %x\n", x0, x1, x2);
	real = printf("%x %x %x\n", x0, x1, x2);
	compare_result();
	mine = ft_printf("%X %X %X\n", x0, x1, x2);
	real = printf("%X %X %X\n", x0, x1, x2);
	compare_result();

	printf("\nwidth:\n");
	mine = ft_printf("%*x %1x %42x\n", 0, x0, x1, x2);
	real = printf("%*x %1x %42x\n", 0, x0, x1, x2);
	compare_result();

	printf("\nprec:\n");
	mine = ft_printf("%.x %.1x %.42x\n", x0, x1, x2);
	real = printf("%.x %.1x %.42x\n", x0, x1, x2);
	compare_result();

	printf("\nflags:\n");
	mine = ft_printf("%#020X %-#.3x %0054.92x\n", x2, x1, x0);
	real = printf("%#020X %-#.3x %0054.92x\n", x2, x1, x0);
	compare_result();
}

void	test_mix(void)
{
	int	x1 = 42;
	unsigned int	u1 = -1;
	int dmin = -2147483648;
	int				i = 0;

	printf("/// Commencing test of mix... ///\n");
	mine = ft_printf("%#020x, %0168.128u, %-+20.15i, %-30p, %4s, %10c\n", x1, u1, dmin, &i, "howdy", 'x');
	real = printf("%#020x, %0168.128u, %-+20.15i, %-30p, %4s, %10c\n", x1, u1, dmin, &i, "howdy", 'x');
	compare_result();
}
/*
void	test_invalid(void)
{
	printf("/// Commencing test of invalid input... ///\n");
	mine = ft_printf("%0-0-15-0-10c", 1);
	real = printf("%0-0-15-0-10c", 1);
	compare_result();
}
*/

int	main(void)
{
	test_c();
	ft_printf("\n");
	test_s();
	ft_printf("\n");
	test_p();
	ft_printf("\n");
	test_di();
	ft_printf("\n");
	test_u();
	ft_printf("\n");
	test_x();
	ft_printf("\n");
	test_mix();
	ft_printf("\nNULL check\n");
	mine = ft_printf(NULL);
	real = printf(NULL);
	compare_result();
//	ft_printf("\n");
//	test_invalid();
	return (0);
}
