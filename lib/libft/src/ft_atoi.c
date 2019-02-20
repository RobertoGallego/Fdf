/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:02:48 by groberto          #+#    #+#             */
/*   Updated: 2018/11/26 16:55:51 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_atoi(const char *str)
{
	int c;
	int rest;
	int neg;

	c = 0;
	rest = 0;
	while (str[c] && (str[c] == '\t'
				|| str[c] == '\n'
				|| str[c] == '\r'
				|| str[c] == '\v'
				|| str[c] == ' '
				|| str[c] == '\f'
				|| ((str[c] == '+' || str[c] == '-')
					&& str[c + 1] >= '0' && str[c + 1] <= '9')))
		c++;
	neg = (str[c - 1] == '-' ? -1 : 1);
	while (str[c] && (str[c] >= '0' && str[c] <= '9'))
	{
		rest = rest + str[c] - 48;
		if (str[c + 1] && (str[c + 1] >= '0' && str[c + 1] <= '9'))
			rest = rest * 10;
		c++;
	}
	return (rest * neg);
}
