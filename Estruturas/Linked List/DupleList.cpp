#include <bits/stdc++.h>
using namespace std;

struct node
{
	int value;
	node *previous;
	node *next;
};

struct SetList{
	node *head;
	node *back;
};

int AddItem(int x, int command, SetList *lista){
	node *newPointer = (node *) malloc(sizeof(node));
	if(newPointer == NULL) return 0;
	newPointer->value = x;

	if(lista->head == NULL){
		lista->head = newPointer;
		lista->back = newPointer;
		newPointer->previous = NULL;
		newPointer->next = NULL;
	}
	else if(command == 1){
		newPointer->next = lista->head;
		lista->head->previous = newPointer;
		lista->head = newPointer;
		newPointer->previous = NULL;
	}
	else if(command == 2){
		newPointer->next == NULL;
		newPointer->previous = lista->back;
		lista->back->next = newPointer;
		lista->back = newPointer;
	}

	return 1;
}

int RemoveItem(int x, SetList *lista){

	if(lista->head == NULL) return 0;
	node *currrent;

	if(lista->head == lista->back && lista->head->value == x){
		currrent = lista->head;
		lista->head = NULL;
		lista->back = NULL;
		free(currrent);
	}
	else if(lista->head->value == x){
		currrent = lista->head;
		lista->head = currrent->next;
		lista->head->previous == NULL;
		free(currrent);
	}
	else if(lista->back->value == x){
		currrent = lista->back;
		lista->back = currrent->previous;
		lista->back->next = NULL;
		free(currrent);
	}
	else{

		currrent = lista->head;
		while(currrent->value != x){
			currrent = currrent->next;
			if(currrent == NULL) return 0;
		}

		currrent->previous->next = currrent->next;
		currrent->next->previous = currrent->previous;
		free(currrent);

	}

	return 1;
}

int PrintList(SetList *lista){
	node *currrent = lista->head;
	if(lista->head == NULL || lista->back == NULL) return 0;

	while(currrent != NULL){
		cout << currrent->value << endl;
		currrent = currrent->next;
	}

	return 1;
}

node *SearchList(int x, SetList *lista){
	node *currrent = lista->head;

	while(1){ 
		if(currrent == NULL) return NULL; 
		if(currrent->value == x) return currrent; 
		currrent = currrent->next;
	}
}

int menu(SetList *lista){

	int command, x;
	cout << "1- PrintList\n2- AddItem\n3- SearchList\n4- RemoveItem\n0- Exit\n";
	cout << "Command: "; cin >> command;

	if(command == 0) return 0;
	else if(command == 1){
		cout << endl;
		if( !PrintList(lista) ) cout << "Empty List.\n\n";
		else cout << endl;
	}	
	else if(command == 2){
		cout << "1- Head\n2- Back\nCommand: "; cin >> command;
		cout << "Insert the item: "; cin >> x;
		int resp = AddItem(x, command, lista);
		if(resp) cout << "Sucess!\n\n";
		else cout << "No memory!\n\n";
	}
	else if(command == 3){
		cout << "Insert the item: "; cin >> x;
		node *found = SearchList(x, lista);
		if(found == NULL) cout << "Not found.\n\n";
		else cout << "There is is.\n\n";
	}
	else if(command == 4){
		cout << "Insert the item: "; cin >> x;
		if( RemoveItem(x, lista) ) cout << "Removed.\n\n";
		else cout << "Item not found.\n\n";
	}
	else cout << "Invalid command.\n\n";

	return 1;

}

int main(){

	SetList *lista = (SetList *) malloc(sizeof(SetList));
	lista->head = NULL;
	lista->back = NULL;

	while(menu(lista));

	return 0;
}
