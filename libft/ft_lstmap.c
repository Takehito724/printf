/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:24:12 by tkoami            #+#    #+#             */
/*   Updated: 2020/11/26 14:03:04 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*first_lst;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(first_lst = ft_lstnew((*f)(lst->content))))
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		lst_new = ft_lstnew((*f)(lst->content));
		if (lst_new == NULL)
		{
			ft_lstclear(&first_lst, (*del));
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&first_lst, lst_new);
	}
	return (first_lst);
}
