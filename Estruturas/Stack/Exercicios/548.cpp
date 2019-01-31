#include <bits/stdc++.h>
using namespace std;

struct nodeList
{
	int value;
	nodeList *next, *previous;
};

struct nodeStack
{
	nodeList *headList;
	nodeList *backList;
	nodeStack *next;
};

struct setStack
{
	nodeStack *headStack;
};

void pushStack(setStack *stack, nodeStack *nodeNewStack){

	if(stack->headStack == NULL){
		stack->headStack = nodeNewStack;
		nodeNewStack->next = NULL;
	}
	else{
		nodeNewStack->next = stack->headStack;
		stack->headStack = nodeNewStack;
	}

}

void pushList(nodeStack *pilha, int x){

	nodeList *newNode = (nodeList *) malloc(sizeof(nodeList));
	newNode->value = x;

	if(pilha->headList == NULL){
		pilha->headList = newNode;
		pilha->backList = newNode;
		newNode->next = NULL;
		newNode->previous = NULL;
	}	
	else{
		newNode->next = NULL;
		newNode->previous = pilha->backList;
		pilha->backList->next = newNode;
		pilha->backList = newNode;
	}

}

void popStack(setStack *stack){

}

void printStackList(nodeStack *node){
	nodeList *current = node->headList;

	cout << current->value;
	current = current->next;
	while(current != NULL){
		cout << " " << current->value;
		current = current->next;
	}
	cout << endl;
}


int main(){

	char trash, command[1000];
	int x;

	setStack *stack = (setStack *) malloc(sizeof(setStack));
	stack->headStack = NULL;

	while(gets(command)){

		if(strcmp(command, "PUSH") == 0){
			nodeStack *nodeNewStack = (nodeStack *) malloc(sizeof(nodeStack));
			nodeNewStack->headList = NULL;
			nodeNewStack->backList = NULL;

			while(1){
				scanf("%d%c", &x, &trash);
				pushList(nodeNewStack, x);

				if(trash == '\n') break;
			}

			pushStack(stack, nodeNewStack);
		}
		else if(strcmp(command, "POP") == 0){
			
			if(stack->headStack == NULL) cout << "EMPTY STACK" << endl;
			else{
				printStackList(stack->headStack);
				stack->headStack = stack->headStack->next;
			}
		}
	}



	return 0;
}
