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

int getItem(SetQueue *fila, int command, int &x){

	if(fila->head == NULL || command < 1 || command > 2) return 0;

	command == 1 ? x = fila->head->value : x = fila->back->value;
	return 1;
}

int RemoveItem(SetQueue *fila, int command){

	if( fila->head == NULL ) return 0;
	node *current;

	if(fila->back == fila->head){
		current == fila->head;
		fila->head = NULL;
		fila->back = NULL;
		free(current);
	}
	else if(command == 1){
		current = fila->head;
		fila->head = current->next;
		fila->head->previous = NULL;
		free(current);
	}
	else if(command == 2){
		current = fila->back;
		fila->back = current->previous;
		fila->back->next = NULL;
		free(current);
	}
	else return 0;

	fila->size --;

	return 1;
}

int filaSize(SetQueue *fila){ return fila->size; }

int printQueue(SetQueue *fila){
	if(fila->head == NULL) return 0;
	
	node *current = fila->head;
	cout << endl;
	
	while(current != NULL){
		cout << current->value << endl;
		current = current->next;
	}

	return 1;
}

int menu(SetQueue *fila){

	int command, x;
	cout << "1 - Push item.\n2 - Get item\n3 - Remove item\n4 - Is empty?\n5 - Print Queue\n6 - Size.\n0 - Exit\n";
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
		cout << "1 - Head.\n2 - Back.\n";
		cout << "Command: "; cin >> command;
		
		if( getItem(fila, command, x) ) cout << "Elemment: " << x << endl << endl;
		else cout << "Empty queue or invalid command.\n\n";
	}
	else if(command == 3){
		cout << "1 - Head.\n2 - Back.\n";
		cout << "Command: "; cin >> command;
		if( RemoveItem(fila, command) ) cout << "Removed.\n\n";
		else cout << "Empty queue or invalid command.\n\n";
	}
	else if(command == 4){
		filaSize(fila) ? cout << "It is not empty.\n\n" : cout << "It is empty.\n\n";
	}
	else if(command == 5){
		if( !printQueue(fila) ) cout << "Empty queue.\n\n";
		else cout << endl;
	}
	else if(command == 6){
		cout << filaSize(fila) << endl << endl;
	}
	else cout << "Invalid Command.\n\n";

	return 1;
}

int main(){

	SetQueue *fila = CreateQueue();

	while(menu(fila));

	return 0;
}