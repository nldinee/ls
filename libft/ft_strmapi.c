/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 11:55:42 by nabdelba          #+#    #+#             */
/*   Updated: 2019/04/13 11:55:51 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*chunk;
	int		i;

	i = -1;
	if (!s || !f)
		return (NULL);
	if (!(chunk = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[++i])
		chunk[i] = f(i, s[i]);
	return (chunk);
}
