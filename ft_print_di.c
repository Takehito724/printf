/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:09:51 by tkoami            #+#    #+#             */
/*   Updated: 2021/01/26 10:24:24 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_putminus(long nbr)
{
	if (nbr < 0)
		return (write(1, "-", 1));
	return (0);
}

int		ft_putpadding(char c, int length)
{
	int res;

	res = 0;
	while(length--)
		res += write(1, &c, 1);
	return (res);
}

int		ft_putnbr(long nbr)
{
	char	mod;
	int		res;

	res = 0;
	if (nbr < 0)
		nbr *= -1;
	mod = nbr % 10 + '0';
	nbr /= 10;
	if (nbr > 0)
		return (res += ft_putnbr(nbr) + write(1, &mod, 1));
	else
		return (res += write(1, &mod, 1));
}

int		ft_get_length(long nbr)
{
	int length;

	length = 1;
	while (nbr /= 10)
		length++;
	return (length);
}

int		ft_print_di(va_list *ap, t_lists *info)
{
	long	nbr;
	int		nbrlen;
	int		res;

	nbr = (long)va_arg(*ap, int);
	nbrlen = ft_get_length(nbr);
	if (info->precision == 0 && nbr == 0)
		return (0);
	if (nbrlen <= info->precision && info->precision < info->width)
	{
		if (info->flag[MINUS])
			res += ft_putminus(nbr) \
				+ ft_putpadding('0', info->precision - nbrlen) \
				+ ft_putnbr(nbr) \
				+ ft_putpadding(' ', info->width - info->precision);
		else if (info->flag[ZERO])
			res += ft_putpadding('0', info->width - nbrlen) \
				+ ft_putminus(nbr) + ft_putnbr(nbr);
		else
			res += ft_putpadding(' ', info->width - info->precision) \
				+ ft_putminus(nbr) \
				+ ft_putpadding('0', info->precision - nbrlen) \
				+ ft_putnbr(nbr);
	}
	if (nbrlen <= info->precision && info->width <= info->precision)
		res += + ft_putminus(nbr) \
				+ ft_putpadding('0', info->precision - nbrlen) \
				+ ft_putnbr(nbr);
	if (info->precision < nbrlen && nbrlen < info->width)
	{
		if (info->flag[MINUS])
			res += ft_putminus(nbr) + ft_putnbr(nbr) \
			+ ft_putpadding(' ', info->width - nbrlen);
		else if (info->flag[ZERO])
			res += ft_putpadding('0', info->width - nbrlen) \
			+ ft_putminus(nbr) + ft_putnbr(nbr);
		else
			res += ft_putpadding(' ', info->width - nbrlen)\
			+ ft_putminus(nbr) + ft_putnbr(nbr);
	}
	if (nbrlen > info->precision && info->width <= nbrlen)
		res += ft_putminus(nbr) + ft_putnbr(nbr);
	return (res);
}