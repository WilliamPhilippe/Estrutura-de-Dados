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

node *SearchList(node *list, int x){
	node *pointer = list;

	while(1){
		if(pointer->i == x) return pointer;
		else if(pointer->next == NULL) return NULL;
		else pointer = pointer->next;
	}
}

int main(){

	node *list = CreatList();
	int t, x;
	cin >> t;

	while(t--){
		cin >> x;
		AddItem(list, x);
	}

	cin >> t;

	while(t--){
		cin >> x;
		node *pointer = SearchList(list, x);
		if(pointer == NULL){
			cout << "0";
			return 0;
		}
	}


	cout << 1;
	return 0;

}