#include <bits/stdc++.h>
using namespace std;

struct nodeTree { int value, h; nodeTree *right, *left; };
void PrintTreeContinue(nodeTree *node, int n, int flag, int AD);

nodeTree *CreateNode(int v){
	nodeTree *newNode = (nodeTree *) malloc(sizeof(nodeTree));
	newNode->value = v;
	newNode->left = newNode->right = NULL;
	newNode->h = 0;
	return newNode;
}

int h(nodeTree *node){
	if(node == NULL) return -1;
	else return 1 + max(h(node->left), h(node->right));
}

int IsBalanced(nodeTree *node){
	int bf = h(node->left) - h(node->right);
	return ( (-1 <= bf) && (bf <= 1) );
}

int BalanceFactor(nodeTree *node){
	if(node == NULL) return 0;
	else if((node->left != NULL) && (node->right != NULL))
		return node->left->h - node->right->h; 
	else if((node->left != NULL) && (node->right == NULL))
		return 1 + node->left->h;
	else return (-node->right->h - 1);
}		

nodeTree *LeftRot(nodeTree *node){
	nodeTree *subtree = NULL;

	if(node != NULL && node->right != NULL){
		subtree = node->right;
		node->right = subtree->left;
		subtree->left = node;
	}

	subtree->h = h(subtree);
	node->h = h(node);
	return subtree;
}

nodeTree *RightRot(nodeTree *node){
	nodeTree *subtree = NULL;

	if(node != NULL && node->left != NULL){
		subtree = node->left;
		node->left = subtree->right;
		subtree->right = node;
	}

	subtree->h = h(subtree);
	node->h = h(node);

	return subtree;
}

nodeTree *AddNode(nodeTree *root, nodeTree *node, int v, int *printBalanced, int isHome){

	if(node == NULL) return CreateNode(v);
	else if(node->value > v) node->left = AddNode(root, node->left, v, printBalanced, 0);
	else node->right = AddNode(root, node->right, v, printBalanced, 0);

	node->h = h(node);
	nodeTree *child;
	int BF = BalanceFactor(node);
  
	if(BF == 2){
		if(!(*printBalanced)){
			PrintTreeContinue(root, v, 2, 1);
			*printBalanced = 1;
		}

		child = node->left;
		if(BalanceFactor(child) == -1) node->left = LeftRot(child);
		node = RightRot(node);
	}
	else if(BF == -2){
		if(!(*printBalanced)){
			PrintTreeContinue(root, v, 2, 1);
			*printBalanced = 1;
		}

		child = node->right;
		if(BalanceFactor(child) == 1) node->right = RightRot(child);
		node = LeftRot(node);
	}

	if(isHome && *printBalanced);// PrintTreeContinue(root, v, 3, 1);
	else if(isHome && !(*printBalanced)) PrintTreeContinue(root, v, 1, 1);



	return node;
}

void PrintTreeContinue(nodeTree *node, int n, int option, int FlagOri){
	if(FlagOri && option == 1){
		//CONTINUOU AVL 
		cout << "----\n" << "Adicionando " << n << endl << "Continuou AVL...\n" << "  " ;
	}
	else if(FlagOri && option == 2){
		// ANTES DE BALANCEAR
		cout << "----\n" << "Adicionando " << n << endl << "Antes de ajustar balanceamento...\n" << "  " ;
	}
	else if(FlagOri && option == 3){
		//BALANCEADO
		cout << "Depois de ajustar balanceamento...\n" << "  ";
	}


	if(node == NULL) { cout << " () "; return; }
	else{
		cout << " ( " << node->value << " "; 
		PrintTreeContinue(node->left, n, 0, 0);
		PrintTreeContinue(node->right, n, 0, 0);
		cout << ") ";
	}

	if(FlagOri) cout << endl;
}

int main(){

	nodeTree *root = NULL;
	int x, flag = 0, u = 1;
	while(cin >> x) {
		root = AddNode(root, root, x, &flag, 1);
		if(u) PrintTreeContinue(root, x, 1, 1);
		else if(!u && flag) PrintTreeContinue(root, x, 3, 1);
		u = 0;
		flag = 0;
	}
	cout << "----";

	return 0;
}
