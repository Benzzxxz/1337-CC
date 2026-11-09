#include "ft_printf.h"
#include <stdio.h>
#include <fcntl.h>


int main(void)
{
    close(1);
    setvbuf(stdout, NULL, _IONBF, 0);
    int x = ft_printf("hello");
    int y = printf("hello");
    if (x == y)
        fprintf(stderr, "x = y = %d, ghna dwz lik lproji mabrok\n", x);
    else
        fprintf(stderr, "x = %d but y = %d, ghan rod lik lproji a 3ami\n", x, y);
}