#include <bits/stdc++.h>
using namespace std;

struct nodeTree { int value, h; nodeTree *right, *left; };

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

nodeTree *AddNode(nodeTree *node, int v){

	if(node == NULL) return CreateNode(v);
	else if(node->value > v) node->left = AddNode(node->left, v);
	else node->right = AddNode(node->right, v);

	node->h = h(node);
	nodeTree *child;
	int BF = BalanceFactor(node);
  
	if(BF == 2){
		child = node->left;
		if(BalanceFactor(child) == -1) node->left = LeftRot(child);
		node = RightRot(node);
	}
	else if(BF == -2){
		child = node->right;
		if(BalanceFactor(child) == 1) node->right = RightRot(child);
		node = LeftRot(node);
	}

	return node;
}

void printTree(nodeTree *no){
	if(no != NULL){
		printTree(no->left);
		cout << no->value << " ";
		printTree(no->right);
	}
}

int main(){

	nodeTree *root = NULL;
	int x;
	while(cin >> x) root = AddNode(root, x);
	printTree(root);

	return 0;
}
