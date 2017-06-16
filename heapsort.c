#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/*
*	Lucas Melo e Mayko Oliver
*
*	Programa de ordenação HeapSort
*	Utiliza uma estrutura de dados chamada heap (monte), para ordenar os elementos a
*	medida que os insere na estrutura. Assim, ao final das inserções, os elementos
*	podem ser sucessivamente removidos da raiz da heap, na ordem desejada, devendo
*	manter o maximo-heap.
*	Pode ser representada como uma árvore (uma árvore binária com propriedades
*	especiais) ou como um vetor. Para uma ordenação crescente, deve ser construído
*	uma heap mínima (o menor elemento fica na raiz). Para uma ordenação decrescente,
*	deve ser construído uma heap máxima (o maior elemento fica na raiz).
*
*/

void heapSort(int a[], int n) {

   int i = n / 2, pai, filho, t;

   for (;;) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n == 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
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

	//char ch;

	//Conta a quantidade de espaços no arquivo, o que define a quantidade de números
	/*while( (ch=fgetc(fp))!= EOF ){

		if(ch == ' '){
		  tam++;
		}

	}*/
    int aux = 0;

	while( (fscanf(fp, "%d", &aux)) != EOF ){
        //printf("%d ", aux);
        tam++;
		//if(ch == ' '){
		  //tam++;
		//}
	}

	//printf("%d", tam);

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
	heapSort(vetor, tam);
	fim = clock();
	tempo = ( (double) (fim - ini) ) / CLOCKS_PER_SEC;

	//Imprime o vetor ordenado
	for(j=0; j < tam; j++){

		printf("%d ", vetor[j]);

	}

	//Imprime o tempo de execução do heapsort
	printf("\n%5.2lfms\n",tempo);

	//Libera o vetor
	free(vetor);
}
