#include <bits/stdc++.h>
using namespace std;

struct node { int value, key; node *next, *previous; };
struct setHash{ node *itens[102]; int m; };

setHash *setarHash(int m){
	setHash *newHash = (setHash *) malloc(sizeof(setHash));
	newHash->m = m;

	for(int i = 0; i < 102; i++) newHash->itens[i] = NULL;

	return newHash;
}

void insertItem(setHash *hash, int key){

	int newKey = key % hash->m;
	node *newNode = (node *) malloc(sizeof(node));
	newNode->value = key; newNode->key = newKey;

	if(hash->itens[newKey] == NULL){
		hash->itens[newKey] = newNode;
		newNode->next = NULL;
	}
	else{
		node *current = hash->itens[newKey];

		while(current->next != NULL) current = current->next;
		current->next = newNode;
		newNode->next = NULL;
	}

}

void printarHash(setHash *hash){

	for(int i = 0; i < hash->m; i++){
		if(hash->itens[i] == NULL) cout << i << " -> \\" << endl;
		else{
			node *current = hash->itens[i];
			cout << i << " -> " << current->value << " -> ";

			current = current->next;
			while(current != NULL){
				cout << current->value << " -> ";
				current = current->next;
			}

			cout << '\\' << endl; 
		}
	}

}



int main(){
	
	int t, m, c, key;
	cin >> t;

	while(t--){
		cin >> m >> c;
		setHash *hash = setarHash(m);

		for(int i = 0; i < c; i++){ cin >> key; insertItem(hash, key); }
		printarHash(hash);
		cout << endl;
	}

	return 0;
}
