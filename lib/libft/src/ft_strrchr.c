/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:12:37 by groberto          #+#    #+#             */
/*   Updated: 2018/11/23 12:42:25 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen((char *)s);
	while (i < (int)len)
	{
		i++;
		s++;
	}
	while (i >= 0)
	{
		if ((char)s[0] == (char)c)
			return ((char *)s);
		s--;
		i--;
	}
	return (NULL);
}
