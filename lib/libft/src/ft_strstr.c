/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:58:17 by groberto          #+#    #+#             */
/*   Updated: 2018/11/26 12:11:34 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*s1;
	char	*s2;

	if (*needle == 0)
		return ((void *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			s1 = (void *)haystack + 1;
			s2 = (void *)needle + 1;
			while (*s1 && *s2 && *s1 == *s2)
			{
				++s1;
				++s2;
			}
			if (*s2 == 0)
				return ((void *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
