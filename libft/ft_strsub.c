/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:55:32 by nabdelba          #+#    #+#             */
/*   Updated: 2019/04/13 17:56:12 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *tmp;

	if (!s)
		return (NULL);
	if (!(tmp = ft_strnew(len)))
		return (NULL);
	ft_strncpy(tmp, &s[start], len);
	return (tmp);
}
