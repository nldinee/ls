/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:47:55 by aelouazz          #+#    #+#             */
/*   Updated: 2020/12/21 16:49:05 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_lstpush(t_list **path, void const *content, size_t content_size)
{
	t_list	*list;

	list = *path;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_lstnew(content, content_size);
	}
	else
		*path = ft_lstnew(content, content_size);
}

void		error_args(char chr)
{
	ft_putstr_fd("ft_ls is illegal option -- ", 2);
	ft_putchar_fd(chr, 2);
	ft_putstr_fd("\nusage: ft_ls [-lRart] [file ...]\n", 2);
	exit(1);
}

void		get_flags(t_flags *flags, char *str)
{
	int		i;

	i = 0;
	while (str[++i])
	{
		if (ft_strchr(FLAGS, str[i]) || (str[1] == '-' && !str[2]))
		{
			flags->l = (str[i] == 'l') ? 1 : flags->l;
			flags->r = (str[i] == 'r') ? 1 : flags->r;
			flags->u_r = (str[i] == 'R') ? 1 : flags->u_r;
			flags->t = (str[i] == 't') ? 1 : flags->t;
			flags->a = (str[i] == 'a') ? 1 : flags->a;
		}
		else
			error_args(str[i]);
	}
}

int			check_flag(char *str)
{
	if (str && str[0] == '-' && str[1])
		return (1);
	return (0);
}

void		get_parm(int ac, char **av, t_flags *flags, t_list **path)
{
	int		i;
	int		is_flag;

	i = -1;
	is_flag = 1;
	while (++i < ac)
	{
		if (check_flag(av[i + 1]) == 0)
			is_flag = 0;
		if (is_flag == 1)
			get_flags(flags, av[i + 1]);
		else
			ft_lstpush(path, av[i + 1], ft_strlen(av[i + 1]) + 1);
	}
}
