/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:27:56 by tkoami            #+#    #+#             */
/*   Updated: 2020/11/26 14:41:57 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	char	res[2];
	char	mask1;
	char	mask2;

	if ((unsigned char)c <= 0x7F)
	{
		write(fd, &c, sizeof(char));
		return ;
	}
	mask1 = 0b00111111;
	mask2 = 0b11000000;
	res[0] = (((unsigned char)c & mask2) >> 6) | mask2;
	res[1] = ((unsigned char)c & mask1) | 0b10000000;
	write(fd, res, 2);
}
