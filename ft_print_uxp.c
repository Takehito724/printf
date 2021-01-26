/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uxp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 01:46:07 by tkoami            #+#    #+#             */
/*   Updated: 2021/01/27 02:20:04 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_put_with_zero_uxp(long long nbr, t_lists *info, int nbrlen)
{
	int		res;

	res = 0;
	if (info->precision < info->width)
	{
		if (info->flag[MINUS])
			res += ft_putprefix(nbr, info) \
				+ ft_putpadding('0', info->precision - nbrlen) \
				+ ft_putnbr_ux(nbr, info) \
				+ ft_putpadding(' ', info->width - info->precision);
		else 
			res += ft_putpadding(' ', info->width - info->precision) \
				+ ft_putprefix(nbr, info) \
				+ ft_putpadding('0', info->precision - nbrlen) \
				+ ft_putnbr_ux(nbr, info);
	}
	else
		res += + ft_putprefix(nbr, info) \
				+ ft_putpadding('0', info->precision - nbrlen) \
				+ ft_putnbr_ux(nbr, info);
	return (res);
}

int		ft_put_with_spaces_uxp(long long nbr, t_lists *info, int nbrlen)
{
	int		res;

	res = 0;
	if (nbrlen < info->width)
	{
		if (info->flag[MINUS])
			res += ft_putprefix(nbr, info) + ft_putnbr_ux(nbr, info) \
			+ ft_putpadding(' ', info->width - nbrlen);
		else if (info->flag[ZERO])
			res += ft_putprefix(nbr, info) \
			+ ft_putpadding((info->precision > 0 ? ' ' : '0'), info->width - nbrlen) \
			+ ft_putnbr_ux(nbr, info);
		else
			res += ft_putpadding(' ', info->width - nbrlen)\
			+ ft_putprefix(nbr, info) + ft_putnbr_ux(nbr, info);
	}
	else
		res += ft_putprefix(nbr, info) + ft_putnbr_ux(nbr, info);
	return (res);
}

int		ft_putnbr_ux(long long nbr, t_lists *info)
{
	char	mod;
	int		res;

	res = 0;
	if (*(info->specifier) == 'u')
	{
		mod = nbr % 10 + '0';
		nbr /= 10;
		if (nbr)
			return (res += ft_putnbr_ux(nbr, info) + write(1, &mod, 1));
		else
			return (res += write(1, &mod, 1));
	}
	else if (*(info->specifier) == 'x' || *(info->specifier) == 'p')
		mod = "0123456789abcdef"[nbr % 16];
	else
		mod = "0123456789ABCDEF"[nbr % 16];
	nbr /= 16;
	if (nbr)
		return (res += ft_putnbr_ux(nbr, info) + write(1, &mod, 1));
	else
		return (res += write(1, &mod, 1));
}

int		ft_put_null(t_lists *info)
{
	int		res;

	res = 0;
	if (info->flag[MINUS])
	{
		res += write(1, "0x", 2);
		info->width -= 2;
		if (info->width < 0)
			info->width = 0;
		while ((info->width)--)
			res += write(1, " ", 1);
	}
	else
	{
		info->width -= 2;
		if (info->width < 0)
			info->width = 0;
		while ((info->width)--)
			res += write(1, " ", 1);
		res += write(1, "0x", 2);
	}
	return (res);
}
int		ft_get_length_uxp(long long nbr, t_lists *info)
{
	int length;

	length = 1;
	if (*(info->specifier) == 'p')
		length += 2;
	if (*(info->specifier) == 'u')
		return (length = ft_get_length(nbr, info));
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
	if (*(info->specifier) == 'p')
		nbr = (long long)va_arg(*ap, void*);
	else
		nbr = (long long)va_arg(*ap, unsigned int);
	nbrlen = ft_get_length_uxp(nbr, info);
	if (info->precision == 0 && nbr == 0)
	{
		if (*(info->specifier) == 'p')
			return (res += ft_put_null(info));
		while ((info->width)--)
			res += write(1, " ", 1);
		return (res);
	}
	if (nbrlen <= info->precision)
		res = ft_put_with_zero_uxp(nbr, info, nbrlen);
	else
		res = ft_put_with_spaces_uxp(nbr, info, nbrlen);
	return (res);
}