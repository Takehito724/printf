/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:16:23 by tkoami            #+#    #+#             */
/*   Updated: 2020/11/23 01:22:14 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		res;

	tmp = lst;
	res = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		res++;
	}
	return (res);
}
