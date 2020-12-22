/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:34:23 by nabdelba          #+#    #+#             */
/*   Updated: 2020/12/21 16:34:25 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		node_cpy(t_node **src, t_node *cpy)
{
	(*src)->name = cpy->name;
	(*src)->path = cpy->path;
	(*src)->date = cpy->date;
	(*src)->st_mode = cpy->st_mode;
	(*src)->st_nlink = cpy->st_nlink;
	(*src)->st_uid = cpy->st_uid;
	(*src)->st_gid = cpy->st_gid;
	(*src)->st_blocks = cpy->st_blocks;
	(*src)->st_size = cpy->st_size;
}

void		swap_nodes(t_node **a, t_node **b)
{
	t_node	tmp;

	tmp = **a;
	node_cpy(a, *b);
	node_cpy(b, &tmp);
}

void		sort(t_node **node, int (*cmp)(t_node *n1, t_node *n2))
{
	t_node	*a;
	t_node	*b;

	a = *node;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (cmp(a, b) > 0)
				swap_nodes(&a, &b);
			b = b->next;
		}
		a = a->next;
	}
}

void		reverse_sort(t_node **new)
{
	t_node	*org;
	t_node	*rev;
	t_node	*tmp;

	org = *new;
	rev = NULL;
	while (org)
	{
		tmp = rev;
		rev = org;
		org = org->next;
		rev->next = tmp;
	}
	*new = rev;
}

t_node		*sort_nodes(t_node *node, t_flags flags)
{
	t_node	*new;

	if (!node)
		return (NULL);
	new = node;
	sort(&new, cmp_alpha);
	flags.t == 1 ? sort(&new, cmp_time) : NULL;
	return (new);
}
