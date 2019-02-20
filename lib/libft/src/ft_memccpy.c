/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:14:20 by groberto          #+#    #+#             */
/*   Updated: 2018/11/21 16:38:02 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*dst;
	const char	*srcs;
	size_t		i;

	i = 0;
	dst = (char *)dest;
	srcs = (char *)src;
	while (i < n)
	{
		dst[i] = srcs[i];
		if (srcs[i] == (char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
