/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 01:46:07 by tkoami            #+#    #+#             */
/*   Updated: 2021/01/26 12:55:42 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_putnbr_x(unsigned long nbr, t_lists *info)
{
	char	mod;
	int		res;

	res = 0;
	if (*(info->specifier) == 'x' || *(info->specifier) == 'p')
		mod = "0123456789abcdef"[nbr % 16];
	else
		mod = "0123456789ABCDEF"[nbr % 16];
	nbr /= 16;
	if (nbr)
		return (res += ft_putnbr_x(nbr, info) + write(1, &mod, 1));
	else
		return (res += write(1, &mod, 1));
}

int		ft_putnbr_u(unsigned long nbr, t_lists *info)
{
	char	mod;
	int		res;

	res = 0;
	if (*(info->specifier) == 'u')
	{
		mod = nbr % 10 + '0';
		nbr /= 10;
		if (nbr)
			return (res += ft_putnbr_u(nbr, info) + write(1, &mod, 1));
		else
			return (res += write(1, &mod, 1));
	}
	else
		return (res += ft_putnbr_x(nbr, info));
}

int		ft_get_length_ux(unsigned long nbr, t_lists *info)
{
	int length;

	length = 1;
	if (*(info->specifier) == 'p')
		length += 2;
	while (nbr /= 16)
		length++;
	return (length);
}

int		ft_print_ux(va_list *ap, t_lists *info)
{
	long long		nbr;
	int				nbrlen;
	int				res;

	res = 0;
	nbr = (unsigned long)va_arg(*ap, unsigned int);
	nbrlen = ft_get_length_ux(nbr, info);
	if (info->precision == 0 && nbr == 0)
		return (0);
	if (nbrlen <= info->precision && info->precision < info->width)
	{
		if (info->flag[MINUS])
			res += ft_putprefix(nbr, info) \
				+ ft_putpadding('0', info->precision - nbrlen) \
				+ ft_putnbr_u(nbr, info) \
				+ ft_putpadding(' ', info->width - info->precision);
		else if (info->flag[ZERO])
			res += ft_putpadding('0', info->width - nbrlen) \
				+ ft_putprefix(nbr, info) + ft_putnbr_u(nbr, info);
		else
			res += ft_putpadding(' ', info->width - info->precision) \
				+ ft_putprefix(nbr, info) \
				+ ft_putpadding('0', info->precision - nbrlen) \
				+ ft_putnbr_u(nbr, info);
	}
	if (nbrlen <= info->precision && info->width <= info->precision)
		res += + ft_putprefix(nbr, info) \
				+ ft_putpadding('0', info->precision - nbrlen) \
				+ ft_putnbr_u(nbr, info);
	if (info->precision < nbrlen && nbrlen < info->width)
	{
		if (info->flag[MINUS])
			res += ft_putprefix(nbr, info) + ft_putnbr_x(nbr, info) \
			+ ft_putpadding(' ', info->width - nbrlen);
		else if (info->flag[ZERO])
			res += ft_putpadding('0', info->width - nbrlen) \
			+ ft_putprefix(nbr, info) + ft_putnbr_u(nbr, info);
		else
			res += ft_putpadding(' ', info->width - nbrlen)\
			+ ft_putprefix(nbr, info) + ft_putnbr_u(nbr, info);
	}
	if (nbrlen > info->precision && info->width <= nbrlen)
		res += ft_putprefix(nbr, info) + ft_putnbr_u(nbr, info);
	return (res);
}