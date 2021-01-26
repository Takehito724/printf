/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:09:51 by tkoami            #+#    #+#             */
/*   Updated: 2021/01/26 12:20:18 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_putprefix(long long nbr, t_lists *info)
{
	if (*(info->specifier) == 'p')
		return (write(1, "0x", 2));
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

int		ft_putnbr(long long nbr)
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

int		ft_get_length(long long nbr)
{
	int length;

	length = 1;
	while (nbr /= 10)
		length++;
	return (length);
}

int		ft_print_di(va_list *ap, t_lists *info)
{
	long long	nbr;
	int			nbrlen;
	int			res;

	nbr = (long long)va_arg(*ap, int);
	nbrlen = ft_get_length(nbr);
	if (info->precision == 0 && nbr == 0)
		return (0);
	if (nbrlen <= info->precision)
		res = ft_put_with_zero(nbr, info, nbrlen);
	if (info->precision < nbrlen && nbrlen < info->width)
		res = ft_put_with_spaces(nbr, info, nbrlen);
	return (res);
}