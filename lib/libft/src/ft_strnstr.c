/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:52:36 by groberto          #+#    #+#             */
/*   Updated: 2018/11/23 14:05:26 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *stack, const char *n, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	while (stack[i] != '\0' && len > i)
	{
		k = 0;
		if (n[k] == '\0')
			return ((char *)stack);
		while (n[k] == stack[i + k] && len > k + i)
		{
			if (n[k + 1] == '\0')
				return (char *)(stack + i);
			k++;
		}
		i++;
	}
	return (0);
}
