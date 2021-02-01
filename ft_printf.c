/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:18:41 by tkoami            #+#    #+#             */
/*   Updated: 2021/02/02 01:05:02 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_process_asterisk(va_list *ap, char **fmt, t_lists *info)
{
	if (*(*fmt - 1) == '.')
		info->prec = (int)va_arg(*ap, int);
	else
	{
		info->wid = (int)va_arg(*ap, int);
		if(info->wid < 0)
		{
			info->flag[MINUS] = 1;
			info->flag[ZERO] = 0;
			info->wid *= -1;
		}
	}
	(*fmt)++;
	return (0);
}

int		ft_set_nbrs(va_list *ap, char **fmt, t_lists *info)
{
	while (**fmt && ft_strchr("0123456789.*-", **fmt))
	{
		if (**fmt == '.')
		{
			info->flag[DOT] = 1;
			info->prec = 0;
			(*fmt)++;
			continue ;
		}
		if (**fmt == '*')
		{
			ft_process_asterisk(ap, fmt, info);
			continue ;
		}
		info->flag[DOT] ? (info->prec = ft_atoi(*fmt)) : (info->wid = ft_atoi(*fmt));
		if (**fmt == '-')
			(*fmt)++;
		while ('0' <= **fmt && **fmt <= '9')
			(*fmt)++;
	}
	return (0);
}

void	ft_init_info(t_lists *info)
{
	int i;

	i = 0;
	while (i <= 2)
		info->flag[i++] = 0;
	info->wid = -1;
	info->prec = -1;
	info->spec = 0;
	return ;
}

int		ft_process_arg(va_list *ap, char **fmt, t_lists *info)
{
	(*fmt)++;
	ft_init_info(info);
	while (ft_strchr("0-", **fmt))
	{
		if (**fmt == '-')
		{
			info->flag[MINUS] = 1;
			info->flag[ZERO] = 0;
		}
		if (**fmt == '0' && !info->flag[MINUS])
			info->flag[ZERO] = 1;
		(*fmt)++;
	}
	ft_set_nbrs(ap, fmt, info);
	info->spec = ft_strchr(SPECIFIER, **fmt);
	if (info->spec == NULL || *(info->spec) == '\0')
		return (0);
	(*fmt)++;
	return (ft_printarg(ap, info));
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*fmt;
	t_lists		info;

	info.total_len = 0;
	va_start(ap, format);
	fmt = (char*)format;
	while (*fmt)
	{
		if (*fmt != '%')
			info.total_len += write(1, fmt++, 1);
		else
			info.total_len += ft_process_arg(&ap, &fmt, &info);
	}
	va_end(ap);
	return (info.total_len);
}