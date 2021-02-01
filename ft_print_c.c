/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 21:22:27 by tkoami            #+#    #+#             */
/*   Updated: 2021/02/02 00:59:47 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_print_c(va_list *ap, t_lists *info)
{
	unsigned char	c;
	int				res;

	res = 0;
	if (*(info->spec) == 'c')
		c = (unsigned char)va_arg(*ap, int);
	else
		c = '%';
	if (info->wid > 1)
	{
		if (info->flag[ZERO])
			res = ft_putpadding('0', info->wid - 1) + write(1, &c, 1);
		else if (info->flag[MINUS])
			res = write(1, &c, 1) + ft_putpadding(' ', info->wid - 1);
		else
			res = ft_putpadding(' ', info->wid - 1) + write(1, &c, 1);
	}
	else
		res = write(1, &c, 1);
	return (res);
}