/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:17:43 by seoyepar          #+#    #+#             */
/*   Updated: 2022/01/17 17:21:10 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;

	if (!lst)
		return ;
	head = *lst;
	while (head)
	{
		head = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		*lst = head;
	}
}
