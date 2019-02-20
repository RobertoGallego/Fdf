/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:24:55 by groberto          #+#    #+#             */
/*   Updated: 2018/11/22 16:13:14 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*strs;
	size_t				i;

	i = 0;
	strs = str;
	while (n > i)
	{
		if (strs[i] == (unsigned char)c)
			return (char *)(&strs[i]);
		i++;
	}
	return (NULL);
}
