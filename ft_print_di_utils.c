/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:34:25 by tkoami            #+#    #+#             */
/*   Updated: 2021/01/26 12:18:40 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_with_zero(long long nbr, t_lists *info, int nbrlen)
{
	int		res;

	res = 0;
	if (info->precision < info->width)
	{
		if (info->flag[MINUS])
			res += ft_putprefix(nbr, info) \
			+ ft_putpadding('0', info->precision - nbrlen) + ft_putnbr(nbr) \
			+ ft_putpadding(' ', info->width - info->precision);
		else if (info->flag[ZERO])
			res += ft_putpadding('0', info->width - nbrlen) + ft_putprefix(nbr, info) \
			+ ft_putnbr(nbr);
		else
			res += ft_putpadding(' ', info->width - info->precision) \
			+ ft_putprefix(nbr, info) + ft_putpadding('0', info->precision - nbrlen) \
			+ ft_putnbr(nbr);
	}
	else
		res += ft_putprefix(nbr, info) + ft_putpadding('0', info->precision - nbrlen) \
		+ ft_putnbr(nbr);
	return (res);
}

int		ft_put_with_spaces(long long nbr, t_lists *info, int nbrlen)
{
	int		res;

	res = 0;
	if (nbrlen < info->width)
	{
		if (info->flag[MINUS])
			res += ft_putprefix(nbr, info) + ft_putnbr(nbr) \
			+ ft_putpadding(' ', info->width - nbrlen);
		else if (info->flag[ZERO])
			res += ft_putpadding('0', info->width - nbrlen) \
			+ ft_putprefix(nbr, info) + ft_putnbr(nbr);
		else
			res += ft_putpadding(' ', info->width - nbrlen)\
			+ ft_putprefix(nbr, info) + ft_putnbr(nbr);
	}
	else
		res += ft_putprefix(nbr, info) + ft_putnbr(nbr);
	return (res);
}