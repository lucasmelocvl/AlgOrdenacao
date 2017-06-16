
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/*
*	Lucas Melo e Mayko de Oliveira
*
*	Programa de ordenação InsertionSort
*	Programa de ordenação InsertionSort
*	Insertion Sort ordena o vetor utilizando um sub-vetores ordenados localizado em
*	seu inicio, e a cada passo, acrescenta no sub-vetor mais
*	um elemento, até atingir o último elemento do arranjo fazendo assim
*	com que ele se torne ordenado.
*
*/
void insertionSort(int original[], int length) {
	int i, j, atual;

	for (i = 1; i < length; i++) {
		atual = original[i];
		j = i - 1;

		while ((j >= 0) && (atual < original[j])) {
			original[j + 1] = original[j];
			j = j - 1;
		}

		original[j + 1] = atual;
	}

}

/*
*	Função de inicialização
*	argv[0] - Nome do arquivo atual (padrão, não precisa explicitar)
*	argv[1] - Nome do arquivo de entrada
*/
int main(int argc, char *argv[]){

	//Verifica se foi passado um nome de arquivo como parâmetro
	if(argv[1] == NULL){
		printf("\nFavor informar o nome do arquivo como primeiro argumento.\n");
		exit(1);
	}

    FILE* fp;
    int* vetor;
    int tam, j;
    clock_t ini, fim;
    double tempo;

	//Abre o arquivo que foi passado por parâmetro
	fp = fopen(argv[1],"r");

	//Verifica se foi possível abrir o arquivo
	if(fp == NULL){
		printf("\nNome do arquivo '%s' inválido.\nVerifique se o arquivo existe na mesma pasta do executável.\n", argv[1]);
		exit(1);
	}

	tam = 0;

	char ch;

	int aux = 0;

	//Conta a quantidade de espaços no arquivo, o que define a quantidade de números -1
	while( (fscanf(fp, "%d", &aux)) != EOF ){
        tam++;
	}
	
	//printf("%d \n", tam);


	//Fecha o arquivo
	fclose(fp);

	//Cria um vetor de tamanho dinâmico
	vetor = (int*)malloc(tam*sizeof(int));

	//Abre o arquivo que foi passado como argumento
	fp = fopen(argv[1],"r");

	//Lê os dados do arquivo e insere no vetor
	for(j=0; j < tam; j++){

		fscanf(fp, "%d ", &vetor[j]);

	}

	//Fecha o arquivo
	fclose(fp);

	//Cálculo do tempo em Milisegundos
	ini = clock();
	insertionSort(vetor, tam);
	fim = clock();
	tempo = ( (double) (fim - ini) ) / CLOCKS_PER_SEC;

	//Imprime o vetor ordenado
	for(j=0; j < tam; j++){

		printf("%d ", vetor[j]);

	}

	//Imprime o tempo de execução do insertion
	printf("\n%5.2lfms\n",tempo);

	//Libera o vetor
	free(vetor);

}
