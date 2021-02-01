/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoami <tkoami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:43:21 by tkoami            #+#    #+#             */
/*   Updated: 2021/02/02 00:41:47 by tkoami           ###   ########.fr       */
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
	int		flag[3];
	int		wid;
	int		prec;
	char	*spec;
	int		total_len;
}				t_lists;

int		ft_printf(const char *format, ...);
int		ft_process_arg(va_list *ap, char **fmt, t_lists *info);
void	ft_init_info(t_lists *info);
int		ft_set_nbrs(va_list *ap, char **fmt, t_lists *info);
int		ft_process_asterisk(va_list *ap, char **fmt, t_lists *info);
int		ft_printarg(va_list *ap, t_lists *info);
int		ft_print_p(va_list *ap, t_lists *info);
int		ft_print_c(va_list *ap, t_lists *info);
int		ft_print_s(va_list *ap, t_lists *info);
int		ft_print_nbr(va_list *ap, t_lists *info);
int		ft_put_p_with_prec(unsigned long long p, t_lists *info, int p_len);
int		ft_put_p_without_prec(unsigned long long p, t_lists *info, int p_len);
int		ft_get_p_length(unsigned long long p, t_lists *info);
int		ft_put_p(unsigned long long p, t_lists *info);
int		ft_get_length(long long nbr, t_lists *info);
int		ft_putnbr(long long nbr, t_lists *info);
int		ft_putpadding(char c, int length);
int		ft_putprefix(long long nbr, t_lists *info);
int		ft_put_with_prec(long long nbr, t_lists *info, int nbrlen);
int		ft_put_without_prec(long long nbr, t_lists *info, int nbrlen);
int		ft_print_percent(t_lists *info);

#endif