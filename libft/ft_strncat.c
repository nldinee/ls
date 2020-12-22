/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 10:59:44 by nabdelba          #+#    #+#             */
/*   Updated: 2019/04/20 19:30:17 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t dstl;
	size_t i;

	dstl = ft_strlen(s1);
	i = -1;
	while (++i < n && s2[i])
		s1[dstl++] = s2[i];
	s1[dstl] = '\0';
	return (s1);
}
