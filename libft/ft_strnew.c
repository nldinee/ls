/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 11:43:34 by nabdelba          #+#    #+#             */
/*   Updated: 2019/04/21 23:39:34 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *chunk;

	if (!(chunk = (char *)malloc(size + 1)))
		return (NULL);
	ft_bzero(chunk, size + 1);
	return (chunk);
}
