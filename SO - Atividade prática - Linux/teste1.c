#include <stdio.h>
#include <unistd.h>
int main()
{
	int cont = 0;
	cont = cont + 1;
	pid_t pid1 = fork();
	pid_t pid2 = fork();
	pid_t pid3 = fork();
	cont = cont + 1;
	printf("\n%d",cont);
	printf("\nPAI: %d",getpid());
	printf("\nFILHO1?: %d",pid1);
	printf("\nFILHO2?: %d",pid2);
	printf("\nFILHO3?: %d",pid3);
	return 0;
}
