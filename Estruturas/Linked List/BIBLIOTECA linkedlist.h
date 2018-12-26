
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int i;
	node *next;
};

node *CreatList(){

	node *new_pointer = (node *) malloc(sizeof(node));
	if(new_pointer == NULL) cout << "No memory" << endl;
	new_pointer->next = NULL;
	return new_pointer;

}

void AddItem(node *list, int x){

	node *new_pointer = (node *) malloc(sizeof(node));
	new_pointer->i = x;
	new_pointer->next = NULL;

	node *pointer = list;

	while(pointer->next != NULL){
		pointer = pointer->next;
	}

	pointer->next = new_pointer;
}

void PrintList(node *list){
	node *pointer = list->next;
	while(1){
		cout << pointer->i << endl;
		if(pointer->next == NULL) return;
		else pointer = pointer->next;
	}
}

node *SearchList(node *list, int x){
	node *pointer = list;

	while(1){
		if(pointer->i == x) return pointer;
		else if(pointer->next == NULL) return NULL;
		else pointer = pointer->next;
	}
}

int RemoveItem(node *list, int x){

	//return 0 nao encontrado
	// return 1 removido

	node *pointer = list;

	while(1){
		if(pointer->next->i == x){
			pointer->next = pointer->next->next;
			return 1;
		}
		else if(pointer->next->next == NULL){
			return 0;
		}
		else{
			pointer = pointer->next;
		}
	}
}