/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:13:28 by groberto          #+#    #+#             */
/*   Updated: 2018/11/26 15:35:26 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;

	(str = (char *)malloc(sizeof(char) * (size + 1)));
	if (str == NULL)
		return (NULL);
	ft_memset(str, '\0', size + 1);
	return (str);
}
