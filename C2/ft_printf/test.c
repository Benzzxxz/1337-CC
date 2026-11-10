#include <stdarg.h>
#include <stdio.h>

#include <stdarg.h>
#include <stdio.h>

int sum(int i, ...)
{
    va_list v;
    va_start(v, i);

    int n = 0;

	unsigned long *t = v->overflow_arg_area;
	unsigned long *y = v->reg_save_area;
	printf("%p\n", y);
	printf("%ld", *y);
	printf("%ld", *(t));
    va_end(v);
    return (0);
}

int main(void)
{
    sum(9, 1, 2, 3, 4, 5, 6, 7, 8, 9);
}
typedef struct {
unsigned int gp_offset; //* generel purpose registers
unsigned int fp_offset; //? Vector register
void *overflow_arg_area;
void *reg_save_area;
} va_list[1];