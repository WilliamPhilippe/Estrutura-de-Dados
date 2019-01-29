#include <bits/stdc++.h>
using namespace std;

struct node
{
	int value;
	node *next;
};

struct SetStack{
	node *head;
};

void PushItem(SetStack *Stack, int x){

	if(Stack->head != NULL && Stack->head->value == x) return;

	node *newNode = (node *) malloc(sizeof(node));
	newNode->value = x;
	
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
		cout << current->value << endl;
		current = current->next;
	}
	cout << endl;
}


int main(){

	int array1[20], array2[20];

	SetStack * Stack = (SetStack *) malloc(sizeof(SetStack));
	Stack->head == NULL;

	for(int i = 0; i < 20; i++)	cin >> array1[i];
	for(int i = 0; i < 20; i++) cin >> array2[i];

	sort(array1, array1 + 20); sort(array2, array2 + 20);

	for(int i = 19; i >= 0; i--){
		for(int j = 19; j >= 0; j--){
			if(array1[i] == array2[j]) PushItem(Stack, array1[i]);
		}
	}

	if(Stack->head == NULL) cout << "VAZIO" << endl;
	else PrintStack(Stack);

	return 0;
}
