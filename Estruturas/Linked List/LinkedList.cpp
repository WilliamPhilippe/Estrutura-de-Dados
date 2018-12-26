#include <bits/stdc++.h>
using namespace std;

struct node
{
	int i;
	node *next;
};

node *CreatList(){

	node *new_pointer = (node *) malloc(sizeof(node));
	if(new_pointer == NULL) cout << "No memory" << endl;
	new_pointer->next = NULL;
	return new_pointer;

}

void AddItem(node *list, int x){

	node *new_pointer = (node *) malloc(sizeof(node));
	new_pointer->i = x;
	new_pointer->next = NULL;

	node *pointer = list;

	while(pointer->next != NULL){
		pointer = pointer->next;
	}

	pointer->next = new_pointer;
}

void PrintList(node *list){
	node *pointer = list->next;
	while(1){
		cout << pointer->i << endl;
		if(pointer->next == NULL) return;
		else pointer = pointer->next;
	}
}

node *SearchList(node *list, int x){
	node *pointer = list;

	while(1){
		if(pointer->i == x) return pointer;
		else if(pointer->next == NULL) return NULL;
		else pointer = pointer->next;
	}
}

void RemoveItem(node *list, int x){

	node *pointer = list;

	while(1){

		if(pointer->next->i == x){
			//encontrado
			pointer->next = pointer->next->next;
			cout << "Removido.\n\n";
			return;
		}
		else if(pointer->next->next == NULL){
			//nao encontrado
			cout << "Nao encontrado.\n\n";
			return;
		}
		else{
			pointer = pointer->next;
		}
	}
}

int main(){

	node *list = CreatList();
	
	while(1){
		int comando, x;
		cout << "1- PrintList\n2- AddItem\n3- SearchList\n4- RemoveItem\n0- Exit\n";
		cout << "Comando: "; cin >> comando;

		if(comando == 0) return 0;
		else if(comando == 1){
			if(list->next == NULL){
				 cout << "Lista Vazia\n\n"; 
				 continue;
			}
			PrintList(list);
			cout << endl;
		}
		else if(comando == 2){

			cout << "Digite o item: "; cin >> x;
			AddItem(list, x);
			cout << "Sucess!\n\n";

		}
		else if(comando == 3){

			cout << "Digite o item: "; cin >> x;
			node *pointer = SearchList(list, x);
			if(pointer == NULL) cout << "Nao encontrado.\n\n";
			else cout << "Existe.\n\n";

		}
		else if(comando == 4){
			cout << "Digite o item: "; cin >> x;
			RemoveItem(list, x);

		}
		else cout << "Comando Invalido\n\n";

	}

	return 0;
}