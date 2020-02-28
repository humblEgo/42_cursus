/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:29:28 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/28 16:25:10 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;

	if (lst != NULL && f != NULL)
	{
		if (!(tmp = ft_lstnew(lst->content)))
			return (NULL);
		if (!(new_lst = f(tmp)))
			return (NULL);
		new_lst->next = ft_lstmap(lst->next, f, del);
		return (new_lst);
	}
	return (NULL);
}
