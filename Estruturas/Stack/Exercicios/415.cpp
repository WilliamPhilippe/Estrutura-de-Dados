#include <bits/stdc++.h>
using namespace std;

struct node
{
	char value;
	node *next;
};

struct setStack
{
	node *head;
};

void push(setStack *stack, char x){
	node *newNode = (node *) malloc(sizeof(node));
	newNode->value = x;

	if(stack->head == NULL){
		stack->head = newNode;
		newNode->next = NULL;
	}
	else{
		newNode->next = stack->head;
		stack->head = newNode;
	}
}

node *pop(setStack *stack){
	if(stack->head == NULL) return NULL;

	node *current = stack->head;
	stack->head = current->next;
	return current;
}

int main(){

	int n, value;
	char frase[500], c;
	scanf("%d\n", &n);

	while(n--){
		gets(frase);
		//cout << frase << endl;
		value = 1;

		setStack *stack = (setStack *) malloc(sizeof(setStack));
		stack->head == NULL;

		for(int i = 0; i < strlen(frase); i++){
			c = frase[i];

			if(c == ' ');
			else if(c == '(' || c == '['){
				push(stack, c);
			}
			else if(c == ']' || c == ')'){
				node *current = pop(stack);

				if(current == NULL){
					cout << "No" << endl;
					value = 0;
					break;
				}
				else if(c == ']' && current->value == '('){
					cout << "No" << endl;
					value = 0;
					break;
				}
				else if(c == ')' && current->value == '['){
					cout << "No" << endl;
					value = 0;
					break;
				}
			}
		}

		if(value && stack->head == NULL) cout << "Yes" << endl;
		else if(value) cout << "No" << endl;
	}


	return 0;
}
