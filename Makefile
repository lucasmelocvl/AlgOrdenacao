#Makefile
#Lucas Melo e Mayko de Oliveira
#
#Para compilar basta digitar no terminal: make [-NomeDoTarget-]
#
#

all: 
	gcc insertionsort.c -o insertionsort
	gcc mergesort.c -o mergesort
	gcc heapsort.c -o heapsort

#Insertion Sort
#insertionsort: insertionsort.o
#	gcc insertionsort.c -o insertionsort.o

#Insertion Sort
#mergesort: mergesort.o
#	gcc mergesort.c -o mergesort.o

#Insertion Sort
#heapsort: heapsort.o
#	gcc heapsort.c -o heapsort.o

clean:
	rm *.o
