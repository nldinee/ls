/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 10:07:27 by nabdelba          #+#    #+#             */
/*   Updated: 2019/04/22 19:02:01 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char *src;
	unsigned char		chr;
	size_t				i;

	src = (unsigned const char *)s;
	chr = (unsigned char)c;
	i = -1;
	while (++i < n)
		if (src[i] == chr)
			return ((void *)src + i);
	return (NULL);
}
