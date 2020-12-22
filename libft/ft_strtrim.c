/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:57:44 by nabdelba          #+#    #+#             */
/*   Updated: 2019/04/21 17:30:11 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	start;
	int		tmp;

	if (!s)
		return (NULL);
	start = 0;
	while (ft_is_space(s[start]))
		start++;
	if (s[start] == '\0')
		return (ft_strdup(""));
	len = ft_strlen(s) - 1;
	while (ft_is_space(s[len]))
		len--;
	tmp = (len - start + 1);
	return (ft_strsub(s, start, tmp));
}
