/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:09:51 by tkoami            #+#    #+#             */
/*   Updated: 2021/02/02 00:57:52 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_putnbr(long long nbr, t_lists *info)
{
	char	mod;

	if (nbr < 0)
		nbr *= -1;
	if (*(info->spec) == 'd' || *(info->spec) == 'i' || *(info->spec) == 'u')
	{
		mod = nbr % 10 + '0';
		nbr /= 10;
		if (nbr)
			return (ft_putnbr(nbr, info) + write(1, &mod, 1));
		else
			return (write(1, &mod, 1));
	}
	else if (*(info->spec) == 'x')
		mod = "0123456789abcdef"[nbr % 16];
	else
		mod = "0123456789ABCDEF"[nbr % 16];
	nbr /= 16;
	if (nbr)
		return (ft_putnbr(nbr, info) + write(1, &mod, 1));
	else
		return (write(1, &mod, 1));
}

int		ft_put_with_prec(long long nbr, t_lists *info, int nbrlen)
{
	int		res;

	res = 0;
	if (info->prec < info->wid)
	{
		if (info->flag[MINUS])
			res = ft_putprefix(nbr, info) \
			+ ft_putpadding('0', info->prec - nbrlen) + ft_putnbr(nbr, info) \
			+ ft_putpadding(' ', info->wid - info->prec);
		else
			res = ft_putpadding(' ', info->wid - info->prec) \
			+ ft_putprefix(nbr, info) \
			+ ft_putpadding('0', info->prec - nbrlen) + ft_putnbr(nbr, info);
	}
	else
		res = ft_putprefix(nbr, info) \
		+ ft_putpadding('0', info->prec - nbrlen) + ft_putnbr(nbr, info);
	return (res);
}

int		ft_put_without_prec(long long nbr, t_lists *info, int nbrlen)
{
	int		res;

	res = 0;
	if (nbrlen < info->wid)
	{
		if (info->flag[MINUS])
			res += ft_putprefix(nbr, info) + ft_putnbr(nbr, info) \
			+ ft_putpadding(' ', info->wid - nbrlen);
		else if (info->flag[ZERO] && info->prec >= 0)
			res +=  ft_putpadding(' ', info->wid - nbrlen) \
			+ ft_putprefix(nbr, info) + ft_putnbr(nbr, info);
		else if (info->flag[ZERO] && info->prec < 0)
			res += ft_putprefix(nbr, info) \
			+ ft_putpadding('0', info->wid - nbrlen) + ft_putnbr(nbr, info);
		else
			res += ft_putpadding(' ', info->wid - nbrlen)\
			+ ft_putprefix(nbr, info) + ft_putnbr(nbr, info);
	}
	else
		res += ft_putprefix(nbr, info) + ft_putnbr(nbr, info);
	return (res);
}

int		ft_get_length(long long nbr, t_lists *info)
{
	int length;

	length = 1;
	if (*(info->spec) == 'd' || *(info->spec) == 'i' || *(info->spec) == 'u')
	{
		while (nbr /= 10)
			length++;
		return (length);
	}
	while (nbr /= 16)
		length++;
	return (length);
}

int		ft_print_nbr(va_list *ap, t_lists *info)
{
	long long	nbr;
	int			nbrlen;
	int			res;

	res = 0;
	info->flag[ZERO] = info->prec >= 0 ? 0 : info->flag[ZERO];
	if (*(info->spec) == 'd' || *(info->spec) == 'i')
		nbr = (long long)va_arg(*ap, int);
	else
		nbr = (long long)va_arg(*ap, unsigned int);
	if (nbr < 0)
		info->wid -= 1;
	nbrlen = ft_get_length(nbr, info);
	if (info->prec == 0 && nbr == 0)
	{
		while (info->wid-- > 0)
			res += write(1, " ", 1);
		return (res);
	}
	if (nbrlen < info->prec)
		res = ft_put_with_prec(nbr, info, nbrlen);
	else
		res = ft_put_without_prec(nbr, info, nbrlen);
	return (res);
}