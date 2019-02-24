#include <bits/stdc++.h>
using namespace std;

int hashTABLE(char *num, int h){
	int soma = 0;
	for(int i = 0; num[i] != '\0'; i++){
		soma += h + i + num[i] - 65;
	}

	return soma;

}


int main(){

	char num[200];
	int n, l, t, soma; 
	cin >> n;

	for(int j = 0; j < n; j++){
		soma = 0;
		scanf("%d\n", &l);
		for(int h = 0; h < l; h++){
			gets(num);
			soma = soma + hashTABLE(num, h);
		}

		cout << soma << endl;
	}



	return 0;
}