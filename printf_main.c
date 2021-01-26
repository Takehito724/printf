

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>

#include <math.h>

#include <ctype.h>
#include "ft_printf.h"

int main()
{
    int k;
    
    printf("%s\n", "---Simple Conversion Management---");
    k = printf("%c, %s, %s, %s, %s, %s\n", '0', "0", "2147483647", "-2147483648", "", NULL);
    printf("k = %d\n", k);
    k = ft_printf("%c, %s, %s, %s, %s, %s\n", '0', "0", "2147483647", "-2147483648", "", NULL);
    printf("k = %d\n", k);
    
    k = printf("%x, %x, %x, %X, %X, %X, %p, %p, %p\n", 0, INT_MIN, INT_MAX, 0, INT_MIN, INT_MAX, 0, NULL, &k);
    printf("k = %d\n", k);
    k = ft_printf("%x, %x, %x, %X, %X, %X, %p, %p, %p\n", 0, INT_MIN, INT_MAX, 0, INT_MIN, INT_MAX, 0, NULL, &k);
    printf("k = %d\n", k);
    
    k = printf("%i, %i, %i, %d, %d, %d\n", 0, INT_MIN, INT_MAX, 0, INT_MIN, INT_MAX);
    printf("k = %d\n", k);
    k = ft_printf("%i, %i, %i, %d, %d, %d\n", 0, INT_MIN, INT_MAX, 0, INT_MIN, INT_MAX);
    printf("k = %d\n", k);
    
    
    printf("%s\n", "---Simple Flags Management---");
    k = printf("|%0s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%0s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%1s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%1s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%2s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%2s|\n", "1234567890");
    printf("k = %d\n", k);
    
    printf("------------------\n");
    
    k = printf("|%10s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%10s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%20s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%20s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%30s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%30s|\n", "1234567890");
    printf("k = %d\n", k);
    
    printf("%s\n", "---with '-'---");
    k = printf("|%-0s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%-0s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%-1s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%-1s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%-2s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%-2s|\n", "1234567890");
    printf("k = %d\n", k);
    
    printf("------------------\n");

    k = printf("|%-10s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%-10s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%-20s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%-20s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%-30s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%-30s|\n", "1234567890");
    printf("k = %d\n", k);

    printf("%s\n", "---with '0'---");
    k = printf("|%00s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%00s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%01s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%01s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%02s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%02s|\n", "1234567890");
    printf("k = %d\n", k);

    printf("------------------\n");

    k = printf("|%010s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%010s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%020s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%020s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%030s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%030s|\n", "1234567890");
    printf("k = %d\n", k);
    
    printf("%s\n", "---with '.'---");
    k = printf("|%.s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%.0s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%.s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%.0s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%.1s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%.1s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%.2s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%.2s|\n", "1234567890");
    printf("k = %d\n", k);

    printf("..................\n");

    k = printf("|%.10s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%.10s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%.20s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%.20s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%.30s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%.30s|\n", "1234567890");
    printf("k = %d\n", k);
    
    printf("%s\n", "---Adv Flags Management---");
    printf("%s\n", "---aste as width---");
    k = printf("|%*s|\n", 0, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%*s|\n", 0, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%*s|\n", 1, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%*s|\n", 1, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%*s|\n", 10, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%*s|\n", 10, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%*s|\n", 20, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%*s|\n", 20, "1234567890");
    printf("k = %d\n", k);

    printf("******************\n");

    k = printf("|%*s|\n", -1, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%*s|\n", -1, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%*s|\n", -10, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%*s|\n", -10, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%*s|\n", -20, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%*s|\n", -20, "1234567890");
    printf("k = %d\n", k);
    
    printf("******************\n");
   
    printf("%s\n", "---aste as prec---");
    k = printf("|%.*s|\n", 0, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%.*s|\n", 0, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%.*s|\n", 1, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%.*s|\n", 1, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%.*s|\n", 10, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%.*s|\n", 10, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%.*s|\n", 20, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%.*s|\n", 20, "1234567890");
    printf("k = %d\n", k);

    printf(".*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*\n");

    k = printf("|%.*s|\n", -1, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%.*s|\n", -1, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%.*s|\n", -10, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%.*s|\n", -10, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%.*s|\n", -20, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%.*s|\n", -20, "1234567890");
    printf("k = %d\n", k);

    printf(".*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*\n");

    k = printf("|%.*s|\n", INT_MAX, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%.*s|\n", INT_MAX, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%.*s|\n", INT_MIN, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%.*s|\n", INT_MIN, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%.*s|\n", INT_MAX + 1, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%.*s|\n", INT_MAX + 1, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%.*s|\n", INT_MIN - 1, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%.*s|\n", INT_MIN - 1, "1234567890");
    printf("k = %d\n", k);

    
    
    
    printf("%s\n", "---aste as both---");
    k = printf("|%*.*s|\n", 20, 0, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%*.*s|\n", 20, 0, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%*.*s|\n", 20, 1, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%*.*s|\n", 20, 1, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%*.*s|\n", 20, 10, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%*.*s|\n", 20, 10, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%*.*s|\n", 20, 20, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%*.*s|\n", 20, 20, "1234567890");
    printf("k = %d\n", k);

    printf("*.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.*\n");

    k = printf("|%*.*s|\n", -20, -1, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%*.*s|\n", -20, -1, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%*.*s|\n", -20, -10, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%*.*s|\n", -20, -10, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%*.*s|\n", -20, -20, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%*.*s|\n", -20, -20, "1234567890");
    printf("k = %d\n", k);

    printf("*.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.*\n");

    k = printf("|%*.*s|\n", -20, INT_MAX, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%*.*s|\n", -20, INT_MAX, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%*.*s|\n", -20, INT_MIN, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%*.*s|\n", -20, INT_MIN, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%*.*s|\n", -20, INT_MAX + 1, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%*.*s|\n", -20, INT_MAX + 1, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%*.*s|\n", -20, INT_MIN - 1, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%*.*s|\n", -20, INT_MIN - 1, "1234567890");
    printf("k = %d\n", k);
    
    printf("*.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.*\n");
    
    
    printf("%s\n", "---aste as both with '-'---");
    k = printf("|%-*.*s|\n", 20, 0, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%-*.*s|\n", 20, 0, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%-*.*s|\n", 20, 1, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%-*.*s|\n", 20, 1, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%-*.*s|\n", 20, 10, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%-*.*s|\n", 20, 10, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%-*.*s|\n", 20, 20, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%-*.*s|\n", 20, 20, "1234567890");
    printf("k = %d\n", k);

    printf("*.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.*\n");

    k = printf("|%-*.*s|\n", -20, -1, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%-*.*s|\n", -20, -1, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%-*.*s|\n", -20, -10, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%-*.*s|\n", -20, -10, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%-*.*s|\n", -20, -20, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%-*.*s|\n", -20, -20, "1234567890");
    printf("k = %d\n", k);

    printf("*.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.*\n");

    k = printf("|%-*.*s|\n", -20, INT_MAX, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%-*.*s|\n", -20, INT_MAX, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%-*.*s|\n", -20, INT_MIN, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%-*.*s|\n", -20, INT_MIN, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%-*.*s|\n", -20, INT_MAX + 1, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%-*.*s|\n", -20, INT_MAX + 1, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%-*.*s|\n", -20, INT_MIN - 1, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%-*.*s|\n", -20, INT_MIN - 1, "1234567890");
    printf("k = %d\n", k);

    printf("*.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.*\n");


    
    printf("%s\n", "---aste as both with '0'---");
    k = printf("|%0*.*s|\n", 20, 0, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%0*.*s|\n", 20, 0, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%0*.*s|\n", 20, 1, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%0*.*s|\n", 20, 1, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%0*.*s|\n", 20, 10, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%0*.*s|\n", 20, 10, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%0*.*s|\n", 20, 20, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%0*.*s|\n", 20, 20, "1234567890");
    printf("k = %d\n", k);

    printf("*.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.*\n");

    k = printf("|%0*.*s|\n", -20, -1, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%0*.*s|\n", -20, -1, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%0*.*s|\n", -20, -10, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%0*.*s|\n", -20, -10, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%0*.*s|\n", -20, -20, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%0*.*s|\n", -20, -20, "1234567890");
    printf("k = %d\n", k);

    printf("*.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.*\n");

    k = printf("|%0*.*s|\n", -20, INT_MAX, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%0*.*s|\n", -20, INT_MAX, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%0*.*s|\n", -20, INT_MIN, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%0*.*s|\n", -20, INT_MIN, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%0*.*s|\n", -20, INT_MAX + 1, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%0*.*s|\n", -20, INT_MAX + 1, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%0*.*s|\n", -20, INT_MIN - 1, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%0*.*s|\n", -20, INT_MIN - 1, "1234567890");
    printf("k = %d\n", k);

    printf("*.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.**.*\n");
    
    
    printf("%s\n", "---Get Crazy---");



    k = printf("|%c, %s, %d, %i, %u, %x, %X, %p|\n", '1', "abcde", 0, INT_MIN, INT_MAX, 0, INT_MAX, NULL);
    printf("k = %d\n", k);
    k = ft_printf("|%c, %s, %d, %i, %u, %x, %X, %p|\n", '1', "abcde", 0, INT_MIN, INT_MAX, 0, INT_MAX, NULL);
    printf("k = %d\n", k);

    k = printf("|%-c, %-s, %-d, %-i, %-u, %-x, %-X, %-p|\n", '1', "abcde", 0, INT_MIN, INT_MAX, 0, INT_MAX, NULL);
    printf("k = %-d\n", k);
    k = ft_printf("|%-c, %-s, %-d, %-i, %-u, %-x, %-X, %-p|\n", '1', "abcde", 0, INT_MIN, INT_MAX, 0, INT_MAX, NULL);
    printf("k = %-d\n", k);

    k = printf("|%0c, %0s, %0d, %0i, %0u, %0x, %0X, %0p|\n", '1', "abcde", 0, INT_MIN, INT_MAX, 0, INT_MAX, NULL);
    printf("k = %0d\n", k);
    k = ft_printf("|%0c, %0s, %0d, %0i, %0u, %0x, %0X, %0p|\n", '1', "abcde", 0, INT_MIN, INT_MAX, 0, INT_MAX, NULL);
    printf("k = %0d\n", k);

    k = printf("|%15c, %15s, %15d, %15i, %15u, %15x, %15X, %15p|\n", '1', "abcde", 0, INT_MIN, INT_MAX, 0, INT_MAX, NULL);
    printf("k = %15d\n", k);
    k = ft_printf("|%15c, %15s, %15d, %15i, %15u, %15x, %15X, %15p|\n", '1', "abcde", 0, INT_MIN, INT_MAX, 0, INT_MAX, NULL);
    printf("k = %15d\n", k);

    k = printf("|%.15c, %.15s, %.15d, %.15i, %.15u, %.15x, %.15X, %.15p|\n", '1', "abcde", 0, INT_MIN, INT_MAX, 0, INT_MAX, NULL);
    printf("k = %.15d\n", k);
    k = ft_printf("|%.15c, %.15s, %.15d, %.15i, %.15u, %.15x, %.15X, %.15p|\n", '1', "abcde", 0, INT_MIN, INT_MAX, 0, INT_MAX, NULL);
    printf("k = %.15d\n", k);

    k = printf("|%20.5c, %20.5s, %20.5d, %20.5i, %20.5u, %20.5x, %20.5X, %20.5p|\n", '1', "abcde", 0, INT_MIN, INT_MAX, 0, INT_MAX, NULL);
    printf("k = %20.5d\n", k);
    k = ft_printf("|%20.5c, %20.5s, %20.5d, %20.5i, %20.5u, %20.5x, %20.5X, %20.5p|\n", '1', "abcde", 0, INT_MIN, INT_MAX, 0, INT_MAX, NULL);
    printf("k = %20.5d\n", k);

    k = printf("|%-20.5c, %-20.5s, %-20.5d, %-20.5i, %-20.5u, %-20.5x, %-20.5X, %-20.5p|\n", '1', "abcde", 0, INT_MIN, INT_MAX, 0, INT_MAX, NULL);
    printf("k = %-20.5d\n", k);
    k = ft_printf("|%-20.5c, %-20.5s, %-20.5d, %-20.5i, %-20.5u, %-20.5x, %-20.5X, %-20.5p|\n", '1', "abcde", 0, INT_MIN, INT_MAX, 0, INT_MAX, NULL);
    printf("k = %-20.5d\n", k);

    k = printf("|%020.5c, %020.5s, %020.5d, %020.5i, %020.5u, %020.5x, %020.5X, %020.5p|\n", '1', "abcde", 0, INT_MIN, INT_MAX, 0, INT_MAX, NULL);
    printf("k = %020.5d\n", k);
    k = ft_printf("|%020.5c, %020.5s, %020.5d, %020.5i, %020.5u, %020.5x, %020.5X, %020.5p|\n", '1', "abcde", 0, INT_MIN, INT_MAX, 0, INT_MAX, NULL);
    printf("k = %020.5d\n", k);

    
    
    printf("%s\n", "---duplicate flags---");



    k = printf("|%..0s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%..0s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%..1s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%..1s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%..2s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%..2s|\n", "1234567890");
    printf("k = %d\n", k);

    printf("..................\n");

    k = printf("|%..10s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%..10s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%..20s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%..20s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%..30s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%..30s|\n", "1234567890");
    printf("k = %d\n", k);
    
    printf("..................\n");

    k = printf("|%--0s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%--0s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%--1s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%--1s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%--2s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%--2s|\n", "1234567890");
    printf("k = %d\n", k);

    printf("..................\n");

    k = printf("|%--10s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%--10s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%--20s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%--20s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%--30s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%--30s|\n", "1234567890");
    printf("k = %d\n", k);
    
    printf("..................\n");

    k = printf("|%000s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%000s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%001s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%001s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%002s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%002s|\n", "1234567890");
    printf("k = %d\n", k);

    printf("..................\n");

    k = printf("|%0010s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%0010s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%0020s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%0020s|\n", "1234567890");
    printf("k = %d\n", k);
    k = printf("|%0030s|\n", "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%0030s|\n", "1234567890");
    printf("k = %d\n", k);
    
    printf("..................\n");

    k = printf("|%**0s|\n", 1, 10, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%**0s|\n", 1, 10, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%**1s|\n", 10, 1, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%**1s|\n", 10, 1, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%**2s|\n", 100, -10, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%**2s|\n", 100, -10, "1234567890");
    printf("k = %d\n", k);

    printf("..................\n");

    k = printf("|%**10s|\n", -1, -10, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%**10s|\n", -1, -10, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%**20s|\n", -10, -1, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%**20s|\n", -10, -1, "1234567890");
    printf("k = %d\n", k);
    k = printf("|%**30s|\n", -100, -10, "1234567890");
    printf("k = %d\n", k);
    k = ft_printf("|%**30s|\n", -100, -10, "1234567890");
    printf("k = %d\n", k);


}
