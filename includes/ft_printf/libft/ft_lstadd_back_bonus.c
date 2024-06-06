/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:36:41 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/22 14:26:16 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*plst;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	plst = *lst;
	while (plst -> next)
		plst = plst -> next;
	plst -> next = new;
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	t_list *l = ft_lstnew(strdup("nyacat"));
	t_list *n = ft_lstnew(strdup("OK"));
	ft_lstadd_back(&l, n);
	if (l->next == n && !strcmp(l->next->content, "OK"))
		printf("success!");
	else
		printf("failure!");
	return (0);
}*/
