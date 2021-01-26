/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:51:06 by tkoami            #+#    #+#             */
/*   Updated: 2020/11/20 14:17:23 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	char	mod;

	nbr = (long)n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	mod = nbr % 10 + '0';
	nbr /= 10;
	if (nbr > 0)
	{
		ft_putnbr_fd((int)nbr, fd);
		write(fd, &mod, 1);
	}
	else
		write(fd, &mod, 1);
}
