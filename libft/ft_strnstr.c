/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 11:12:56 by nabdelba          #+#    #+#             */
/*   Updated: 2019/04/13 11:13:17 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t nlen;

	nlen = ft_strlen(needle);
	i = len + 1;
	if (!*haystack && !*needle)
		return ((char *)haystack);
	haystack -= 1;
	while (*++haystack && --i >= nlen)
	{
		if (ft_strncmp(haystack, needle, nlen) == 0)
			return ((char *)haystack);
	}
	return (NULL);
}
