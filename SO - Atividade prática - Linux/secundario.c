#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main (void) {
	printf("\n %d - Olá do programa secundário!\n",getpid());
	return 0;
}
