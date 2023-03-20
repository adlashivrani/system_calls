#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define SIZE 100

void copy(int, int);
char buff[SIZE];

int main(int argc, char *argv[])
{
	int fd1;
	int fd2;
	if (argc != 3) {
		printf("\nNeed 2 arguments\n");
		exit(1);
	}
	if ((fd1 = open(argv[1], O_RDONLY)) == -1 ) { //opening existing file
		printf("\nfd1 not opened\n");
		exit(1);
	}
	if ((fd2 = creat(argv[2], 0666)) == -1) { //creating new file
		printf("\nFd2 not created\n");
		exit(1);
	}
	copy(fd1, fd2);
	return 0;
}

void copy(int fd1, int fd2)
{
	int count;
	while ((count = read(fd1, buff, SIZE)) > 0) {
		write (fd2, buff, count);
	}
}
	
