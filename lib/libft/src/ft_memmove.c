/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:02:15 by groberto          #+#    #+#             */
/*   Updated: 2018/11/26 15:37:19 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (!dest && !src)
		return (NULL);
	if (src >= dest)
		return (ft_memcpy(dest, src, len));
	while (len > 0)
	{
		len--;
		((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
	}
	return ((unsigned char *)dest);
}
