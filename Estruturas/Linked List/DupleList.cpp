#include <bits/stdc++.h>
using namespace std;

struct node
{
	int value;
	node *previous;
	node *next;
};

void CreatList(node *head, node *back){
	head = (node *) malloc(sizeof(node));
	back = (node *) malloc(sizeof(node));

	head->previous = NULL;
	head->next = back;
	back->previous = head;
	back->next = NULL;
}

int AddItem(node *head, node *back, int x, int comando){
	node *new_pointer = (node *) malloc(sizeof(node));
	if(new_pointer == NULL) return 0;
	new_pointer->value = x;

	if(comando == 1){
		new_pointer->next = head->next;
		new_pointer->next->previous = new_pointer;
		new_pointer->previous = head;
		head->next = new_pointer;
	}
	else if(comando == 2){
		new_pointer->next = back;
		new_pointer->previous = back->previous;
		new_pointer->previous->next = new_pointer;
		back->previous = new_pointer;
	}

	return 1;
}

void PrintList(node *head, node *back){
	node *pointer = head->next;
	while(pointer->next != NULL){
		cout << pointer->value << endl;
	}
}

int main(){

	node *head; node *back;
	CreatList(head, back);

	while(1){
		int comando, x;
		cout << "1- PrintList\n2- AddItem\n3- SearchList\n4- RemoveItem\n0- Exit\n";
		cout << "Comando: "; cin >> comando;

		if(comando == 0) return 0;
		else if(comando == 1){
				
			if(head->next->next == NULL);

		}
		else if(comando == 2){
			
			cout << "1- Inicio\n2- Fim\nComando: "; cin >> comando;
			cout << "Digite o item: "; cin >> x;
			int test = AddItem(head, back, x, comando);
			cout << "Sucess\n\n";

		}
		else if(comando == 3){


		}
		else if(comando == 4){
			

		}
		else cout << "Comando Invalido\n\n";
	}


	return 0;
}