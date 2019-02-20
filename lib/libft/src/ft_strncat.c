/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:38:20 by groberto          #+#    #+#             */
/*   Updated: 2018/11/19 16:57:48 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (dest[i] != '\0')
		i++;
	while (src[k] != '\0' && k < len)
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dest);
}
