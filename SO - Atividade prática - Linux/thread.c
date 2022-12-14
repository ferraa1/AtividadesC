#include <pthread.h>
#include <stdio.h>
void *executor(); //Protótipo da função thread
int main(int argc, char * argv[]) {
	if (argc != 3) {
		printf("Uso: ./thread <inteiro 1> <inteiro 2>\n");
		printf("Onde: <inteiro 1> = N de threads\n");
		printf("Onde: <inteiro 2> = duração da contagem\n");
		return -1;
	}
	int nthread = atoi(argv[1]);
	int cont = atoi(argv[2]);
	if (nthread <= 0 || cont <= 0) {
		printf("Valores deve ser > 0\n");
		return -1;
	}
	pthread_t tid[nthread]; //Conjunto de TIDs - cada thread
	pthread_attr_t attr[nthread]; //Atributos das threads
	int ta;
	for (ta = 0; ta < nthread; ta++) {
		//Inicia uma estrutura para thread padrão
		pthread_attr_init(&attr[ta]);
		//Inicia a nova thread
		pthread_create(&tid[ta], &attr[ta], executor, &cont);
	}
	for (ta = 0; ta < nthread; ta++) {
		//Aguarda pelas threads
		//Importante: este laço é separado do anterior!
		pthread_join(tid[ta], NULL);
	}
	return 0;
} //Fim do main
//A função da thread
void *executor(void *parametro) {
	int i, superior = (int) *(int*)parametro;
	pthread_t meuTid = pthread_self();
	for (i = 1; i <= superior; i++) {
		printf("Thread %x: %d\n",meuTid, i);
		usleep(20);
	}
	pthread_exit(0);
}
