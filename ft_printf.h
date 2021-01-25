
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
	int		length;
}				t_lists;

#endif