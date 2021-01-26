/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:43:21 by tkoami            #+#    #+#             */
/*   Updated: 2021/01/26 10:24:12 by tkoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define ZERO 0
# define MINUS 1
# define DOT 2

# define WIDTH 0
# define PRECISION 1

# define SPECIFIER "cspdiuxX%"

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
int		ft_get_length(long nbr);
int		ft_putnbr(long nbr);
int		ft_putpadding(char c, int length);
int		ft_putminus(long nbr);
int		ft_get_length_ux(unsigned long nbr, t_lists *info);
int		ft_putnbr_u(unsigned long nbr, t_lists *info);
int		ft_putnbr_x(unsigned long nbr, t_lists *info);

#endif