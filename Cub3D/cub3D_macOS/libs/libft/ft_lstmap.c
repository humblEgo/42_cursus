/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:29:28 by iwoo              #+#    #+#             */
/*   Updated: 2020/04/08 19:12:21 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*tmp;
	t_list	*res;

	if (lst != NULL && f != NULL)
	{
		if (!(res = ft_lstnew(f(lst->content))))
			return (NULL);
		new_node = lst->next;
		while (new_node != 0)
		{
			if (!(tmp = ft_lstnew(f(new_node->content))))
			{
				ft_lstclear(&res, del);
				return (NULL);
			}
			ft_lstadd_back(&res, tmp);
			new_node = new_node->next;
		}
		return (res);
	}
	return (NULL);
}
