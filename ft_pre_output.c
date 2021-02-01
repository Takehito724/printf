/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:59:15 by tkoami            #+#    #+#             */
/*   Updated: 2021/02/01 19:35:26 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_printarg(va_list *ap, t_lists *info)
{
	int		res;
	char	type;

	res = 0;
	type = *(info->spec);
	if (type == 'd' || type == 'i' || type == 'u' \
	|| type == 'x' || type == 'X')
		res = ft_print_nbr(ap, info);
	else if (type == 'p')
		res = ft_print_p(ap, info);
	else if (type == 'c' || type == '%')
		res = ft_print_c(ap, info);
	else if (type == 's')
		res = ft_print_s(ap, info);
	return (res);
}

int		ft_putprefix(long long nbr, t_lists *info)
{
	if (*(info->spec) == 'p')
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
