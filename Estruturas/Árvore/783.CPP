#include <bits/stdc++.h>
using namespace std;

struct nodeTree{ int value; nodeTree *left, *right; };

nodeTree *CreateNode(int x){
	nodeTree *newNode = (nodeTree *) malloc(sizeof(nodeTree));
	newNode->value = x;
	newNode->right = NULL; newNode->left = NULL;

	return newNode;
}

void InsertItem(nodeTree **node, int n){
	
	if(*node == NULL){
		*node = CreateNode(n);
	}	
	else{
		if(n >= (*node)->value) InsertItem( &((*node)->right), n);
		else InsertItem( &((*node)->left), n);
	}

}

void PrintTree(nodeTree *node, int n, int flag){
	if(flag) cout << "----\n" << "Adicionando " << n << endl << "  " ;

	if(node == NULL) { cout << " () "; return; }
	else{
		cout << " ( " << node->value << " "; 
		PrintTree(node->left, n, 0);
		PrintTree(node->right, n, 0);
		cout << ") ";
	}

	if(flag) cout << endl;
}

int main(){

	int n; cin >> n;
	nodeTree *root = CreateNode(n);
	PrintTree(root, n, 1);

	while(cin >> n) InsertItem(&root, n), PrintTree(root, n, 1);
	cout << "----" << endl;
	return 0;
}