/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:33:16 by aelouazz          #+#    #+#             */
/*   Updated: 2020/12/21 16:34:55 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ls_long_file(t_node *cur, t_size size)
{
	char			*uid;

	uid = ft_itoa(cur->st_gid);
	print_access(cur);
	print_int(cur->st_nlink, size.linkspace);
	if (getpwuid(cur->st_uid))
		print_str(getpwuid(cur->st_uid)->pw_name, size.userspace);
	else
		print_str(uid, size.userspace);
	if (getgrgid(cur->st_gid))
		print_str(getgrgid(cur->st_gid)->gr_name, size.groupspace);
	else
		print_str(uid, size.groupspace);
	if (S_ISCHR(cur->st_mode) || S_ISBLK(cur->st_mode))
		print_majmin(cur, size);
	else
		print_int(cur->st_size, size.size);
	print_date(cur->date);
	ft_putstr(cur->name);
	S_ISLNK(cur->st_mode) ? print_link(cur) : NULL;
	ft_putendl("");
	free(uid);
}

void				ls_long(t_flags flags, t_node *node, int fileordir)
{
	t_node			*cur;
	t_size			size;

	cur = node;
	size = get_size(flags, node);
	if (fileordir && size.total)
	{
		ft_putstr("Total ");
		ft_putnbr(size.total);
		ft_putchar('\n');
	}
	while (cur)
	{
		if (!(flags.a == 0 && cur->name[0] == '.'))
			ls_long_file(cur, size);
		cur = cur->next;
	}
}

void				ls_simple(t_flags flags, t_node *node)
{
	t_node			*cur;

	cur = node;
	while (cur)
	{
		if (!(flags.a == 0 && (cur->name[0] == '.')))
			ft_putendl(cur->name);
		cur = cur->next;
	}
}

void				display_file(t_flags flags, t_node **files, int fileordir)
{
	t_node			*cur;

	cur = *files;
	cur = sort_nodes(cur, flags);
	flags.r == 1 ? reverse_sort(&cur) : NULL;
	flags.l == 1 ? ls_long(flags, cur, fileordir) : ls_simple(flags, cur);
	flags.u_r == 1 ? recursion(flags, cur) : NULL;
	*files = cur;
}
