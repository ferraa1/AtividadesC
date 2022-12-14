#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int valor = 5;
int main() {
	pid_t pid = fork();
	printf("\nPID: %d\n",getpid());
	printf("\nPIDT: %d\n",pid);
	if (pid == 0) {
		valor += 15;
		printf("\n%d PRINT: Valor alterado: %d\n",getpid(),valor);
	} else if (pid > 0) {
		wait();
		printf("\n%d PRINT: Valor: %d\n",getpid(),valor);//linha A
	}
	return 0;
}
