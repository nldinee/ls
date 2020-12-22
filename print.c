/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:32:20 by nabdelba          #+#    #+#             */
/*   Updated: 2020/12/21 18:59:24 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_link(t_node *node)
{
	char	link[4096];

	ft_bzero(link, 4096);
	readlink(node->path, link, 4096);
	ft_putstr(" -> ");
	ft_putstr(link);
}

void		print_date_helper(char **str1, char **str2, char **tmp)
{
	*tmp = *str1;
	*str2 = ft_strsub(*str1, 20, 4);
	*str1 = ft_strsub(*str1, 4, 6);
	free(*tmp);
	*tmp = *str1;
	*str1 = ft_strjoin(*str1, "  ");
	free(*tmp);
	*tmp = *str1;
	*str1 = ft_strjoin(*str1, *str2);
	free(*tmp);
	free(*str2);
}

void		print_date(time_t date)
{
	char	*str1;
	char	*str2;
	char	*tmp;
	time_t	actualtime;

	actualtime = time(0);
	str1 = ft_strdup(ctime(&date));
	if ((actualtime - 15778463) > date || actualtime < date)
		print_date_helper(&str1, &str2, &tmp);
	else
	{
		tmp = str1;
		str1 = ft_strsub(str1, 4, 12);
		free(tmp);
	}
	str1[12] = '\0';
	ft_putstr(str1);
	ft_putchar(' ');
	free(str1);
}

void		print_majmin(t_node *file, t_size size)
{
	int				min;
	int				maj;
	struct stat		data;

	lstat(file->path, &data);
	min = ft_intlen((minor(data.st_rdev)));
	maj = ft_intlen((major(data.st_rdev)));
	ft_putnbr((int)major(data.st_rdev));
	while (maj < size.maj--)
		ft_putchar(' ');
	ft_putstr(", ");
	ft_putnbr((int)minor(data.st_rdev));
	while (min < size.min--)
		ft_putchar(' ');
	ft_putchar(' ');
}

void		print_access(t_node *elem)
{
	ft_putchar((S_ISFIFO(elem->st_mode)) ? 'p' : '\0');
	ft_putchar((S_ISCHR(elem->st_mode)) ? 'c' : '\0');
	ft_putchar((S_ISDIR(elem->st_mode)) ? 'd' : '\0');
	ft_putchar((S_ISBLK(elem->st_mode)) ? 'b' : '\0');
	ft_putchar((S_ISREG(elem->st_mode)) ? '-' : '\0');
	ft_putchar((S_ISLNK(elem->st_mode)) ? 'l' : '\0');
	ft_putchar((S_ISSOCK(elem->st_mode)) ? 's' : '\0');
	ft_putchar((elem->st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((elem->st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((elem->st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((elem->st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((elem->st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((elem->st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((elem->st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((elem->st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((elem->st_mode & S_IXOTH) ? 'x' : '-');
	ft_putstr("  ");
}
