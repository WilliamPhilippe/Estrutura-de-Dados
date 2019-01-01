#include <bits/stdc++.h>
using namespace std;

struct node
{
	int value;
	node *next;
};

struct SetStack
{
	node *head;
	int size;
};

int push_elemment(SetStack *stack, int x){

	node *newPointer = (node *) malloc(sizeof(node));
	if(newPointer == NULL) return 0;
	newPointer->value = x;
	stack->size ++;

	if(stack->head == NULL){
		stack->head = newPointer;
		newPointer->next = NULL;
	}
	else{
		newPointer->next = stack->head;
		stack->head = newPointer;
	}

	return 1;
}

int remove_elemment(SetStack *stack){

	if(stack->head == NULL) return 0;
	else{
		node *current = stack->head;
		stack->head = current->next;
		free(current);
	}
	stack->size --;
	return 1;
}

void printstack(SetStack *stack){
	node *current = stack->head;
	while(current != NULL){
		cout << current->value << endl;
		current = current->next;
	}
	cout << endl;
}

int peek_elemment(SetStack *stack, int &x){
	if(stack->head == NULL) return 0;
	node *current = stack->head;
	x = current->value;
	return 1;
}

int isempty(SetStack *stack){
	if(stack->head == NULL) return 1;
	else return 0;
}

int menu(SetStack *stack){

	int x, command;

	cout << "1 - Push Elemment.\n2 - Pop Elemment.\n3 - Peek Elemment.\n4 - Is Empty?\n5 - Print Stack.\n6 - Size.\n0 - Exit.\n";
	cout << "Insert command: "; cin >> command;

	if(command == 0) return 0;
	else if(command == 1){
		cout << "Insert elemment: "; cin >> x;
		if( push_elemment(stack, x) ) cout << "Success.\n\n";
		else cout << "No memory.\n\n";
	}
	else if(command == 2){
		if( remove_elemment(stack) ) cout << "Success.\n\n";
		else cout << "Empty stack.\n\n";
	}
	else if(command == 3){
		int c;
		if(!peek_elemment(stack, c)) cout << "Empty stack.\n\n";
		else cout << "Elemment: " << c << endl << endl;
	}
	else if(command == 5) printstack(stack);
	else if(command == 4){
		isempty(stack) ? cout << "Empty.\n\n" : cout << "It isn't empty.\n\n";
	}
	else if(command == 6) cout << stack->size << endl << endl;
	else cout << "Invalid Command.\n\n";

	return 1;
}

int main(){

	SetStack *stack = (SetStack *) malloc(sizeof(SetStack));
	stack->head = NULL;
	stack->size = 0;

	while(menu(stack));

	return 0;
}