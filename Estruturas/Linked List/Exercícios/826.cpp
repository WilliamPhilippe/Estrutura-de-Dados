#include <bits/stdc++.h>
using namespace std;

struct node
{
	char bin;
	int pos;
	node *next, *previous;
};

struct SetLista
{
	int posIni, posFim, posTempIni, posTempFim, tam, tamTemp;
	node *head, *back;
};

SetLista * SetarLista(){
	SetLista * lista = (SetLista *) malloc(sizeof(SetLista));
	lista->head = NULL; lista->back = NULL;
	lista->posIni = lista->posFim = lista->posTempFim = lista->posTempIni = 0;
	lista->tam = lista->tamTemp = 0;

	return lista;
}

void AddItem(SetLista *lista, char cr){

	node *newNode = (node *) malloc(sizeof(node));
	newNode->bin = cr;

	if(lista->head == NULL){
		lista->head = newNode;
		lista->back = newNode;
		newNode->next = NULL;
		newNode->previous = NULL;
		newNode->pos = 0;

		if(newNode->bin == '0') lista->tam = lista->tamTemp = 1;
	}
	else{
		newNode->next = NULL;
		newNode->previous = lista->back;
		lista->back->next = newNode;
		lista->back = newNode;
		newNode->pos = newNode->previous->pos + 1;

		if(newNode->bin = '0'){
			if(newNode->previous->bin = '1'){

			}
			else{

			}
		}
		else{
			if(lista->tamTemp > lista->tam){
				lista->posIni = lista->posTempIni;
				lista->posFim = lista->posTempFim;
				lista->tam = lista->tamTemp;
				lista->tamTemp = 0;
			}
			else lista->tamTemp = 0;
		}
	}


}



int main(){

	char cr[10000];
	SetLista *lista = SetarLista();


	while(1){
		//gets(cr);
		if(strlen(cr) <= 1) break;

		for(int i = 0; cr[i] != '\n'; i++) AddItem(lista, cr[i]);
		AddItem(lista, '1');
		cout << lista->posIni << " " << lista->posFim << endl;
	}

	return 0;	
}
