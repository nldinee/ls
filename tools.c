/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:35:15 by nabdelba          #+#    #+#             */
/*   Updated: 2020/12/21 16:35:24 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				file_is_link(t_list *cur)
{
	struct stat	fstat;

	if (lstat(cur->content, &fstat) == -1)
		return (0);
	if (S_ISLNK(fstat.st_mode))
		return (1);
	return (0);
}

void			free_tlist(t_list **list)
{
	t_list		*hlp;

	while (*list)
	{
		hlp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = hlp;
	}
	free(*list);
}

void			free_tnode(t_node **nodes)
{
	t_node		*hlp;

	while (*nodes)
	{
		hlp = (*nodes)->next;
		free((*nodes)->name);
		free((*nodes)->path);
		free(*nodes);
		*nodes = hlp;
	}
	free(*nodes);
}
