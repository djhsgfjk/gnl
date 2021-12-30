#include <stdio.h>

#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	char *s;
	int fd;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		printf("fd fault\n");
	s = get_next_line(fd);
	close(fd);
	printf("%s", s);
	return 0;
}
