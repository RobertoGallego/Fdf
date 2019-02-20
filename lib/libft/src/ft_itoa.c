/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:45:01 by groberto          #+#    #+#             */
/*   Updated: 2018/11/27 12:40:46 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	n_cpy;

	len = ft_intlen(n);
	n_cpy = n;
	if (n < 0)
	{
		n_cpy = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = n_cpy % 10 + 48;
	while (n_cpy /= 10)
		str[--len] = n_cpy % 10 + 48;
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
