#include <bits/stdc++.h>
using namespace std;

struct node
{
	char value;
	node *next, *previous;
};

struct SetQueue
{
	node *head;
	node *back;
	int size;
};

void AddItem(SetQueue *fila, char x){
	if(fila->back != NULL && x == fila->back->value) return;

	node *newNode = (node *) malloc(sizeof(node));
	newNode->value = x;

	if(fila->head == NULL){
		fila->head = newNode;
		newNode->next = NULL;
		newNode->previous = NULL;
		fila->back = newNode;
	}
	else{
		newNode->next = NULL;
		newNode->previous = fila->back;
		fila->back->next = newNode;
		fila->back = newNode;
	}
}

void PrintQueue(SetQueue *fila){
	node *current = fila->head;
	while(current != NULL) cout << current->value, current = current->next;
	cout << endl;
}

int main(){
	
	char s[100];
	gets(s);
	SetQueue *fila = (SetQueue *) malloc(sizeof(SetQueue));
	fila->head = NULL;
	fila->back = NULL;

	for(int i = 0; i < strlen(s); i++) AddItem(fila, s[i]);
	PrintQueue(fila);


	return 0;
}