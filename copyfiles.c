#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	if (fork() == 0 ) {
		execl("copy", "copy", argv[0], argv[1], 0);
	}
	wait((int*)0);
	printf("\nCopy done\n");	
	return 0;
}
