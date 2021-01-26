/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:25:03 by tkoami            #+#    #+#             */
/*   Updated: 2020/11/26 14:34:21 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	to_find;
	size_t	i;

	str = (char*)s;
	to_find = (char)c;
	i = 0;
	i = ft_strlen(s);
	while (&str[i] != &str[0] && str[i] != to_find)
		i--;
	if (str[i] == to_find)
		return (&str[i]);
	return (NULL);
}
