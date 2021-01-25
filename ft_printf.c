/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:18:41 by tkoami            #+#    #+#             */
/*   Updated: 2021/01/25 21:02:32 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_set_nbrs(va_list *ap, char **fmt, t_lists *info, int mode)
{
	int		nbr;

	nbr = 0;
	if (**fmt == '*')
	{
		nbr = (int)va_arg(*ap, int);
		if (mode == WIDTH && nbr < 0)
		{
			info->flag[MINUS] = 1;
			nbr *= -1;
		}
		if (mode == PRECISION && nbr < 0)
			nbr = -1;
		(*fmt)++;
		return (nbr);
	}
	while('0' <= **fmt && **fmt <= '9')
	{
		nbr = nbr * 10 + **fmt - '0';
		(*fmt)++;
	}
	return (nbr);
}

void	ft_init_info(t_lists *info)
{
	int i;

	i = 0;
	while (i < 2)
		info->flag[i++] = 0;
	info->width = -1;
	info->precision = -1;
	info->specifier = 0;
	info->length = -1;
	return ;
}

int		ft_process_arg(va_list *ap, char **fmt)
{
	t_lists		info;
	int			res;

	ft_init_info(&info);
	(*fmt)++;
	while (ft_strchr("0-", **fmt))
	{
		if (**fmt == '-')
			info.flag[MINUS] = 1;
		else
			info.flag[ZERO] = 1;
		(*fmt)++;
	}
	info.width = ft_set_nbrs(ap, fmt, &info, WIDTH);
	if (**fmt == '.')
	{
		(*fmt)++;
		info.precision = ft_set_nbrs(ap, fmt, &info, PRECISION);
	}
	info.specifier = ft_strchr(SPECIFIER, **fmt);
	res = ft_printarg(ap, &info);
	return (res);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	char	*fmt;
	int		sum;

	sum = 0;
	va_start(ap, format);
	fmt = (char*)format;
	while (*fmt)
	{
		if (*fmt != '%')
			sum += write(1, fmt++, 1);
		else
			sum += ft_process_arg(&ap, &(fmt));
	}
	va_end(ap);
	return (sum);
}