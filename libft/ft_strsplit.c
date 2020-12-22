/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:55:29 by nabdelba          #+#    #+#             */
/*   Updated: 2019/04/18 17:23:17 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		wc;
	int		x;
	int		len;
	char	**words;

	x = 0;
	if (!s)
		return (NULL);
	wc = ft_cwords((char *)s, c) + 1;
	if (!(words = (char **)malloc((wc) * sizeof(char *))))
		return (NULL);
	i = -1;
	while (s[++i] && i <= (int)ft_strlen(s))
		if (s[i] != c)
		{
			len = i;
			while (s[i] != c)
				i++;
			len = i - len;
			words[x++] = ft_strsub(s, i - len, len);
		}
	words[x] = NULL;
	return (words);
}
