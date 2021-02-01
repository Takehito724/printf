/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 01:46:07 by tkoami            #+#    #+#             */
/*   Updated: 2021/02/02 01:10:00 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_put_p(unsigned long long p, t_lists *info)
{
	char	mod;

	mod = "0123456789abcdef"[p % 16];
	if (info->prec == 0 && p == 0)
		return(0);
	p /= 16;
	if (p)
		return (ft_put_p(p, info) + write(1, &mod, 1));
	else
		return (write(1, &mod, 1));
}

int		ft_put_p_with_prec(unsigned long long p, t_lists *info, int p_len)
{
		int		res;

	res = 0;
	if (info->prec < info->wid)
	{
		if (info->flag[MINUS])
			res = ft_putprefix(p, info) \
			+ ft_putpadding('0', info->prec - p_len) + ft_put_p(p, info) \
			+ ft_putpadding(' ', info->wid - info->prec);
		else
			res = ft_putpadding(' ', info->wid - info->prec) \
			+ ft_putprefix(p, info) \
			+ ft_putpadding('0', info->prec - p_len) + ft_put_p(p, info);
	}
	else
		res = ft_putprefix(p, info) \
		+ ft_putpadding('0', info->prec - p_len) + ft_put_p(p, info);
	return (res);
}

int		ft_put_p_without_prec(unsigned long long p, t_lists *info, int p_len)
{
	int		res;

	res = 0;
	if (p_len < info->wid)
	{
		if (info->flag[MINUS])
			res += ft_putprefix(p, info) + ft_put_p(p, info) \
			+ ft_putpadding(' ', info->wid - p_len);
		else if (info->flag[ZERO] && info->prec >= 0)
			res +=  ft_putpadding(' ', info->wid - p_len) \
			+ ft_putprefix(p, info) + ft_put_p(p, info);
		else if (info->flag[ZERO] && info->prec < 0)
			res += ft_putprefix(p, info) \
			+ ft_putpadding('0', info->wid - p_len) + ft_put_p(p, info);
		else
			res += ft_putpadding(' ', info->wid - p_len)\
			+ ft_putprefix(p, info) + ft_put_p(p, info);
	}
	else
		res += ft_putprefix(p, info) + ft_put_p(p, info);
	return (res);
}

int		ft_get_p_length(unsigned long long p, t_lists *info)
{
	int		length;

	if (info->prec == 0 && p == 0)
		return (0);
	length = 1;
	while (p /= 16)
		length++;
	return (length);
}

int		ft_print_p(va_list *ap, t_lists *info)
{
	unsigned long long	p;
	int					p_len;
	int					res;

	p = (unsigned long long)va_arg(*ap, void*);
	info->flag[ZERO] = info->prec >= 0 ? 0 : info->flag[ZERO];
	p_len = ft_get_p_length(p, info);
	info->wid -= 2;
	if (p_len < info->prec)
		res = ft_put_p_with_prec(p, info, p_len);
	else
		res = ft_put_p_without_prec(p, info, p_len);
	return (res);
}