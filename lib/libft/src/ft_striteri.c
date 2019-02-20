/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:46:45 by groberto          #+#    #+#             */
/*   Updated: 2018/11/19 16:00:12 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)s;
	if (str && f)
	{
		while (str[i] != '\0')
		{
			(*f)(i, &str[i]);
			i++;
		}
	}
}
