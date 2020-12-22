/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 10:05:17 by nabdelba          #+#    #+#             */
/*   Updated: 2019/04/22 19:02:39 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char *s;

	d = (unsigned char *)dst;
	s = (unsigned const char *)src;
	if (s < d)
		while (len--)
			d[len] = s[len];
	else
		while (len--)
			*d++ = *s++;
	return ((void *)dst);
}
