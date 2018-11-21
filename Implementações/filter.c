#include <stdio.h>
#include <stdlib.h>

// ALGO ESTA ERRADO


int menu(int x){

	int op;
	printf(" \n0 - Sair\n 1 - Adicionar mais numeros? Quantos?\n 2 - Filtrar pares\n 3 - Filtrar impares\n 4 - Listar numeros\n");
	scanf("%d", &op);
	return op;
}

void realocar(int *array, int *n, int num){
	
	array = (int *) realloc(array, sizeof(int) * ( (*n) + num) );

	printf("Adicione mais %d numeros: \n", num);
	for(int i = (*n); i < (*n) + num; i++){
		scanf("%d", &array[i]);
	}

	(*n) = (*n) + num;
}

int pares(int x){
	if( x%2 == 0) return 1;
	return 0;
}

int impares(int x){
	if( x%2 == 0) return 0;
	return 1;
}

void filter(int (*f)(int x), int *array, int *n){

	int i, j;

	for(i = 0, j = 0; i < (*n); i++){
		if( f( array[i]) ) array[j] = array[i], j++;
	}

	array = (int *) realloc(array, sizeof(int) * (j + 1) );
	*n = j + 1;
}

void list(int *array, int n){
	for(int i = 0; i < n; i++) printf("%d\n", array[i]);
}

void main(){
	
	int n;

	printf("Quantos numeros? "); scanf("%d", &n); printf("\n");

	int *array =  malloc(sizeof(int) * n);
	int num;

	printf("Adicione os numeros: \n");

	for(int i = 0; i < n; i++){
		scanf("%d", &array[i]);
	}

	int opcoes;
	do{

		opcoes = menu(1);

		switch(opcoes){
			case 0:
				break;
			case 1:
				scanf("%d", &num);
				realocar(array, &n, num);
				break;
			case 2:
				filter(pares, array, &n);
				break;
			case 3:
				filter(impares, array, &n);
				break;
			case 4:
				list(array, n);
				break;
		}


	} while(opcoes);


}