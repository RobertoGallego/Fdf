/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:12:55 by groberto          #+#    #+#             */
/*   Updated: 2018/11/27 14:37:44 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dest;
	const char	*srcs;
	size_t		i;
	size_t		len;

	dest = dst;
	srcs = src;
	i = size;
	while (*dest != '\0' && i-- != 0)
		dest++;
	len = dest - dst;
	i = size - len;
	if (i == 0)
		return (len + ft_strlen(srcs));
	while (*srcs)
	{
		if (i != 1)
		{
			*dest++ = *srcs;
			i--;
		}
		srcs++;
	}
	*dest = '\0';
	return (len + (srcs - src));
}
