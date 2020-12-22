/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:45:53 by aelouazz          #+#    #+#             */
/*   Updated: 2020/12/21 16:47:14 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node			*new_node(char *name, char *path)
{
	t_node		*node;
	struct stat	fstat;

	node = malloc(sizeof(t_node));
	node->name = ft_strdup(name);
	node->path = ft_strjoin(path, name);
	if (lstat(node->path, &fstat) == -1)
	{
		handle_err("ft_ls: ", node->name, 1);
		return (NULL);
	}
	node->st_mode = fstat.st_mode;
	node->st_nlink = fstat.st_nlink;
	node->st_uid = fstat.st_uid;
	node->st_gid = fstat.st_gid;
	node->st_size = fstat.st_size;
	node->st_blocks = fstat.st_blocks;
	node->date = fstat.st_mtime;
	node->st_rdev = fstat.st_rdev;
	node->next = NULL;
	return (node);
}

void			node_push_file(t_node **files, char *name, char *path)
{
	t_node		*nodes;

	nodes = *files;
	if (nodes)
	{
		while (nodes->next)
			nodes = nodes->next;
		nodes->next = new_node(name, path);
	}
	else
		*files = new_node(name, path);
}

int				node_get_data(t_node **files, struct dirent *file, char *path)
{
	t_node		*list;
	char		*tmp_path;

	list = *files;
	if (!file)
		return (0);
	if (path[ft_strlen(path) - 1] == '/')
		tmp_path = ft_strdup(path);
	else
		tmp_path = ft_strjoin(path, "/");
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = new_node(file->d_name, tmp_path);
	}
	else
		*files = new_node(file->d_name, tmp_path);
	ft_strdel(&tmp_path);
	tmp_path = NULL;
	return (1);
}
