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

int main(){

	node *list = CreatList();


	return 0;
}