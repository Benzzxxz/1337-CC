// #include "get_next_line_bonus.h"
#include "get_next_line.h"

int main()
{
	int fd = open("test.txt", O_CREAT | O_RDWR);
	int fd2 = open("README.md", O_RDONLY);
	write(fd, "benzz", 5);
	printf("fd : %d\nfd2 : %d\n", fd, fd2);
	// printf("%s\n", get_next_line(fd));
	lseek(fd, 0, SEEK_SET);
	printf("%s", get_next_line(fd));
}