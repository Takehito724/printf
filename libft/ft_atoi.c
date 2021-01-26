/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:09:07 by tkoami            #+#    #+#             */
/*   Updated: 2020/11/26 13:58:25 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int				ft_atoi(const char *str)
{
	unsigned long	result;
	long			sign;
	size_t			i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_strchr(" \t\n\v\f\r", str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	if (sign == 1 && result > LONG_MAX)
		return (-1);
	if (sign == -1 && result - 1 > LONG_MAX)
		return (0);
	return ((int)((long)result * sign));
}
