/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:59:15 by tkoami            #+#    #+#             */
/*   Updated: 2021/01/27 01:07:51 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_printarg(va_list *ap, t_lists *info)
{
	int		res;
	char	type;

	res = 0;
	type = *(info->specifier);
	if (type == 'd' || type == 'i')
		res = ft_print_di(ap, info);
	else if (type == 'u' || type == 'x' || type == 'X')
		res = ft_print_ux(ap, info);
	else if (type == 'p')
		res = ft_print_ux(ap, info);
	else if (type == 'c')
		res = ft_print_di(ap, info);
	else if (type == 's')
		res = ft_print_s(ap, info);
	else if (type == '%')
		res = ft_print_di(ap, info);
	return (res);
}