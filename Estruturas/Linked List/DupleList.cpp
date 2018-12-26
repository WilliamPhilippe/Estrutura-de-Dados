#include <bits/stdc++.h>
using namespace std;

struct node
{
	int value;
	node *previous;
	node *next;
}

void CreatList(node *head, node *back){
	head = (node *) malloc(sizeof(node));
	back = (node *) malloc(sizeof(node));

	head->previous = NULL;
	head->next = back;
	back->previous = head;
	back->next = NULL;
}

int main(){

	node *head; node *back;
	CreatList(head, back);

	while(1){
		int comando, x;
		cout << "1- PrintList\n2- AddItem\n3- SearchList\n4- RemoveItem\n0- Exit\n";
		cout << "Comando: "; cin >> comando;

		if(comando == 0) return 0;
		else if(comando == 1){
				

		}
		else if(comando == 2){
			

		}
		else if(comando == 3){


		}
		else if(comando == 4){
			

		}
		else cout << "Comando Invalido\n\n";
	}


	return 0;
}