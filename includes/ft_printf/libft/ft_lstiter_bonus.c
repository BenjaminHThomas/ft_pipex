/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:10:53 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/21 20:36:46 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>
void	f1(void	*content)
{
	printf("%p\n", content);
}

int main()
{
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));

    node1->content = malloc(sizeof(int));
    node2->content = malloc(sizeof(int));
    node3->content = malloc(sizeof(int));

    *(int *)(node1->content) = 1;
    *(int *)(node2->content) = 2;
    *(int *)(node3->content) = 3;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    ft_lstiter(node1, f1);
    return 0;
}
*/
