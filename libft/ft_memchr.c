/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 15:52:11 by tkoami            #+#    #+#             */
/*   Updated: 2020/11/26 14:06:21 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	to_find;
	size_t			i;

	src = (unsigned char*)s;
	to_find = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (src[i] == to_find)
			return ((void*)&src[i]);
		i++;
	}
	return (NULL);
}
