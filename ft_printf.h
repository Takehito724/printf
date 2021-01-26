/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:43:21 by tkoami            #+#    #+#             */
/*   Updated: 2021/01/26 21:02:38 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define ZERO 0
# define MINUS 1
# define DOT 2

# define WIDTH 0
# define PRECISION 1

# define SPECIFIER "cspdiuxX%"
# define NUL_MSG "(null)"

typedef struct s_lists
{
	int		flag[2];
	int		width;
	int		precision;
	char	*specifier;
}				t_lists;

int		ft_printf(const char *format, ...);
int		ft_process_arg(va_list *ap, char **fmt);
void	ft_init_info(t_lists *info);
int		ft_set_nbrs(va_list *ap, char **fmt, t_lists *info, int mode);
int		ft_printarg(va_list *ap, t_lists *info);
int		ft_print_di(va_list *ap, t_lists *info);
int		ft_print_ux(va_list *ap, t_lists *info);
int		ft_print_p(va_list *ap, t_lists *info);
int		ft_print_c(va_list *ap, t_lists *info);
int		ft_print_s(va_list *ap, t_lists *info);
int		ft_print_di(va_list *ap, t_lists *info);
int		ft_get_length(long long nbr, t_lists *info);
int		ft_putnbr(long long nbr, t_lists *info);
int		ft_putpadding(char c, int length);
int		ft_putprefix(long long nbr, t_lists *info);
int		ft_get_length_uxp(long long nbr, t_lists *info);
int		ft_put_with_zero(long long nbr, t_lists *info, int nbrlen);
int		ft_put_with_spaces(long long nbr, t_lists *info, int nbrlen);
int		ft_putnbr_ux(long long nbr, t_lists *info);

#endif