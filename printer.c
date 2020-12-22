/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:00:03 by nabdelba          #+#    #+#             */
/*   Updated: 2020/12/21 18:55:00 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_str(char *str, int spacemax)
{
	int		n;

	n = spacemax - ft_strlen(str);
	ft_putstr(str);
	while (n-- > 0)
		ft_putchar(' ');
	ft_putstr("  ");
}

void		print_int(int nlink, int spacemax)
{
	int		n;

	n = spacemax - ft_intlen(nlink);
	while (n-- > 0)
		ft_putchar(' ');
	ft_putnbr(nlink);
	ft_putstr(" ");
}

void		print_2(char *str1, char *str2)
{
	ft_putstr(str1);
	ft_putendl(str2);
}
