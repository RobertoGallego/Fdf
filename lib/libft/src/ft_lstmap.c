/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:54:53 by groberto          #+#    #+#             */
/*   Updated: 2018/11/27 12:39:21 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *begin;
	t_list *new;
	t_list *before;

	begin = NULL;
	if (lst && (*f))
	{
		begin = (*f)(lst);
		before = begin;
		lst = lst->next;
		while (lst)
		{
			new = (*f)(lst);
			before->next = new;
			before = new;
			lst = lst->next;
		}
		before->next = NULL;
	}
	return (begin);
}
