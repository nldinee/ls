/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 11:53:57 by nabdelba          #+#    #+#             */
/*   Updated: 2019/04/13 11:54:30 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*chunk;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(chunk = ft_strnew(ft_strlen(s))))
		return (NULL);
	s -= 1;
	while (*++s)
		chunk[i++] = f(*s);
	return (chunk);
}
