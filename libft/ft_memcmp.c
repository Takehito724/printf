/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:19:18 by tkoami            #+#    #+#             */
/*   Updated: 2020/11/26 14:49:32 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	size_t			i;

	i = 0;
	string1 = (unsigned char*)s1;
	string2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && string1[i] == string2[i])
		i++;
	return (string1[i] - string2[i]);
}
