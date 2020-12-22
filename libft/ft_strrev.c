/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:13:31 by nabdelba          #+#    #+#             */
/*   Updated: 2019/04/17 12:20:54 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	int		len;
	char	*revd;
	int		i;

	i = 0;
	len = ft_strlen(s);
	revd = ft_strnew(len);
	while (len--)
		revd[i++] = s[len];
	return (revd);
}
