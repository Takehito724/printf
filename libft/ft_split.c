/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 10:13:53 by tkoami            #+#    #+#             */
/*   Updated: 2020/11/26 14:18:22 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	root_size(char const *s, char c)
{
	size_t	size;
	int		i;

	size = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			size++;
		i++;
	}
	return (size);
}

static void		*all_free(char **s, int j)
{
	int	i;

	i = 0;
	while (i != j)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char			**res;
	size_t			i;
	size_t			j;
	size_t			len;

	if (s == NULL || !(res = (char**)malloc(sizeof(char*) * root_size(s, c))))
		return (NULL);
	i = 0;
	j = 0;
	len = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			len = 0;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			if (!(res[j] = ft_substr(s, (unsigned int)(i + 1 - len), len)))
				return (all_free(res, j));
			j++;
		}
		len++;
		i++;
	}
	res[j] = NULL;
	return (res);
}
