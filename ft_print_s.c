/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:08:47 by tkoami            #+#    #+#             */
/*   Updated: 2021/01/26 22:34:21 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnstr(char *str, int n)
{
	return (write(1, str, n));
}

int		ft_put_s_with_zero(char *str, t_lists *info, int strlen)
{
	int		res;

	res = 0;
	if (strlen < info->width)
	{
		if (info->flag[MINUS])
			res += ft_putnstr(str, strlen) \
			+ ft_putpadding(' ', info->width - strlen);
		else if (info->flag[ZERO])
			res += ft_putpadding('0', info->width - strlen) \
			+ ft_putnstr(str, strlen);
		else
			res += ft_putpadding(' ', info->width - strlen) \
			+ ft_putnstr(str, strlen);
	}
	else
		res += ft_putnstr(str, strlen);
	return (res);
}

int		ft_put_s_with_spaces(char *str, t_lists *info)
{
	int		res;

	res = 0;
	if (info->precision < info->width)
	{
		if (info->flag[MINUS])
			res += ft_putnstr(str, info->precision) \
			+ ft_putpadding(' ', info->width - info->precision);
		else if (info->flag[ZERO])
			res += ft_putpadding('0', info->width - info->precision) \
			+ ft_putnstr(str, info->precision);
		else
			res += ft_putpadding(' ', info->width - info->precision)\
			+ ft_putnstr(str, info->precision);
	}
	else
		res += ft_putnstr(str, info->precision);
	return (res);
}

int		ft_print_s(va_list *ap, t_lists *info)
{
	char	*str;
	int		strlen;
	int		res;

	str = (char*)va_arg(*ap, char*);
	if (!str)
		str = NUL_MSG;
	strlen = ft_strlen(str);
	if (info->precision < strlen && info->precision >= 0)
		res = ft_put_s_with_spaces(str, info);
	else
		res = ft_put_s_with_zero(str, info, strlen); 
	return (res);
}