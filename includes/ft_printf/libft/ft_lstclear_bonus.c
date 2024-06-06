/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:27:07 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/22 13:20:33 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*pnext;

	if (!lst || !del)
		return ;
	head = *lst;
	while (head)
	{
		pnext = head->next;
		ft_lstdelone(head, del);
		head = pnext;
	}
	*lst = NULL;
}
/*
void	del(void *x)
{
	free(x);
}

#include <stdio.h>
int main()
{
    t_list *head = NULL;
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

    head = node1;
    ft_lstclear(&head, del);
    return 0;
}*/
