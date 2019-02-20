/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:00:52 by groberto          #+#    #+#             */
/*   Updated: 2018/11/26 15:36:08 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->next = NULL;
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if (!(list->content = (void *)malloc(content_size)))
			return (NULL);
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	return (list);
}
