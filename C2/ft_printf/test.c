#include <stdarg.h>
#include <stdio.h>

static void show(const char *label, va_list v)
{
	printf("%-22s gp=%-3u fp=%-3u reg_save=%p overflow=%p\n",
		label, v->gp_offset, v->fp_offset,
		(void *)v->reg_save_area, (void *)v->overflow_arg_area);
}

int sum(int i, double d, ...)
{
	va_list	v;
	int		a;
	double	x;

	(void)i;
	(void)d;
	va_start(v, d);
	show("after va_start", v);

	a = va_arg(v, int);
	printf("int    -> %d\n", a);
	show("after int #1", v);

	a = va_arg(v, int);
	printf("int    -> %d\n", a);
	show("after int #2", v);

	x = va_arg(v, double);
	printf("double -> %f\n", x);
	show("after double #1", v);

	a = va_arg(v, int);
	a = va_arg(v, int);
	a = va_arg(v, int);
	printf("int #5 -> %d\n", a);
	show("after int #5", v);

	a = va_arg(v, int);
	printf("int #6 -> %d\n", a);
	show("after int #6 (stack?)", v);

	a = va_arg(v, int);
	printf("int #7 -> %d\n", a);
	show("after int #7", v);

	va_end(v);
	return (0);
}

int main(void)
{
	sum(13, 1.5, 1, 2, 3, 4, 5, 6, 7, 2.5, 3.5);
	return (0);
}