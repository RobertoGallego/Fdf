/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:27:43 by groberto          #+#    #+#             */
/*   Updated: 2018/11/22 15:22:27 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (*alst && alst)
	{
		if ((*alst)->content)
		{
			if (del)
				del((*alst)->content, (*alst)->content_size);
		}
		free(*alst);
		*alst = NULL;
	}
}
