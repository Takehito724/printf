/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 10:19:42 by tkoami            #+#    #+#             */
/*   Updated: 2020/11/26 14:00:13 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*res;

	if (size == 0 || count == 0)
	{
		size = 1;
		count = 1;
	}
	if (!(res = (unsigned char*)malloc(size * count)))
		return (NULL);
	ft_bzero(res, size * count);
	return ((void*)res);
}
