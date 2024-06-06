/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:23:21 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/22 14:21:34 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (NULL == lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	t_list *l;
	t_list *expected;
	t_list *actual;

	l = ft_lstnew(strdup("1"));
	l->next = ft_lstnew(strdup("2"));
	l->next->next = ft_lstnew(strdup("3"));
	expected = l->next->next;
	actual = ft_lstlast(l);
	if (actual == expected)
		printf("Success!");
	else
		printf("Failure!");
	return (0);
}*/
