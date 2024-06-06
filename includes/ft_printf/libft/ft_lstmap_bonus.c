/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:13:09 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/23 14:55:14 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;
	void	*temp;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		temp = f(lst->content);
		node = ft_lstnew(temp);
		if (!node)
		{
			del(temp);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, node);
		lst = lst->next;
	}
	return (head);
}
/*
void	del(void *content)
{
	if (content == NULL)
		return ;
	free(content);
}

void	*change_content(void *s)
{
	if (s)
		free(s);
	s = ft_strdup("AAAAA");
	return (s);
}*/
