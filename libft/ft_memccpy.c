/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 09:54:14 by nabdelba          #+#    #+#             */
/*   Updated: 2019/04/22 19:02:09 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst,
							const void *src, int c, size_t n)
{
	unsigned char		*d;
	unsigned const char *s;
	unsigned char		chr;

	chr = (unsigned char)c;
	d = (unsigned char *)dst;
	s = (unsigned const char *)src;
	while (n--)
	{
		*d++ = *s;
		if (*s++ == chr)
			return ((void *)d);
	}
	return (NULL);
}
