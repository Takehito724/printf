/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:40:59 by tkoami            #+#    #+#             */
/*   Updated: 2020/11/26 14:09:33 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*s1;
	unsigned char			*s2;
	size_t					i;

	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	i = 0;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}
