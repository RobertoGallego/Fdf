/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:41:28 by groberto          #+#    #+#             */
/*   Updated: 2018/11/22 15:54:26 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*str;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (s1[i] != '\0')
		i++;
	str = (char*)malloc(sizeof(*str) * (i + 1));
	if (str == NULL)
		return (NULL);
	while (i > len)
	{
		str[len] = s1[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}
