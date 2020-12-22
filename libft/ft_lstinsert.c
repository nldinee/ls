/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:54:01 by nabdelba          #+#    #+#             */
/*   Updated: 2019/04/22 20:25:14 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list **lst, t_list *node)
{
	t_list *p;

	if (!lst || !node)
		return ;
	node->next = NULL;
	if (*lst == NULL)
		*lst = node;
	else
	{
		p = *lst;
		while (p->next)
			p = p->next;
		p->next = node;
	}
}
