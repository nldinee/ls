/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 10:12:00 by nabdelba          #+#    #+#             */
/*   Updated: 2019/04/13 10:12:03 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	int		i;

	if (!(s = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1)))
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		s[i] = s1[i];
	s[i] = '\0';
	return (s);
}
