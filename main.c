#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int p;
	int q;
	int r = 5;

	p = ft_printf("[%p]\n", &r);
	q = printf("[%p]\n", &r);
	printf("%d",p-q);
	return (0);
}