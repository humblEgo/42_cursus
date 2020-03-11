/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:43:07 by iwoo              #+#    #+#             */
/*   Updated: 2020/02/28 12:35:12 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*new_node;

	if (!(new_node = (t_list *)malloc(sizeof(t_list) * 1)))
		return (NULL);
	if (content == NULL)
		new_node->content = NULL;
	else
		new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
