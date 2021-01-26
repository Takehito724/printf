/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:14:52 by tkoami            #+#    #+#             */
/*   Updated: 2020/11/26 14:18:56 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	to_find;
	size_t	i;

	str = (char*)s;
	to_find = (char)c;
	i = 0;
	while (str[i] != to_find)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return (&str[i]);
}
