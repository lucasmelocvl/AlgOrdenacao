#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/*
*	Lucas Melo e Mayko de Oliveira
*
*	Programa de ordena��o MergeSort
*	O vetor de elementos � divido em pares de elementos e ent�o os pares s�o
*	ordenados, depois s�o agrupados de dois em dois pares e ent�o os valores do
*	grupo s�o ordenados. O processo de agrupamento ocorre at� voltar ao tamanho do
*	vetor original e nesse ponto o vetor j� estar� ordenado.
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

	//Verifica se o piv� i � menor ou igual que o meio, e se o piv� j � menor ou igual ao tamanho maximo do vetor (maior)
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
*	Divide o vetor em pequenos subvetores (Divis�o)
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
*	Fun��o de inicializa��o
*	argv[0] - Nome do arquivo atual (padr�o, n�o precisa explicitar)
*	argv[1] - Nome do arquivo de entrada
*/
int main(int argc, char *argv[]){

	//Verifica se foi passado um nome de arquivo como par�metro
	if(argv[1] == NULL){
		printf("\nFavor informar o nome do arquivo como primeiro argumento.\n");
		exit(1);
	}

    FILE* fp;
    int* vetor;
    int tam, j;
    clock_t ini, fim;
    double tempo;

	//Abre o arquivo que foi passado por par�metro
	fp = fopen(argv[1],"r");

	//Verifica se foi poss�vel abrir o arquivo
	if(fp == NULL){
		printf("\nNome do arquivo '%s' inv�lido.\nVerifique se o arquivo existe na mesma pasta do execut�vel.\n", argv[1]);
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

	//Cria um vetor de tamanho din�mico
	vetor = (int*)malloc(tam*sizeof(int));

	//Abre o arquivo que foi passado como argumento
	fp = fopen(argv[1],"r");

	//L� os dados do arquivo e insere no vetor
	for(j=0; j < tam; j++){

		fscanf(fp, "%d ", &vetor[j]);

	}
	//Fecha o arquivo
	fclose(fp);

	//C�lculo do tempo em Milisegundos
	ini = clock();
	mergeSort(vetor, 0, tam-1);
	fim = clock();
	tempo = ( (double) (fim - ini) ) / CLOCKS_PER_SEC;

	//Imprime o vetor ordenado
	for(j=0; j < tam; j++){

		printf("%d ", vetor[j]);

	}

	//Imprime o tempo de execu��o do merge
	printf("\n%5.2lfms\n",tempo);

	//Libera o vetor
	free(vetor);

}
