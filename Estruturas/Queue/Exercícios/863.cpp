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

void push_elemment(SetStack *stack, int x){

	node *newPointer = (node *) malloc(sizeof(node));
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

}

void remove_elemment(SetStack *stack){

	
	if(stack->head == NULL) return;
	else{
		node *current = stack->head;
		stack->head = current->next;
		free(current);
	}
	stack->size --;
}

int main(){

	char command[100], running[100];
	SetStack *back = (SetStack *) malloc(sizeof(SetStack));
	SetStack *forward = (SetStack *) malloc(sizeof(SetStack));

	strcpy(running, "null");

	
	while(gets(command)){
		

		if(strcmp(command, "ENTER") == 0){
			if(strcmp(running, command) == 0){
				push_elemment(back, 1);
				strcpy(running, command);
			}
			else strcpy(running, command);
		}
		else if(strcmp(command, "BACK") == 0){
			if(back->size > 0){
				remove_elemment(back);
				push_elemment(forward, 1);
			}
			else if(!strcmp(running, "ENTER")){
				push_elemment(forward, 1);
				strcpy(running, "null");
			}
			else push_elemment(forward, 1);
		}
		else if(strcmp(command, "FORWARD") == 0){
			if(forward->size > 0){
				remove_elemment(forward);
				push_elemment(back, 1);
			}
			else if ( !strcmp(running, "ENTER") ){
				push_elemment(back, 1);
				strcpy(running, "null");
			}
			else{
				push_elemment(back, 1);
			}
		}

	}
	cout << "BACK: " << back->size << endl;
	cout << "FORWARD: " << forward->size << endl;

}
