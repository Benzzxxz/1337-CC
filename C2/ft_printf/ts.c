#include "ft_printf.h"
#include <stdio.h>

int seum(int j, ...)
{
	va_list	v;
	va_start(v, j);
	unsigned int *p = v->reg_save_area;
	printf("%u", *(p));
	return (0);
}

int main()
{
	seum(5, 1, 2, 3, 4, 5);
}

