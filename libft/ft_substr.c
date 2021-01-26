/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 22:39:26 by tkoami            #+#    #+#             */
/*   Updated: 2020/11/24 03:42:13 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	size_t			size;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
		size = 0;
	else if (ft_strlen(s) < (size_t)start + len)
		size = ft_strlen(s) - (size_t)start;
	else
		size = len;
	if (!(res = (char*)malloc(size + 1)))
		return (NULL);
	i = 0;
	while (i < (unsigned int)size)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
