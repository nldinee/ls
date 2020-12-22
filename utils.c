/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:39:33 by nabdelba          #+#    #+#             */
/*   Updated: 2020/12/21 16:39:34 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			cmp_alpha(t_node *n1, t_node *n2)
{
	return (ft_strcmp(n1->name, n2->name));
}

int			cmp_time(t_node *n1, t_node *n2)
{
	return (n1->date < n2->date);
}

void		get_size_norm(t_size *size, t_node *cur)
{
	size->linkspace = ft_intlen(cur->st_nlink) > size->linkspace ? \
	ft_intlen(cur->st_nlink) : size->linkspace;
	size->maj = ft_intlen(major(cur->st_rdev)) > size->maj ? \
	ft_intlen(major(cur->st_rdev)) : size->maj;
	size->min = ft_intlen(minor(cur->st_rdev)) > size->min ? \
	ft_intlen(minor(cur->st_rdev)) : size->min;
	size->size = ft_intlen(cur->st_size) > size->size ? \
	ft_intlen(cur->st_size) : size->size;
	size->total += cur->st_blocks;
}

void		get_size_errorhandling(t_size *size, t_node *cur)
{
	if (getpwuid(cur->st_uid))
		size->userspace = (int)ft_strlen(getpwuid(cur->st_uid)->pw_name) > \
		size->userspace ? \
		(int)ft_strlen(getpwuid(cur->st_uid)->pw_name) : size->userspace;
	else
		size->userspace = (int)ft_strlen(ft_itoa(cur->st_uid)) > \
		size->userspace ? (int)ft_strlen(ft_itoa(cur->st_uid)) \
		: size->userspace;
	if (getgrgid(cur->st_gid))
		size->groupspace = (int)ft_strlen(getgrgid(cur->st_gid)->gr_name) > \
		size->groupspace ?\
		(int)ft_strlen(getgrgid(cur->st_gid)->gr_name) : size->groupspace;
	else
		size->groupspace = (int)ft_strlen(ft_itoa(cur->st_gid)) > \
		size->groupspace ? (int)ft_strlen(ft_itoa(cur->st_gid)) : \
		size->groupspace;
}

t_size		get_size(t_flags flags, t_node *files)
{
	t_node	*cur;
	t_size	size;

	size = (t_size){0, 0, 0, 0, 0, 0, 0};
	cur = files;
	while (cur)
	{
		if (!(flags.a == 0 && cur->name[0] == '.'))
		{
			get_size_norm(&size, cur);
			get_size_errorhandling(&size, cur);
		}
		cur = cur->next;
	}
	return (size);
}
