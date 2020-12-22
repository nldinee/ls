/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:35:40 by aelouazz          #+#    #+#             */
/*   Updated: 2020/12/21 17:02:03 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		core_helper(t_flags flags, t_list **files, t_list **dirs, int mdir)
{
	*files ? handle_files(flags, *files) : 0;
	(*files && *dirs) ? ft_putchar('\n') : 0;
	dirs ? handle_dirs(flags, *dirs, mdir) : 0;
	free_tlist(files);
	free_tlist(dirs);
}

void		core(t_flags flags, t_list *path, int mdir)
{
	DIR		*dir;
	t_list	*files;
	t_list	*dirs;
	t_list	*cur;
	int		islink;

	files = NULL;
	dirs = NULL;
	cur = path;
	while (cur)
	{
		islink = file_is_link(cur);
		islink ? ft_lstpush(&files, cur->content, cur->content_size) : 0;
		if ((dir = opendir(cur->content)) == NULL && !islink)
			errno != ENOTDIR ? handle_err("ft_ls: ", cur->content, 0) : \
				ft_lstpush(&files, cur->content, cur->content_size);
		else if (!islink)
		{
			ft_lstpush(&dirs, cur->content, cur->content_size);
			if (closedir(dir) == -1)
				handle_err("ft_ls: ", cur->content, 0);
		}
		cur = cur->next;
	}
	core_helper(flags, &files, &dirs, mdir);
}

int			list_len(t_list *path)
{
	int		i;
	t_list	*cur;

	i = 1;
	cur = path;
	while (cur->next)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

int			main(int ac, char **av)
{
	t_flags	flags;
	t_list	*path;

	flags = (t_flags){0, 0, 0, 0, 0};
	path = 0;
	if (ac > 1)
		get_parm(ac - 1, av, &flags, &path);
	if (path == NULL)
		path = ft_lstnew(".", 1);
	sort_by_name(&path, list_len(path));
	core(flags, path, path->next != NULL ? 1 : 0);
	free_tlist(&path);
	return (0);
}
