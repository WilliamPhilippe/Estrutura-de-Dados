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
	
	if(list->next == NULL){
		cout << list->i;
		return;
	}
	else{
		PrintList(list->next);
		cout << " " << list->i;
	}


}

int main(){

	node *list = CreatList();

	int x;
	while(cin >> x) AddItem(list, x);

	PrintList(list->next);

	return 0;
}