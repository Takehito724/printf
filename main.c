#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int p;
	int q;
	char *r = "abcd";

	p = ft_printf("|%-20.5u|\n", INT_MAX);
	q = printf("|%-20.5u|\n", INT_MAX);
	printf("%d",p-q);
	return (0);
}