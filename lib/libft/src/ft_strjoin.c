/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:25:47 by groberto          #+#    #+#             */
/*   Updated: 2018/11/26 15:39:36 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = ft_strnew((ft_strlen(s1) + ft_strlen(s2)))))
		return (NULL);
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}
