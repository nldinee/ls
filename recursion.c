/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:33:11 by nabdelba          #+#    #+#             */
/*   Updated: 2020/12/21 16:33:25 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		do_recursion(t_flags flags, char *path)
{
	t_node	*files;
	DIR		*dir;

	files = NULL;
	ft_putchar('\n');
	ft_putstr(path);
	ft_putstr(": \n");
	if ((dir = opendir(path)) != 0)
	{
		while (node_get_data(&files, readdir(dir), path) != 0)
			;
		closedir(dir);
		files ? display_file(flags, &files, 1) : NULL;
		free_tnode(&files);
		files = NULL;
	}
	else
		handle_err("ft_ls: ", path, 0);
}

void		recursion(t_flags flags, t_node *files)
{
	t_node	*cur;

	cur = files;
	while (cur)
	{
		if (cur->name && cur->path && S_ISDIR(cur->st_mode) &&
			ft_strcmp(".", cur->name) && ft_strcmp("..", cur->name) &&
			!(flags.a == 0 && cur->name[0] == '.'))
		{
			do_recursion(flags, cur->path);
		}
		cur = cur->next;
	}
}
