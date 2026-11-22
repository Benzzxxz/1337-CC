// #include "get_next_line_bonus.h"
#include "get_next_line.h"

int main()
{
	int fd = open("test.txt", O_CREAT | O_RDWR);
	int fd2 = open("README.md", O_RDONLY);

	printf("fd : %d\nfd2 : %d", fd, fd2);
	perror("open");
	// printf("%s\n", get_next_line(fd));
	// printf("%s", get_next_line(fd2));
}