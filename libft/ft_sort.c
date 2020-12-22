/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:00:36 by nabdelba          #+#    #+#             */
/*   Updated: 2020/12/21 16:30:52 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*swap2node(t_list *ptr1, t_list *ptr2)
{
	t_list			*tmp;

	tmp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = tmp;
	return (ptr2);
}

void				sort_by_name(t_list **head, int count)
{
	t_list			**h;
	int				ij[3];
	t_list			*p1;
	t_list			*p2;

	ij[0] = 0;
	while (ij[0] <= count)
	{
		h = head;
		ij[2] = 0;
		ij[1] = 0;
		while (ij[1] < (count - ij[0] - 1))
		{
			p1 = *h;
			p2 = p1->next;
			if (ft_strcmp(p1->content, p2->content) > 0 && (ij[2] = 1))
				*h = swap2node(p1, p2);
			h = &(*h)->next;
			ij[1]++;
		}
		ij[0]++;
		if (ij[2] == 0)
			break ;
	}
}
