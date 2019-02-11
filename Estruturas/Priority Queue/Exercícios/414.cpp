#include <bits/stdc++.h>
using namespace std;

struct node { int nota; node *next, *previous; };
struct setPQ { node *head, *back; int max, min; };

void InsertItem(setPQ *PQ, int p){
	node *newNode = (node *) malloc(sizeof(node));
	newNode->nota = p;

	if(PQ->head == NULL){
		newNode->next = NULL;
		newNode->previous = NULL;
		PQ->head = newNode;
		PQ->back = newNode;
		PQ->max = PQ->min = p;
	}
	else if(newNode->nota >= PQ->max){
		newNode->next = PQ->head;
		newNode->previous = NULL;
		newNode->next->previous = newNode;
		PQ->head = newNode;
		PQ->max = p;
	}
	else if(newNode->nota <= PQ->min){
		newNode->next = NULL;
		newNode->previous = PQ->back;
		newNode->previous->next = newNode;
		PQ->back = newNode;
		PQ->min = p;
	}
	else{
		node *current = PQ->head;
		while(current->nota > p) current = current->next;

		newNode->next = current;
		newNode->previous = current->previous;
		current->previous = newNode;
		newNode->previous->next = newNode;
	}
}

int verificar(int *alunos, int m, setPQ *PQ){
	int contador = 0;
	node *current = PQ->head;
	for(int i = 0; i < m; i++, current = current->next)
		if(current->nota == alunos[i]) contador++;
	return contador;
}

void printqueue(setPQ *PQ){
	node *current = PQ->head;

	while(current != NULL) cout << current->nota << " ", current = current->next;
	cout << endl;
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
		int cc = verificar(alunos, m, PQ);
		cout << cc << endl;
	}

	return 0;
}
