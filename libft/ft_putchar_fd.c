/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:27:56 by tkoami            #+#    #+#             */
/*   Updated: 2021/01/27 02:39:08 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_putchar_fd(char c, int fd)
{
	char	res[2];
	char	mask1;
	char	mask2;
	int		result;

	result = 0;
	if ((unsigned char)c <= 0x7F)
	{
		result += write(fd, &c, sizeof(char));
		return (result);
	}
	mask1 = 0b00111111;
	mask2 = 0b11000000;
	res[0] = (((unsigned char)c & mask2) >> 6) | mask2;
	res[1] = ((unsigned char)c & mask1) | 0b10000000;
	return (result += write(fd, res, 2));
}
