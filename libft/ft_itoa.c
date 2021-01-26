/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:09:55 by tkoami            #+#    #+#             */
/*   Updated: 2020/11/23 16:17:43 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		set_nbr(long n, char *res)
{
	long	tmp;
	int		i;

	if (n == 0)
		return ;
	if (n < 0)
		n *= -1;
	tmp = n;
	i = 0;
	while (tmp /= 10)
		i++;
	set_nbr(n / 10, res);
	res[i] = n % 10 + '0';
	res[i + 1] = '\0';
}

static void		set_minus(int n, char *res, size_t len)
{
	if (n <= -1)
	{
		ft_memmove(res + 1, res, len);
		res[0] = '-';
	}
	return ;
}

char			*ft_itoa(int n)
{
	char	*res;
	long	nbr;
	size_t	len;

	nbr = (long)n;
	len = 1;
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr /= 10)
		len++;
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	set_nbr((long)n, res);
	set_minus(n, res, len);
	if (n == 0)
	{
		res[0] = '0';
		res[1] = '\0';
	}
	return (res);
}
