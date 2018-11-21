#include <stdio.h>
#include <stdlib.h>

int square(int x){
	return x*x;
}

int fat(int x){
	if(x < 2) return 1;
	else return x*fat(x - 1);
}

void map(int (*fuction)(int x), int *array, int *result, int ind){
	if(ind > 4) return;
	result[ind] = fuction(array[ind]);
	map(fuction, array, result, ind + 1);
}

void main(){

	char input;
	scanf("%c", &input);

	int array[5], result[5];

	int i = 0;

	for(i = 0; i < 5; i++) scanf("%d", &array[i]);

	if(input == 'f'){
		map(fat, array, result, 0);
		for(i = 0; i < 5; i++) printf("%d\n", result[i]);
	}
	else{
		map(square, array, result, 0);
		for(i = 0; i < 5; i++) printf("%d\n", result[i]);
	}


}