#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main (void) {
	char c = 'A';
	pid_t pid = fork();
	if (pid < 0){
		printf("\n Erro ao executar o fork \n");
		exit(1);
	}
	if (pid == 0){//Processo Filho
		c = 'B';
	}
	printf("\nPID: %d. Letra: %c. \n",getpid(),c);
	return 0;
}
