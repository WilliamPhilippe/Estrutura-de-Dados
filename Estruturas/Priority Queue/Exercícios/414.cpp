#include <bits/stdc++.h>
using namespace std;

struct node { int nota; node *next, *previous; };
struct setPQ { node *head; };

void InsertItem(setPQ *PQ, int p){
	node *newNode = (node *) malloc(sizeof(node));
	newNode->nota = p;

	if(PQ->head == NULL){
		PQ->head = newNode;
		newNode->next = NULL;
	}
	else{
		node *current = PQ->head;

		while(current->next != NULL && current->nota > newNode->nota){

		}
	}
}

int main(){

	int n, m;
	cin >> n;

	while(n--){
		cin >> m;
		int alunos[m];
		for(int i = 0; i < m; i++) cin >> alunos[i];

		setPQ *PQ = (setPQ *) malloc(sizeof(setPQ));
		PQ->head = NULL;

		for(int i = 0; i < m; i++) InsertItem(PQ, alunos[i]);
	}

	return 0;
}
