#include <bits/stdc++.h>
using namespace std;

struct node
{
	int value;
	char cr;
	node *next;
};

struct SetStack{
	node *head;
};

void PushItem(SetStack *Stack, char x){

	if(Stack->head != NULL && Stack->head->cr == x){
		Stack->head->value ++;
		return;
	}

	node *newNode = (node *) malloc(sizeof(node));
	newNode->cr = x;
	newNode->value = 1;

	if(Stack->head == NULL){
		Stack->head = newNode;
		newNode->next = NULL;
	}
	else{
		newNode->next = Stack->head;
		Stack->head = newNode;
	}


}

void PrintStack(SetStack *Stack){
	node *current = Stack->head;
	while(current != NULL){
		cout << current->cr << ' ' << current->value << endl;
		current = current->next;
	}
	cout << endl;
}

int main(){
	
	char text[10000];
	gets(text);
	sort(text, text + strlen(text));

	SetStack *Stack = (SetStack *) malloc(sizeof(SetStack));
	Stack->head = NULL;

	for(int i = 0; i < strlen(text); i++){
		PushItem(Stack, text[i]);
	}

	PrintStack(Stack);

	return 0;
}
