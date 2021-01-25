#include <stdio.h>

int main(void)
{
	int res;

	res = printf("%.5d",-1);
	printf("%d", res);

	return (0);
}