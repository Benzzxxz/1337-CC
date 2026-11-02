#include <stdarg.h>
#include <stdio.h>

void print(int j, ...)
{
	va_list	i;
	va_start(i, j);
	printf("%d", va_arg(i, int));
}
int main()
{
	print(1, 2, 3, 4, 5, 6);
}