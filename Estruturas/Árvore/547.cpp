#include <bits/stdc++.h>
using namespace std;

struct nodeT{ int value; nodeT *right, *left; };
struct nodeS{ nodeT *elemment; nodeS *next; };
struct SetStack{ nodeS *head; };

SetStack *CreateStack(){
	SetStack *stack = (SetStack *) malloc(sizeof(SetStack));
	stack->head = NULL;
	return stack;
}

nodeT *PopStack (SetStack *stack){
	if(stack->head == NULL) return NULL;
	else{
		nodeS *current = stack->head;
		stack->head = current->next;
		return current->elemment;
	}
}

void PushStack (SetStack *stack, nodeT *node){
	nodeS *newNode = (nodeS *) malloc(sizeof(nodeS));
	newNode->elemment = node;

	newNode->next = stack->head;
	stack->head = newNode;
}

nodeT *buildTree(char *s){

	SetStack *stack = CreateStack();
	nodeT *root = NULL, *current = NULL;

	bool value;
	for(int i = 0; s[i] != '\0'; i++){
		if(s[i] == '(') current = PopStack(stack);
		else if(s[i] >= 48 && s[i] <= 57){
			
		}
	} 
}

int main(){
	
	char s[10000]; gets(s);
	nodeT *root = buildTree(s);

	return 0;
}