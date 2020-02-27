/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:58:35 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/27 23:39:40 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (*lst != NULL)
	{
		del((*lst)->content);
		free(*lst);
		ft_lstclear(&((*lst)->next), del);
		*lst = NULL;
	}
}
