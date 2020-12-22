/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 11:28:18 by nabdelba          #+#    #+#             */
/*   Updated: 2019/04/20 22:09:14 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int sign;
	int res;

	res = 0;
	while (ft_iswhite(*nptr) && nptr++)
		;
	sign = ((*nptr == '-') ? -1 : 1);
	nptr += ((*nptr == '-' || *nptr == '+') ? 1 : 0);
	while (ft_isdigit(*nptr) && *nptr)
		res = res * 10 + (*nptr++ - 48);
	return (res * sign);
}
