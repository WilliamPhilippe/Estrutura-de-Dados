#include <bits/stdc++.h>
using namespace std;

struct node
{
	int i;
	node *next;
};

node *CreatList(){

	node *new_pointer = (node *) malloc(sizeof(node));
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
		if(pointer->next == NULL) cout << pointer->i;
		else cout << pointer->i << " ";
		if(pointer->next == NULL) return;
		else pointer = pointer->next;
	}
}

void OrdenarLista(node *list){

	node *pointerI;
	node *pointerJ;

	for(pointerI = list->next; pointerI != NULL; pointerI = pointerI->next){
		for(pointerJ = list->next; pointerJ != NULL; pointerJ = pointerJ->next){
			if(pointerJ->i >= pointerI->i){
				int aux = pointerI->i;
				pointerI->i = pointerJ->i;
				pointerJ->i = aux;
			}
		}
	}
}

int main(){

	node *list = CreatList();
	if(list == NULL){
		cout << "NULL";
		return 0;
	}

	int x;
	while(cin >> x) AddItem(list, x);

	OrdenarLista(list);
	PrintList(list);

	return 0;
}