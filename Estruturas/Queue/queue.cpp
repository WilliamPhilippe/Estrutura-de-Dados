#include <bits/stdc++.h>
using namespace std;

struct node
{
	int value;
	node *next, *previous;
};

struct SetQueue
{
	node *head;
	node *back;
	int size;
};

SetQueue *CreateQueue(){
	SetQueue *newpointer = (SetQueue *) malloc(sizeof(SetQueue));
	newpointer->head = NULL;
	newpointer->back = NULL;
	newpointer->size = 0;
	return newpointer;
}

int pushItem( SetQueue *fila, int x, int command ){
	node *newpointer = (node *) malloc(sizeof(node));
	if(newpointer == NULL) return 0;
	newpointer->value = x;

	if(fila->head == NULL){
		newpointer->next == NULL;
		newpointer->previous = NULL;
		fila->head = newpointer;
		fila->back = newpointer;
	}
	else if(command == 1){
		newpointer->previous == NULL;
		newpointer->next = fila->head;
		fila->head->previous = newpointer;
		fila->head = newpointer;
	}
	else if(command == 2){
		newpointer->next = NULL;
		newpointer->previous = fila->back;
		fila->back->next = newpointer;
		fila->back = newpointer;
	}

	fila->size ++;

	return 1;
}

int menu(SetQueue *fila){

	int command, x;
	cout << "1 - Push item.\n2 - Get item\n3 - Is empty?\n4 - Print Queue\n 5 - Size.\n0 - Exit\n";
	cout << "Command: "; cin >> command;

	if(command == 0) return 0;
	else if(command == 1){
		cout << "1 - Head.\n2 - Back.\n";
		cout << "Command: "; cin >> command;
		cout << "Insert item: "; cin >> x;
		if( pushItem(fila, x, command) ) cout << "Sucess.\n\n";
		else cout << "No memmory.\n\n";
	}
	else if(command == 2){

	}
	else if(command == 3){

	}
	else if(command == 4){

	}
	else if(command == 5){

	}
	else cout << "Invalid Command.\n\n";

	return 1;
}

int main(){

	SetQueue *fila = CreateQueue();

	while(menu(fila));

	return 0;
}