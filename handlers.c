/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:44:24 by aelouazz          #+#    #+#             */
/*   Updated: 2020/12/21 16:45:26 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			handle_err(char *name, char *error, int ex)
{
	if (errno)
	{
		ft_putstr_fd(name, 2);
		perror(error);
		if (ex)
			exit(1);
	}
}

void			handle_files(t_flags flags, t_list *paths)
{
	t_list		*cur;
	t_node		*files;

	cur = paths;
	files = NULL;
	flags.a = 1;
	while (cur)
	{
		node_push_file(&files, cur->content, "");
		cur = cur->next;
	}
	files ? display_file(flags, &files, 0) : 0;
	free_tnode(&files);
}

void			handle_dirs_2(t_flags flags, t_node *dir_list, int mdir)
{
	DIR			*dir;
	t_node		*files;
	int			first;

	first = 0;
	files = NULL;
	if (!dir_list)
		return ;
	while (dir_list)
	{
		dir = opendir(dir_list->name);
		while (node_get_data(&files, readdir(dir), dir_list->path) != 0)
			;
		closedir(dir);
		if (files)
		{
			first == 1 ? ft_putendl("") : NULL;
			mdir ? print_2(dir_list->name, ":") : NULL;
			first = 1;
			display_file(flags, &files, 1);
		}
		free_tnode(&files);
		dir_list = dir_list->next;
	}
}

void			handle_dirs(t_flags flags, t_list *paths, int mdir)
{
	t_list		*cur;
	t_node		*dir_list;

	cur = paths;
	dir_list = NULL;
	while (cur)
	{
		node_push_file(&dir_list, cur->content, "");
		cur = cur->next;
	}
	dir_list = sort_nodes(dir_list, flags);
	handle_dirs_2(flags, dir_list, mdir);
	free_tnode(&dir_list);
}
