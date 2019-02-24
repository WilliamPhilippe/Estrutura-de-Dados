#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 300

int matrix[300][300];

struct node{ int value; node *next, *previous; };
struct SetQueue{ node *head; node *back; int size; };

SetQueue *CreateQueue(){
	SetQueue *newpointer = (SetQueue *) malloc(sizeof(SetQueue));
	newpointer->head = NULL;
	newpointer->back = NULL;
	newpointer->size = 0;
	return newpointer;
}

void enqueueQ(SetQueue *fila, int x){
	node *newpointer = (node *) malloc(sizeof(node));
	newpointer->value = x;

	if(fila->head == NULL){
		newpointer->next == NULL;
		newpointer->previous = NULL;
		fila->head = newpointer;
		fila->back = newpointer;
	}
	else{
		newpointer->next = NULL;
		newpointer->previous = fila->back;
		fila->back->next = newpointer;
		fila->back = newpointer;
	}

	fila->size ++;
}

int getQ(SetQueue *fila){ return fila->head->value; }

void dequeueQ(SetQueue *fila){
	node *current;

	if(fila->back == fila->head){
		current == fila->head;
		fila->head = NULL;
		fila->back = NULL;
		free(current);
	}
	else{
		current = fila->head;
		fila->head = current->next;
		fila->head->previous = NULL;
		free(current);
	}

	fila->size --;
}

int sizeQ(SetQueue *fila){ return fila->size; }

void printQueue(SetQueue *fila){
	node *current = fila->head;
	cout << endl;
	
	while(current != NULL){
		cout << current->value << endl;
		current = current->next;
	}
}

// ^^ ---------- QUEUE ---------- ^^ \\

int main(){

	int v, a, t;

	return 0;
}