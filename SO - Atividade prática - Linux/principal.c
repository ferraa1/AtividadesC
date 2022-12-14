#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main (void) {
	printf("\nPP %d - Invocando o segundo programa: \n", getpid());
	//execv("secundario", NULL);
	system("./secundario");
	printf("\nIsto será impresso?\n");
	return 0;
}
