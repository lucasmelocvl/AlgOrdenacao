#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/*
*	Lucas Melo e Mayko de Oliveira
*
*	Programa de ordenação MergeSort
*	O vetor de elementos é divido em pares de elementos e então os pares são
*	ordenados, depois são agrupados de dois em dois pares e então os valores do
*	grupo são ordenados. O processo de agrupamento ocorre até voltar ao tamanho do
*	vetor original e nesse ponto o vetor já estará ordenado.
*
*/

/*
*	Realiza o merge (Conquista)
*/
void merge(int a[], int menor, int maior, int meio){
	int i, j, k, c[maior];
	i=menor;
	j=meio+1;
	k=menor;

	//Verifica se o pivô i é menor ou igual que o meio, e se o pivô j é menor ou igual ao tamanho maximo do vetor (maior)
	while((i<=meio)&&(j<=maior)){
		if(a[i]<a[j]){
			c[k]=a[i];
			k++;
			i++;
		}else{
			c[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=meio){
		c[k]=a[i];
		k++;
		i++;
	}
	while(j<=maior){
		c[k]=a[j];
		k++;
		j++;
	}
	for(i=menor;i<k;i++){
		a[i]=c[i];
	}
}

/*
*	Merge Sort
*	Divide o vetor em pequenos subvetores (Divisão)
*/
void mergeSort(int a[], int menor, int maior){
	int meio;
	if(menor<maior){
		meio=(menor+maior)/2;
		mergeSort(a,menor,meio);
		mergeSort(a,meio+1,maior);
		merge(a,menor,maior,meio);
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

	int aux = 0;

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
	mergeSort(vetor, 0, tam-1);
	fim = clock();
	tempo = ( (double) (fim - ini) ) / CLOCKS_PER_SEC;

	//Imprime o vetor ordenado
	for(j=0; j < tam; j++){

		printf("%d ", vetor[j]);

	}

	//Imprime o tempo de execução do merge
	printf("\n%5.2lfms\n",tempo);

	//Libera o vetor
	free(vetor);

}
